/*
 * FW_InitUART3.c
 *
 *  Created on: 24/10/2013
 *      Author: Nicolas
 */

#include "Aplicacion.h"
void InitUART3 (void);

void InitUART3 (void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 25 en 1 prende la UART3:
	PCONP |= 0x01<<25;
	//2.- Registro PCLKSEL1  - bits 18 y 19 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	PCLKSEL1 &= ~(0x03<<18);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U3LCR - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U3LCR = 0x00000083;
	//4.- Registros U1DLL  y U1DLM - 9600 baudios:
	U3DLM = 0;
	U3DLL = 0xA3;//0xA3 para 9600

	//5.- Registros PINSEL - habilitan las funciones especiales de los pines:
	SetPINSEL(RX_485,PINSEL_FUNC2);
	SetPINSEL(TX_485,PINSEL_FUNC2);
	SetPINSEL(TE_485,PINSEL_GPIO);
	SetDIR(TE_485,SALIDA);
	SetPIN(TE_485,1); //transmision

	//6.- Registro U3LCR, pongo DLAB en 0:
	U3LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U3IER = 0x03;
	ISER0 |= (1<<8);
}
