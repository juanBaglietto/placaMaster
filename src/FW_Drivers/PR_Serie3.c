/*
 * PR_Serie3.c
 *
 *  Created on: 09/11/2013
 *      Author: Nicolas
 */

#include "Aplicacion.h"
extern uint8_t actualizandodatos;
extern uint8_t txStart3;
extern uint8_t cantbytes;
extern uint8_t Humestring[7];
extern uint8_t Tempstring[8];
extern uint8_t esperandoACK;
extern uint8_t Leng;
extern uint8_t id485;
extern uint8_t indice;
extern Elemento Mensajes[25];
// Buffer de Transmision
uint8_t bufferTx3[TXBUFFER_SIZE];
// Buffer de Recepcion
uint8_t bufferRx3[RXBUFFER_SIZE];

// Indices de Transmision
uint8_t tx_in3,tx_out3;
// Indices de Recepcion
uint8_t rx_in3,rx_out3;
// Flags de estado de los buffers
uint8_t tx_buffer_empty3;
uint8_t tx_buffer_full3 = 0;
uint8_t rx_buffer_full3 = 0, rx_buffer_empty3 = 1;

uint8_t PushTx3(uint8_t dato)
{
	if(tx_buffer_full3)
		return 1;	//buffer lleno

	bufferTx3[tx_in3] = dato;
	tx_in3++;
	tx_in3 %= TXBUFFER_SIZE;
	tx_buffer_empty3 = 0;	//si agrego un dato el buffer ya no esta vacio

	if(tx_in3 == tx_out3)
		tx_buffer_full3 = 1;	//se lleno el buffer

	if (txStart3 == 0)
	{
		txStart3 = 1;
		START_TX485();
	}
	return 0;	//dato agregado al buffer
}

uint8_t PopTx3( uint8_t *dato )
{
	if(tx_buffer_empty3)
		return 1;	//buffer vacio

	*dato = (uint8_t) bufferTx3[tx_out3];
	tx_out3++;
	tx_out3 %= TXBUFFER_SIZE;
	tx_buffer_full3 = 0;	//si saco un dato el buffer ya no esta lleno

	if(tx_out3 == tx_in3){
		tx_buffer_empty3 = 1;	//se vacio el buffer
		if(!actualizandodatos){ //solo si no es actualizacion de datos porque sino me pone como receptor
			TmrStartM(EVENTOM6,TM6*cantbytes); //arranco timer //multiplica  por cant de bytes enviados
		}
	}
	return 0;	//dato sacado del buffer
}

uint8_t PushRx3( uint8_t dato )
{
	if(rx_buffer_full3)
		return 1;	//buffer lleno

	bufferTx3[rx_in3] = dato;
	rx_in3 ++;
	rx_in3 %= RXBUFFER_SIZE;
	rx_buffer_empty3 = 0;	//si agrego un dato el buffer ya no esta vacio

	if(rx_in3 == rx_out3)
		rx_buffer_full3 = 1;	//se lleno el buffer

	return 0;	//dato agregado al buffer
}

uint8_t PopRx3( uint8_t *dato )
{
	if(rx_buffer_empty3)
		return 1;	//buffer vacio

	*dato = (uint8_t) bufferTx3[rx_out3];
	rx_out3++;
	rx_out3 %= RXBUFFER_SIZE;
	rx_buffer_full3 = 0;	//si saco un dato el buffer ya no esta lleno

	if(rx_out3 == rx_in3)
		rx_buffer_empty3 = 1;	//se vacio el buffer

	return 0;	//dato sacado del buffer
}

void EnviarString3 (uint8_t *str)
{
	uint32_t i;
	for( i = 0 ; i<cantbytes ; i++ )	//cantbytes limita cuantos se van a mandar
		PushTx3( str[i] );
}

void CambiarEstadoTE(uint8_t estado){
	SetPIN(TE_485,estado);
	SetPIN(LEDXpresso,estado);	//el led acompaña al TE para poder ver su estado
}

void ActualizarDatos(void){
	uint8_t strLecturas[200],j,k;


	CambiarEstadoTE(TRANSMISION); //por las dudas
	strLecturas[0]=INICIO_TX;	//strLecturas es para diferenciarse de strEnvio, uno es para temp y humedad y el otro para la informacion
	strLecturas[1]=BROADCAST_ID+'0';
	strLecturas[2]=strlen(Humestring);
	j=3;
	for(k=0;Humestring[k];k++){
		strLecturas[j]=Humestring[k];
		j++;
	}
	strLecturas[j]=strlen(Tempstring);
	j++;
	for(k=0;Tempstring[k];k++){
		strLecturas[j]=Tempstring[k];
		j++;
	}
	strLecturas[j]=FIN_TX;
	cantbytes=18;	//el mensaje es de largo fijo, siempre se manda lo mismo
	EnviarString3(strLecturas); //arranco tx en 485
}

void EnviarInicioTx(void){
	uint8_t strEnvio[3];

	CambiarEstadoTE(TRANSMISION);
	actualizandodatos=0; //para apagar el bloque de actualizar datos
	strEnvio[0]=INICIO_TX;
	strEnvio[1]=id485+'0';
	strEnvio[2]=Leng+'0';
	cantbytes=3;
	EnviarString3(strEnvio); //arranco tx en 485
	esperandoACK=1;
	TmrStartM(EVENTOM7,TM7); //activo Timeout de protocolo
}

void EnviarPaquete(void){
	uint8_t strEnvio[200],j,k;

	CambiarEstadoTE(TRANSMISION);
	actualizandodatos=0;
	for(j=0;j<4;j++){
		strEnvio[j]=(Mensajes[indice].arrayID[j])+'0';
	}
	strEnvio[j]=(Mensajes[indice].Tipo_Elem)+'0';
	j++;
	strEnvio[j]=Mensajes[indice].vel;
	j++;
	//si no es texto ya termino el paquete y no manda string
	if(Mensajes[indice].Tipo_Elem==ELEMENTO_TEXTO){
		strEnvio[j]=strlen(Mensajes[indice].str);
		j++;
		for(k=0;Mensajes[indice].str[k];k++){
			strEnvio[j]=Mensajes[indice].str[k];
			j++;
		}
	}


	strEnvio[j]=FIN_PAQUETE;//fin de paquete
	if(Mensajes[indice].Tipo_Elem== ELEMENTO_TEXTO){
		cantbytes=8+strlen(Mensajes[indice].str);
	}
	else{ //temp y hume tienen largo fijo porque no mandan string
		cantbytes=7;
	}
	EnviarString3(strEnvio); //envio el paquete
	esperandoACK=1; //tengo q esperar ack
	indice++;//para ir al prox paquete despues
	TmrStartM(EVENTOM7,TM7); //activo Timeout de protocolo
}

void EnviarFinTX(void){
	uint8_t strEnvio[2]; //es vector porque enviar string recibe string

	CambiarEstadoTE(TRANSMISION);
	indice=0; //para proxima tx empezar desde el 1er paquete
	strEnvio[0]=FIN_TX;
	cantbytes=1;
	EnviarString3(strEnvio); //arranco tx en 485
	TmrStartM(EVENTOM7,TM7); //activo Timeout de protocolo
}

