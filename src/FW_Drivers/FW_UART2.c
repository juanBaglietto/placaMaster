/*
 * FW_UART2.c
 *
 *  Created on: 24/10/2013
 *      Author: Nicolas
 */


#include "Aplicacion.h"

extern uint8_t buffer[TOPE];
extern uint8_t inx_out;
extern uint8_t inx_in;
extern uint8_t enviando;

#define IDLE 		0
#define	ID			1
#define	CANT		2
#define ARRAY		3
#define TIPO		4
#define	VEL			5
#define LENG 		6
#define TEXTO 		7
#define FINPAQUETE 	8
#define FINTX		9


extern Elemento Mensajes[25];
extern uint8_t Leng;
extern uint8_t Inicio;
extern uint8_t flash;

extern uint8_t buffer[TOPE];
extern uint8_t inx_out;
extern uint8_t inx_in;
extern uint8_t enviando;

extern uint8_t velocidadActual;
extern uint8_t iniciar485;

uint8_t txStart;

void procesaDato(uint8_t* datoLlegado){
	static uint8_t estadoMsg = IDLE, leng,i=0;
	uint8_t j;

	static uint8_t cantElementos=0;
	static uint8_t indice_mensaje=0;
	static Elemento Recibidos[25]; //para recibir
	static Elemento aux;


	switch (estadoMsg){

	case IDLE:
		if(*datoLlegado == INICIO_TX){
			estadoMsg = ID;
			flash=OFF;
		}
		else{
			estadoMsg=IDLE;
		}
		break;

	case ID:
		if(*datoLlegado == PROTOCOL_ID+'0'){
			estadoMsg = CANT;
		}
		else{
			estadoMsg=IDLE;
		}
		break;

	case CANT:
		if(*datoLlegado){
			estadoMsg = ARRAY;
			cantElementos=*datoLlegado;
			*datoLlegado=ACK; //ack de empezar tx
		}
		else{
			estadoMsg=IDLE;
		}
		break;

	case ARRAY:
		if(*datoLlegado == '1' || *datoLlegado == '0'){
			aux.arrayID[i]=*datoLlegado-'0'; //convertido a int
			i++;
			if(i==4){
				estadoMsg=TIPO;
				i=0;
			}
		}
		else{
			estadoMsg=IDLE;
		}
		break;

	case TIPO:
		if(*datoLlegado=='0'){
			estadoMsg = VEL;
			aux.Tipo_Elem=ELEMENTO_TEXTO;
		}
		if(*datoLlegado=='1'){
			estadoMsg = VEL;
			aux.Tipo_Elem=ELEMENTO_TEMPERATURA;
		}
		if(*datoLlegado=='2'){
			estadoMsg = VEL;
			aux.Tipo_Elem=ELEMENTO_HUMEDAD;
			flash=ON;

			//VaciarBuffer();
		}
		if(*datoLlegado!= '0' && *datoLlegado!= '1' && *datoLlegado!= '2'){
			estadoMsg=IDLE;
		}
		break;

	case VEL:
		if(*datoLlegado){
			aux.vel=*datoLlegado;
			if(aux.Tipo_Elem== ELEMENTO_TEXTO){
				estadoMsg=LENG;
			}
			if(aux.Tipo_Elem== ELEMENTO_TEMPERATURA || aux.Tipo_Elem== ELEMENTO_HUMEDAD){
				estadoMsg=FINPAQUETE;
			}
		}
		else{
			estadoMsg=IDLE;
		}
		break;

	case LENG:
		if(*datoLlegado){
			leng=*datoLlegado;
			estadoMsg = TEXTO;
		}else{
			estadoMsg = IDLE;
		}
		break;

	case TEXTO:
		aux.str[i]=*datoLlegado;
		i++;
		if(i==leng){
			aux.str[i]='\0';
			estadoMsg=FINPAQUETE;
		}
		break;

	case FINPAQUETE:
		if(*datoLlegado == FIN_PAQUETE){ //$ es caracter de fin de paquete
			strcpy(Recibidos[indice_mensaje].str,aux.str);
			Recibidos[indice_mensaje].vel=aux.vel;
			for(i=0;i<4;i++){
				Recibidos[indice_mensaje].arrayID[i]=aux.arrayID[i];
			}
			Recibidos[indice_mensaje].Tipo_Elem=aux.Tipo_Elem;

			indice_mensaje++;
			if(indice_mensaje == cantElementos){
				estadoMsg=FINTX;
			}else{
				estadoMsg=ARRAY;
			}

			for(i=0;i<100;i++){
				aux.str[i]='\0';
			}
			i=0; //reinicio todos los valores para proxima recepcion
			Inicio=0; //para empezar a mostrar desde el ppio
			*datoLlegado=ACK;
		}
		else{
			estadoMsg = IDLE;
			for(i=0;i<100;i++){
				aux.str[i]='\0';
			}
			i=0; //reinicio todos los valores para proxima recepcion
		}
		break;

	case FINTX:
		if(*datoLlegado==FIN_TX){
			indice_mensaje=0;
			estadoMsg=IDLE;
			Leng=cantElementos;
			for(j=0;j<Leng;j++){
				Mensajes[j].Tipo_Elem=Recibidos[j].Tipo_Elem;
				Mensajes[j].vel=Recibidos[j].vel;
				strcpy(Mensajes[j].str,Recibidos[j].str);
				for(i=0;i<4;i++){
					Mensajes[j].arrayID[i]=Recibidos[j].arrayID[i];
				}
			}
			i=0;
			*datoLlegado=FIN_TX; //fin de tx
		}
		break;

	}
}


void UART2_IRQHandler (void){
	uint8_t iir, aux;

	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U2IIR;

		if ( iir & 0x04 ) //Data ready
		{
			PushRx((uint8_t )U2RBR );
			PopRx(&aux);
			procesaDato(&aux);
			if(aux==ACK){
				iir |= 0x02; //ack de que termino el paquete
			}
			if(aux==FIN_TX){
				iir |= 0x02; //ack de que termino tx
			}

		}

		if ( iir & 0x02 ) //THRE
		{

				enviando = 1;	 		//aviso que estoy enviando

				if(aux==ACK){
					U2THR=ACK; //ack de que termino el paquete

				}
				if(aux==FIN_TX){
					U2THR=FIN_TX; //ack de que termino tx
					//termino tx contra pc, hay q transmitir a esclavas
					iniciar485=1;
					TmrStartM(EVENTOM6,TM6*2);
				}

				enviando = 0;

		}
	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */

}


