 /**
 * Regs.h
 *
 *  Created on: 17/04/2012 -   Author: Mica y Chor
 *  modificado el 12/03/13 -   Author: Marcelo T. y G.
 *  modificado el 25/06/13 -   Author: GOS
 */

#ifndef REGS_H_
#define REGS_H_


	#define		__R					volatile const
	#define		__W					volatile
	#define		__RW				volatile

	typedef 	unsigned int 		uint32_t;
	typedef 	unsigned short 		uint16_t;
	typedef 	unsigned char 		uint8_t;
//	typedef 	__RW uint32_t 		registro;		//!< defino un tipo '__RW uint32_t' uint32_t volatile.

	//!< ////////////////__RW uint32_ts PINSEL//////////////////////////////
	//!< 0x4002C000UL : Direccion de inicio de los __RW uint32_ts PINSEL
	#define		PINSEL		( ( __RW uint32_t  * ) 0x4002C000UL )

	#define		PINSEL0		PINSEL[0]	//!< PINSEL0------>P0[15:0] 		(0x4002C000)
	#define		PINSEL1		PINSEL[1]	//!< PINSEL1------>P0[31:16] 		(0x4002C004)
	#define		PINSEL2		PINSEL[2]	//!< PINSEL2------>P1[15:0] 		(0x4002C008)
	#define		PINSEL3		PINSEL[3]	//!< PINSEL3------>P1[31:16] 		(0x4002C00C)
	#define		PINSEL4		PINSEL[4]	//!< PINSEL4------>P2[15:0] 		(0x4002C010)
	#define		PINSEL5		PINSEL[5]	//!< PINSEL5------>P2[31:16] 	NOT USED
	#define		PINSEL6		PINSEL[6]	//!< PINSEL6------>P3[15:0]		NOT USED
	#define		PINSEL7		PINSEL[7]	//!< PINSEL7------>P3[31:16] 		(0x4002C01C)
	#define		PINSEL8		PINSEL[8]	//!< PINSEL8------>P4[15:0]		NOT USED
	#define		PINSEL9		PINSEL[9]	//!< PINSEL9------>P4[31:16] 		(0x4002C024)

	//!< ----------- Estados de PINSEL:
	#define		PINSEL_GPIO			0
	#define		PINSEL_FUNC1		1
	#define		PINSEL_FUNC2		2
	#define		PINSEL_FUNC3		3

	//!< //////////////////__RW uint32_ts PINMODE ///////////////////////////
	//!< 0x4002C040UL : Direccion de inicio de los __RW uint32_ts de modo de los pines del GPIO
	#define	PINMODE		( ( __RW uint32_t  * ) 0x4002C040UL )

	#define		PINMODE0	PINMODE[0]		//!< 0x4002C040
	#define		PINMODE1	PINMODE[1]		//!< 0x4002C044
	#define		PINMODE2	PINMODE[2]		//!< 0x4002C048
	#define		PINMODE3	PINMODE[3]		//!< 0x4002C04C
	#define		PINMODE4	PINMODE[4]		//!< 0x4002C050
	#define		PINMODE5	PINMODE[5]		//!< 0x4002C054
	#define		PINMODE6	PINMODE[6]		//!< 0x4002C058
	#define		PINMODE7	PINMODE[7]		//!< 0x4002C05C
	#define		PINMODE9	PINMODE[9]		//!< 0x4002C064

	//!< ----------- Estados de PINMODE
	//!< 00	Pull Up resistor enable (reset value)		01	repeated mode enable
	//!< 11	Pull Down resistor enable					10	ni Pull Up ni Pull DOwn
	#define		PINMODE_PULLUP 		0
	#define		PINMODE_REPEAT 		1
	#define		PINMODE_NONE 		2
	#define		PINMODE_PULLDOWN 	3

	//!< ///////////////// __RW uint32_tS PINMODE_OD ///////////////////////////
	//!< 0x4002C068UL : Direccion de inicio de los __RW uint32_ts de control del modo OPEN DRAIN
	#define		PINMODE_OD		( ( __RW uint32_t  * ) 0x4002C068UL )

	#define		PINMODE_OD0		PINMODE_OD[0]
	#define		PINMODE_OD1		PINMODE_OD[1]
	#define		PINMODE_OD2		PINMODE_OD[2]
	#define		PINMODE_OD3		PINMODE_OD[3]
	#define		PINMODE_OD4		PINMODE_OD[4]

	//!< ////////////////// __RW uint32_tS GPIOs //////////////////////////////
	//!< 0x2009C000UL : Direccion de inicio de los __RW uint32_ts de GPIOs
	#define	GPIOs		( ( __RW uint32_t  * ) 0x2009C000UL )


	#define		PORT0		0
	#define		PORT1		1
	#define		PORT2		2
	#define		PORT3		3
	#define		PORT4		4

