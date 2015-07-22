/*
 * FW_Pantalla.c
 *
 *  Created on: 24/10/2013
 *      Author: Nicolas
 */
#include "Aplicacion.h"

extern uint8_t SystemFont5x7[];
extern uint8_t firstchar;
extern uint8_t width;
extern uint8_t offset;
extern uint8_t bufferPantalla[MAXBUFFER]; //defino 100 caracteres maximo
extern uint8_t strEjemplo[];
extern uint16_t indexInicio;
extern uint16_t indexFin;
extern uint16_t indexRestart;
extern uint8_t cambioDeIndice;

extern uint8_t Humestring[7];
extern uint8_t Tempstring[9];
extern uint8_t flagLeerMensajeNuevo;
extern uint8_t velocidadActual;

extern Elemento Mensajes[25];
extern uint8_t Leng;
extern uint8_t Inicio;


void LedMultiplexation(void){
	static uint8_t i=0,cont=0;
	i++;
	if(i==1){
		ClockON();
		SendDataToMatrix(cont);
		cont++;

	}
	else{
		if(i==4){
		ClockOFF();
		SendZeroToMatrix();

		}
		else{
			if(i==5){
				i=0;
				if(cont==MATRIXWIDTH){ 	//termino de recorrer toda la matriz
					ResetON();	//pulso de reset
					ResetOFF();
					ClockOFF();
					cont=0;
					IncrementarIndices();
				}
			}
		}
	}


}

void FillBuffer(uint8_t str[]){
	uint16_t i,j,c,index;
	VaciarBuffer();

	for(j=0;j<MATRIXWIDTH;j++){
		bufferPantalla[j]=0; //vacio el principio del buffer
	}
	index=j;
	for(j=0;str[j]!='\0';j++){
		c=str[j];
		for(i=0;i<width;i++){
			bufferPantalla[index]=SystemFont5x7[((c-firstchar)*5)+offset+i];
			index++;
		}
		index++; //para dejar una columna apagada entre 2 caracteres
	}

	indexRestart=strlen(str)*6+MATRIXWIDTH*2; //multiplico cada caracter x 6 xq es el largo y le agrego los 32 al final
}

void ResetON(void){
	SetPIN(RESET,0); //esto es negado x las uln
}
void ResetOFF(void){
	SetPIN(RESET,1);
}
void ClockON(void){
	SetPIN(CLOCK,0);
}
void ClockOFF(void){
	SetPIN(CLOCK,1);
}

void SendDataToMatrix(uint8_t index){


	uint8_t byte=bufferPantalla[index+indexInicio];

	if((byte & 0x01)==0x01){
		SetPIN(FILA1,ON);
	}
	else{
		SetPIN(FILA1,OFF);
	}

	if((byte & 0x02)==0x02){
		SetPIN(FILA2,ON);
	}
	else{
		SetPIN(FILA2,OFF);
	}

	if((byte & 0x04)==0x04){
		SetPIN(FILA3,ON);
	}
	else{
		SetPIN(FILA3,OFF);
	}

	if((byte & 0x08)==0x08){
		SetPIN(FILA4,ON);
	}
	else{
		SetPIN(FILA4,OFF);
	}

	if((byte & 0x10)==0x10){
		SetPIN(FILA5,ON);
	}
	else{
		SetPIN(FILA5,OFF);
	}

	if((byte & 0x20)==0x20){
		SetPIN(FILA6,ON);
	}
	else{
		SetPIN(FILA6,OFF);
	}

	if((byte & 0x40)==0x40){
		SetPIN(FILA7,ON);
	}
	else{
		SetPIN(FILA7,OFF);
	}

	if((byte & 0x80)==0x80){
		SetPIN(FILA8,ON);
	}
	else{
		SetPIN(FILA8,OFF);
	}


}

void SendZeroToMatrix(void){
	SetPIN(FILA1,OFF);
	SetPIN(FILA2,OFF);
	SetPIN(FILA3,OFF);
	SetPIN(FILA4,OFF);
	SetPIN(FILA5,OFF);
	SetPIN(FILA6,OFF);
	SetPIN(FILA7,OFF);
	SetPIN(FILA8,OFF);
}
void prendermatriz(void){
	SetPIN(FILA1,ON);
	SetPIN(FILA2,ON);
	SetPIN(FILA3,ON);
	SetPIN(FILA4,ON);
	SetPIN(FILA5,ON);
	SetPIN(FILA6,ON);
	SetPIN(FILA7,ON);
	SetPIN(FILA8,ON);
}
void apagarmatriz(void){
	SetPIN(FILA1,OFF);
	SetPIN(FILA2,OFF);
	SetPIN(FILA3,OFF);
	SetPIN(FILA4,OFF);
	SetPIN(FILA5,OFF);
	SetPIN(FILA6,OFF);
	SetPIN(FILA7,OFF);
	SetPIN(FILA8,OFF);
}

void VaciarBuffer(void){
	uint16_t i;
	for(i=0;i<MAXBUFFER;i++){
		bufferPantalla[i]=0;
	}
}

void IncrementarIndices(void){

	if(cambioDeIndice){
		cambioDeIndice=0;
		indexInicio++;
		indexFin++;
		if(indexFin==indexRestart){
			indexInicio=0;
			indexFin=MATRIXWIDTH;
			flagLeerMensajeNuevo=1;

		}
	}
}

void get_message (void) {


	while(!(Mensajes[Inicio].arrayID[PROTOCOL_ID])){
		Inicio++;
		Inicio%=Leng;
	}
	if(Mensajes[Inicio].Tipo_Elem==ELEMENTO_TEXTO){ //texto
		FillBuffer(Mensajes[Inicio].str);
	}
	if(Mensajes[Inicio].Tipo_Elem==ELEMENTO_TEMPERATURA){	//temp
		FillBuffer(Tempstring);
	}
	if(Mensajes[Inicio].Tipo_Elem==ELEMENTO_HUMEDAD){ //humedad
		FillBuffer(Humestring);
	}
	velocidadActual=Mensajes[Inicio].vel;
	Inicio++;
	Inicio%=Leng;

}
