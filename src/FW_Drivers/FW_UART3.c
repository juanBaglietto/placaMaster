/*
 * FW_UART3.c
 *
 *  Created on: 02/11/2013
 *      Author: Nicolas
 */
#include "Aplicacion.h"

extern uint8_t bufferuart3[TOPE];
extern uint8_t inx_out3;
extern uint8_t inx_in3;
extern uint8_t enviando;
extern uint8_t enviando485;
uint8_t txStart3;
extern uint8_t findeenvio;
extern uint8_t id485;
extern uint8_t iniciar485;
extern uint8_t Leng;
extern uint8_t esperandoACK;
extern uint8_t actualizandodatos;
extern  uint8_t enviarfindetx;

void UART3_IRQHandler (void)
{
	uint8_t iir, dato, aux;
	static uint8_t cantACK=0;

	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U3IIR;

		if ( iir & 0x02 ) //THRE
		{
			if( !PopTx3(&dato) )	//para transmitir hasta no tener mas datos
				U3THR = dato;
			else
				txStart3 = 0;

		}
		if ( iir & 0x04 ) //Data ready
		{
			aux=U3RBR;

			if((aux==ACK) && esperandoACK){
				cantACK++;
				if(cantACK==Leng+1){ //recibio todos los ack
					findeenvio=1;
				}
				else{
					enviando485=1;
				}
				TmrStopM(EVENTOM7); //paro timer de timeout de protocolo
				TmrStartM(EVENTOM6,TM6*2); //espero para enviar prox paquete para q esclava se ponga como rx


			}
			if(aux==FIN_TX){
				id485++;
				iniciar485=1; //comienza nueva tx
				cantACK=0;
				TmrStopM(EVENTOM7); //paro timer timeout
				TmrStopM(EVENTOM6);
				TmrStartM(EVENTOM6,TM6*2);

				if(id485==CANTESCLAVAS+1){ //si despues de incrementar se paso de las esclavas es porque se termino de transmitir a todas
					id485=1;
					iniciar485=0;
					actualizandodatos=1; //ya lo dejo actualizar datos cdo termino de enviar al resto
					CambiarEstadoTE(TRANSMISION);
					TmrStopM(EVENTOM6); //paro timer 485 para evitar problemas
				}
			}



		}

	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}





