/*
	#define		PORT0		(GPIOs+0)		//!< 0x2009C000
	#define		PORT1		(GPIOs+8)		//!< 0x2009C020
	#define		PORT2		(GPIOs+16)		//!< 0x2009C040
	#define		PORT3		(GPIOs+24)		//!< 0x2009C060
	#define		PORT4		(GPIOs+32)		//!< 0x2009C080
*/
	/*	*						*
		*************************
		*		FIODIR			*	0x2009C000
		*************************
		*		RESERVED		*	0x2009C004
		*************************
		*		RESERVED		*	0x2009C008
		*************************
		*		RESERVED		*	0x2009C00C
		*************************
		*		FIOMASK			*	0x2009C010
		*************************
		*		FIOPIN			*	0x2009C014
		*************************
		*		FIOSET			*	0x2009C018
		*************************
		*		FIOCLR			*	0x2009C01C
		*************************
		*						*
		*						*
	*/
	#define		FIO0DIR		GPIOs[0]	//!< 0x2009C000
	#define		FIO1DIR		GPIOs[8]	//!< 0x2009C020
	#define		FIO2DIR		GPIOs[16]	//!< 0x2009C040
	#define		FIO3DIR		GPIOs[24]	//!< 0x2009C060
	#define		FIO4DIR		GPIOs[32]	//!< 0x2009C080

	#define		FIO0MASK	GPIOs[4]	//!< 0x2009C010
	#define		FIO1MASK	GPIOs[12]	//!< 0x2009C030
	#define		FIO2MASK	GPIOs[20]	//!< 0x2009C050
	#define		FIO3MASK	GPIOs[28]	//!< 0x2009C070
	#define		FIO4MASK	GPIOs[36]	//!< 0x2009C090

	#define		FIO0PIN		GPIOs[5]	//!< 0x2009C014
	#define		FIO1PIN		GPIOs[13]	//!< 0x2009C034
	#define		FIO2PIN		GPIOs[21]	//!< 0x2009C054
	#define		FIO3PIN		GPIOs[29]	//!< 0x2009C074
	#define		FIO4PIN		GPIOs[37]	//!< 0x2009C094

	#define		FIO0SET		GPIOs[6]	//!< 0x2009C018
	#define		FIO1SET		GPIOs[14]	//!< 0x2009C038
	#define		FIO2SET		GPIOs[22]	//!< 0x2009C058
	#define		FIO3SET		GPIOs[30]	//!< 0x2009C078
	#define		FIO4SET		GPIOs[38]	//!< 0x2009C098

	#define		FIO0CLR		GPIOs[7]	//!< 0x2009C01C
	#define		FIO1CLR		GPIOs[15]	//!< 0x2009C03C
	#define		FIO2CLR		GPIOs[23]	//!< 0x2009C05C
	#define		FIO3CLR		GPIOs[31]	//!< 0x2009C07C
	#define		FIO4CLR		GPIOs[39]	//!< 0x2009C09C



//-----------------------------------------------------------------------------
// NVIC
//-----------------------------------------------------------------------------

	#define		ISER 		( ( __RW uint32_t  * ) 0xE000E100UL )
	#define 	ISER0		ISER[0]
	#define 	ISER1		ISER[1]

	#define		ICER 		( ( __RW uint32_t  * ) 0xE000E180UL )
	#define		ICER0		ICER[0]
	#define		ICER1		ICER[1]

	#define		ISPR 		( ( __RW uint32_t  * ) 0xE000E200UL )
	#define		ISPR0		ISPR[0]
	#define		ISPR1		ISPR[1]

	#define		ICPR 		( ( __RW uint32_t  * ) 0xE000E280UL )
	#define		ICPR0		ICPR[0]
	#define		ICPR1		ICPR[1]

	#define		IABR 		( ( __RW uint32_t  * ) 0xE000E300UL )
	#define		IABR0		IABR[0]
	#define		IABR1		IABR[1]

	#define		IPR 		( ( __RW uint32_t  * ) 0xE000E400UL )
	#define		IPR0		IPR[0]
	#define		IPR1		IPR[1]
	#define		IPR2		IPR[2]
	#define		IPR3		IPR[3]
	#define		IPR4		IPR[4]
	#define		IPR5		IPR[5]
	#define		IPR6		IPR[6]
	#define		IPR7		IPR[7]
	#define		IPR8		IPR[8]

	#define		STIR_ 		( ( __RW uint32_t  * ) 0xE000EF00UL )
	#define		STIR 		STIR_[0]


