/*
 * FW_isr.c
 *
 *  Created on: 13/08/2013
 *      Author: Gos
 */

#include "Aplicacion.h"

extern uint8_t indexInicio;
extern uint8_t indexFin;
extern uint8_t indexRestart;
extern uint8_t cambioDeIndice;
extern uint8_t velocidadActual;
extern uint8_t flag_flash;
//-----------------------------------------------------------------------------
// Rutina de servicio de interrupción del Timer 0
//-----------------------------------------------------------------------------
void TIMER0_IRQHandler (void)
{

	if((T0IR & 0x00000001))
	{
		// Si interrumpio match 0
		T0IR |= 0x00000001; 									// Borro flag del Match 0
		LedMultiplexation();
	}


}
void TIMER1_IRQHandler (void)
{
	static uint8_t aux=10;
	static uint32_t cont_flash1=50;
	static uint32_t cont_flash2=50;
	if((T1IR & 0x00000001))
	{
		// Si interrumpio match 0
		T1IR |= 0x00000001;// Borro flag del Match 0

		if(flag_flash==OFF){
			if(cont_flash1==0){
				cont_flash1=velocidadActual;
				flag_flash=ON;
			}
			else{
				cont_flash1--;
			}
		}
		else if(flag_flash==ON){
			if(cont_flash2==0){
					cont_flash2=velocidadActual;
					flag_flash=OFF;
				}
					else{
					cont_flash2--;
				}
		}

		if((aux-velocidadActual)==0){
			cambioDeIndice=1;	//aviso que hay q cambiar el indice, se lee al final del multiplexado
			aux=10;

		}
		else{
			aux--;

		}
	}

}

void TIMER2_IRQHandler (void) //Cada 10  microsegundos...
{
	if((T2IR & 0x00000001)){
		T2IR |= 0x00000001;	// Borro flag del Match 0
		AnalizarTimerM();  //Bajo cada contador en esta funcion

	}
}

