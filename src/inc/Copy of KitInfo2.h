/*
 * KitInfo2.h
 *
 *  Created on: 17/04/2012
 *      Author: Mica y Chor
 *	modificado por Marcelo T. y G.
 */
#ifndef KITINFO2_H_
#define KITINFO2_H_

	#include "Regs.h"
	#include "KitInic.h"
	#include "UtilesInfo2.h"

	//******agregue aquí debajo los includes propios de su aplicación.
	//#include "..............h"
	//#include "..............h"
	//#include "..............h"
	//******

	//SALIDAS:
	#define		LEDXpresso	PORT0,22
	#define		FILA1		PORT1,30
	#define		FILA2		PORT0,26
	#define		FILA3		PORT0,25
	#define		FILA4		PORT0,24
	#define		FILA5		PORT0,23
	#define		FILA6		PORT0,16
	#define		FILA7		PORT0,15
	#define		FILA8		PORT0,17

	#define		CLOCK		PORT2,13
	#define		RESET		PORT0,21


	#define		SALIDA1		PORT0,27
	#define		SALIDA2		PORT0,22
	#define		SALIDA3		PORT0,28
	#define		SALIDA4		PORT0,3
	#define		SALIDA5		PORT0,2
	#define		SALIDA6		PORT1,31

	//ENTRADAS:
	#define		PULS1		PORT2,6
	#define		PULS2		PORT2,5
	#define		PULS3		PORT2,4
	#define		PULS4		PORT2,3

	//SENSOR:
	#define		DHT_DATA	PORT2,10

	//COMUNICACION
	#define		RX_232		PORT0,11
	#define		TX_232		PORT0,10
	#define		RX_485		PORT0,1
	#define		TX_485		PORT0,0
	#define		TE_485		PORT0,6



	//Defines generales:
	#define		OFF			0
	#define		ON			1



	//Valores para configuracion del PLL:
	#define CLOCK_SETUP_Value 	    1
	#define SCS_Value				0x00000020
	#define CLKSRCSEL_Value         0x00000001
	#define PLL0_SETUP_Value        1
	#define PLL0CFG_Value           0x00050063
	#define PLL1_SETUP_Value        1
	#define PLL1CFG_Value           0x00000023
	#define CCLKCFG_Value           0x00000003
	#define USBCLKCFG_Value         0x00000000
	#define PCLKSEL0_Value          0x00000000
	#define PCLKSEL1_Value          0x00000000
	#define PCONP_Value             0x042887DE
	#define CLKOUTCFG_Value         0x00000000
	#define FLASHCFG_Value			0x00004000


#endif /* KITINFO2_H_ */