//-----------------------------------------------------------------------------
// Interrupciones Externas
//-----------------------------------------------------------------------------
	#define		EXTINT_ 		( ( __RW uint32_t  * ) 0x400FC140UL )
	#define		EXTINT		EXTINT_[0]

	#define		EXTMODE_ 	( ( __RW uint32_t  * ) 0x400FC148UL )
	#define		EXTMODE		EXTMODE_[0]

	#define		EXTPOLAR_ 	( ( __RW uint32_t  * ) 0x400FC14CUL )
	#define 	EXTPOLAR	EXTPOLAR_[0]

	#define EINT0  0
	#define EINT1  1
	#define EINT2  2
	#define EINT3  3


//-----------------------------------------------------------------------------
// Interrupciones Externas GPIO
//-----------------------------------------------------------------------------
	#define		IOIntStatus_ 		( ( __RW uint32_t  * ) 0x40028080UL )
	#define		IOIntStatus			IOIntStatus_[0]

	// P0
	#define		IO0IntStatR_ 		( ( __RW uint32_t  * ) 0x40028084UL )
	#define		IO0IntStatR			IO0IntStatR_[0]

	#define		IO0IntStatF_ 		( ( __RW uint32_t  * ) 0x40028088UL )
	#define		IO0IntStatF			IO0IntStatF_[0]

	#define		IO0IntClr_ 			( ( __RW uint32_t  * ) 0x4002808CUL )
	#define		IO0IntClr			IO0IntClr_[0]

	#define		IO0IntEnR_ 			( ( __RW uint32_t  * ) 0x40028090UL )
	#define		IO0IntEnR			IO0IntEnR_[0]

	#define		IO0IntEnF_ 			( ( __RW uint32_t  * ) 0x40028094UL )
	#define		IO0IntEnF			IO0IntEnF_[0]

	// P2
	#define		IO2IntStatR_ 		( ( __RW uint32_t  * ) 0x400280A4UL )
	#define		IO2IntStatR			IO2IntStatR_[0]

	#define		IO2IntStatF_ 		( ( __RW uint32_t  * ) 0x400280A8UL )
	#define		IO2IntStatF			IO2IntStatF_[0]

	#define		IO2IntClr_ 			( ( __RW uint32_t  * ) 0x400280ACUL )
	#define		IO2IntClr			IO2IntClr_[0]

	#define		IO2IntEnR_ 			( ( __RW uint32_t  * ) 0x400280B0UL )
	#define		IO2IntEnR			IO2IntEnR_[0]

	#define		IO2IntEnF_ 			( ( __RW uint32_t  * ) 0x400280B4UL )
	#define		IO2IntEnF			IO2IntEnF_[0]

