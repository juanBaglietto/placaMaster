/*
 * FW_InitUART2.c
 *
 *  Created on: 24/10/2013
 *      Author: Nicolas
 */

#include "Aplicacion.h"


void InitUART2 (void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 24 en 1 prende la UART2:
	PCONP |= 0x01<<24;
	//2.- Registro PCLKSEL1  - bits 16 y 17 en 0 seleccionan que el clk de la UART2 sea CCLK/4:
	PCLKSEL1 &= ~(0x03<<16);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U2LCR - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U2LCR = 0x00000083;
	//4.- Registros U2DLL y U2DLM - 9600 baudios:
	U2DLM = 0;
	U2DLL = 0xA3;//0xA3 para 9600
	//5.- Registros PINSEL - habilitan las funciones especiales de los pines:

	SetPINSEL(RX_232,PINSEL_FUNC1);
	SetPINSEL(TX_232,PINSEL_FUNC1);

	//6.- Registro U1LCR, pongo DLAB en 0:
	U2LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U2IER = 0x03;
	ISER0 |= (1<<7);
}