//-----------------------------------------------------------------------------
// Oscilador
//-----------------------------------------------------------------------------

	//////////////__RW uint32_ts del CLOCK y de sistema/////////////////
	//0x400FC1A0UL: __RW uint32_t de control de sistema y __RW uint32_t de status:
	#define		DIR_SCS			( (uint32_t *) 0x400FC1A0UL)
	//0x400FC104UL: __RW uint32_t de configuracion del clock:
	#define		DIR_CCLKCFG		( (uint32_t *) 0x400FC104UL)
	//0x400FC10CUL: __RW uint32_t de seleccion del clock:
	#define		DIR_CLKSRCSEL	( (uint32_t *) 0x400FC10CUL)
	//0x400FC1C8UL: Clock Output Config register:
	#define		DIR_CLKOUTCFG	( (uint32_t *) 0x400FC1C8UL)
	//0x400FC000UL: Flash access configuration:
	#define		DIR_FLASHCFG	( (uint32_t *) 0x400FC000UL)

	/////////////////__RW uint32_ts de los PLL///////////////////////////
	//0x400FC080UL: __RW uint32_t de control del PLL0:
	#define		DIR_PLL0CON		( (uint32_t *) 0x400FC080UL)
	//0x400FC084UL: __RW uint32_t de configuracion del PLL0:
	#define		DIR_PLL0CFG		( (uint32_t *) 0x400FC084UL)
	//0x400FC088UL: __RW uint32_t de estado del PLL0:
	#define		DIR_PLL0STAT	( (uint32_t *) 0x400FC088UL)
	//0x400FC08CUL: __RW uint32_t de control del PLL0:
	#define		DIR_PLL0FEED	( (uint32_t *) 0x400FC08CUL)
	//0x400FC0A0UL: __RW uint32_t de control del PLL1:
	#define		DIR_PLL1CON		( (uint32_t *) 0x400FC0A0UL)
	//0x400FC0A4UL: __RW uint32_t de configuracion del PLL1:
	#define		DIR_PLL1CFG		( (uint32_t *) 0x400FC0A4UL)
	//0x400FC0A8UL: __RW uint32_t de estado del PLL1:
	#define		DIR_PLL1STAT	( (uint32_t *) 0x400FC0A8UL)
	//0x400FC0ACUL: __RW uint32_t de control del PLL1:
	#define		DIR_PLL1FEED	( (uint32_t *) 0x400FC0ACUL)

	//__RW uint32_t de status y configuracion del sistema:
	#define		SCS			DIR_SCS[0]
	#define 	FLASHCFG	DIR_FLASHCFG[0]

	//__RW uint32_ts de control del CLOCK:
	#define		CCLKCFG		DIR_CCLKCFG[0]
	#define		CLKSRCSEL	DIR_CLKSRCSEL[0]
	#define		CLKOUTCFG	DIR_CLKOUTCFG[0]

	//PLL0:
	#define		PLL0CON		DIR_PLL0CON[0]
	#define		PLL0CFG		DIR_PLL0CFG[0]
	#define		PLL0STAT	DIR_PLL0STAT[0]
	#define		PLL0FEED	DIR_PLL0FEED[0]

	//PLL1:
	#define		PLL1CON		DIR_PLL1CON[0]
	#define		PLL1CFG		DIR_PLL1CFG[0]
	#define		PLL1STAT	DIR_PLL1STAT[0]
	#define		PLL1FEED	DIR_PLL1FEED[0]

	//!< ///////////////////   PCONP   //////////////////////////
	//!<  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
	//!< 0x400FC0C4UL : Direccion de inicio del __RW uint32_t de habilitación de dispositivos:
	#define 	PCONP	(* ( ( __RW uint32_t  * ) 0x400FC0C4UL ))


	//!< ///////////////////   PCLKSEL   //////////////////////////
	//!< Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
	//!< 0x400FC1A8UL : Direccion de inicio de los __RW uint32_ts de seleccion de los CLKs de los dispositivos:
	#define		PCLKSEL		( ( __RW uint32_t  * ) 0x400FC1A8UL )
	//!< __RW uint32_ts PCLKSEL
	#define		PCLKSEL0	PCLKSEL[0]
	#define		PCLKSEL1	PCLKSEL[1]


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

//-----------------------------------------------------------------------------
// Timers
//-----------------------------------------------------------------------------
//#define		PINSEL		( ( __RW uint32_t  * ) 0x4002C000UL )
//#define		PINSEL0		PINSEL[0]	//!< PINSEL0------>P0[15:0] 		(0x4002C000)

	// Timer 0
	#define		TIMER0 		( ( __RW uint32_t  * ) 0x40004000UL )
	#define		T0IR		TIMER0[0]
	#define		T0TCR		TIMER0[1]
	#define		T0TC		TIMER0[2]
	#define		T0PR		TIMER0[3]
	#define		T0PC		TIMER0[4]
	#define		T0MCR		TIMER0[5]
	#define		T0MR0		TIMER0[6]
	#define		T0MR1		TIMER0[7]
	#define		T0MR2		TIMER0[8]
	#define		T0MR3		TIMER0[9]
	#define		T0CCR		TIMER0[10]
	#define		T0CR0		TIMER0[11]
	#define		T0CR1		TIMER0[12]

	#define		T0EMR	( *( __RW uint32_t  * ) 0x4000403CUL )

	#define		T0CTCR	(* ( __RW uint32_t  * ) 0x40004070UL )

	// Timer 1
	#define		TIMER1 		( ( __RW uint32_t  * ) 0x40008000UL )
	#define		T1IR		TIMER1[0]
	#define		T1TCR		TIMER1[1]
	#define		T1TC		TIMER1[2]
	#define		T1PR		TIMER1[3]
	#define		T1PC		TIMER1[4]
	#define		T1MCR		TIMER1[5]
	#define		T1MR0		TIMER1[6]
	#define		T1MR1		TIMER1[7]
	#define		T1MR2		TIMER1[8]
	#define		T1MR3		TIMER1[9]
	#define		T1CCR		TIMER1[10]
	#define		T1CR0		TIMER1[11]
	#define		T1CR1		TIMER1[12]

	#define		T1EMR	(* ( __RW uint32_t  * ) 0x4000803CUL )

	#define		T1CTCR	( *( __RW uint32_t  * ) 0x40008070UL )

	// Timer 2
	#define		TIMER2 		( ( __RW uint32_t  * ) 0x40090000UL )
	#define		T2IR		TIMER2[0]
	#define		T2TCR		TIMER2[1]
	#define		T2TC		TIMER2[2]
	#define		T2PR		TIMER2[3]
	#define		T2PC		TIMER2[4]
	#define		T2MCR		TIMER2[5]
	#define		T2MR0		TIMER2[6]
	#define		T2MR1		TIMER2[7]
	#define		T2MR2		TIMER2[8]
	#define		T2MR3		TIMER2[9]
	#define		T2CCR		TIMER2[10]
	#define		T2CR0		TIMER2[11]
	#define		T2CR1		TIMER2[12]

	#define		T2EMR	(* ( __RW uint32_t  * ) 0x4009003CUL )

	#define		T2CTCR	( *( __RW uint32_t  * ) 0x40090070UL )

	// Timer 3
	#define		TIMER3 		( ( __RW uint32_t  * ) 0x40094000UL )
	#define		T3IR		TIMER3[0]
	#define		T3TCR		TIMER3[1]
	#define		T3TC		TIMER3[2]
	#define		T3PR		TIMER3[3]
	#define		T3PC		TIMER3[4]
	#define		T3MCR		TIMER3[5]
	#define		T3MR0		TIMER3[6]
	#define		T3MR1		TIMER3[7]
	#define		T3MR2		TIMER3[8]
	#define		T3MR3		TIMER3[9]
	#define		T3CCR		TIMER3[10]
	#define		T3CR0		TIMER3[11]
	#define		T3CR1		TIMER3[12]

	#define		T3EMR	( *( __RW uint32_t  * ) 0x4009403CUL )

	#define		T3CTCR	(* ( __RW uint32_t  * ) 0x40094070UL )


	//!< /////////////		UARTs		///////////////////////////
	//0x40098000UL : Registro de recepcion de la UART2:
	#define		DIR_UART2		( ( __RW uint32_t  * ) 0x40098000UL )

	#define		U2RBR		DIR_UART2[0]
	#define		U2THR		DIR_UART2[0]
	#define		U2DLL		DIR_UART2[0]
	#define		U2IER		DIR_UART2[1]
	#define		U2DLM		DIR_UART2[1]
	#define		U2IIR		DIR_UART2[2]
	#define		U2LCR		DIR_UART2[3]
	#define		U2LSR		DIR_UART2[5]

	//0x4009C000UL : Registro de recepcion de la UART1:
	#define		DIR_UART3		( ( __RW uint32_t  * ) 0x4009C000UL )

	#define		U3RBR		DIR_UART3[0]
	#define		U3THR		DIR_UART3[0]
	#define		U3DLL		DIR_UART3[0]
	#define		U3IER		DIR_UART3[1]
	#define		U3DLM		DIR_UART3[1]
	#define		U3IIR		DIR_UART3[2]
	#define		U3LCR		DIR_UART3[3]
	#define		U3LSR		DIR_UART3[5]

	#endif /* REGS_H_ */
