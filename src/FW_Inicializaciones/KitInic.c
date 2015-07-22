/*
 * KitInic.c
 *
 *  Created on: 17/04/2012
 *      Author: Mica y Chor
 */

#include "KitInfo2.h"

void InicializarKit ( void )
{
	InicGPIOs();
	InicPLL();
	InitUART2();
	InitUART3();
}



/********************************************************************************
	\fn  void InitGPIOs (void)
	\brief: Para cada PIN de un PUERTO de entrada/salida, tengo que configurar 2 registros:
			PINSEL: Selecciona si el pin se comportara como un GPIO o como el pin de un periférico
					Para modificar este registro uso la función SetPINSEL, definida en UtilesInfo2.c
			FIODIR:	Selecciona si el pin se comportara como una entrada o como una salida digital
					Para modificar este registro uso la función SetPIN, definida en UtilesInfo2.c

	\author & date: CATEDRA INFO2 - Feb2012
 	\param 	void
	\return void
*/
void InicGPIOs ( void )
{
	//PANTALLA
	SetPINSEL(LEDXpresso,PINSEL_GPIO);
	SetPINSEL(FILA1,PINSEL_GPIO);
	SetPINSEL(FILA2,PINSEL_GPIO);
	SetPINSEL(FILA3,PINSEL_GPIO);
	SetPINSEL(FILA4,PINSEL_GPIO);
	SetPINSEL(FILA5,PINSEL_GPIO);
	SetPINSEL(FILA6,PINSEL_GPIO);
	SetPINSEL(FILA7,PINSEL_GPIO);
	SetPINSEL(FILA8,PINSEL_GPIO);
	SetPINSEL(CLOCK,PINSEL_GPIO);
	SetPINSEL(RESET,PINSEL_GPIO);

	//SALIDAS EXTRA
	SetPINSEL(SALIDA1,PINSEL_GPIO);
	SetPINSEL(SALIDA2,PINSEL_GPIO);
	SetPINSEL(SALIDA3,PINSEL_GPIO);
	SetPINSEL(SALIDA4,PINSEL_GPIO);
	SetPINSEL(SALIDA5,PINSEL_GPIO);
	SetPINSEL(SALIDA6,PINSEL_GPIO);

	//SENSOR
	SetPINSEL(DHT_DATA,PINSEL_GPIO);
	/*
	//PULSADORES
	SetPINSEL(PULS1,PINSEL_GPIO);
	SetPINSEL(PULS2,PINSEL_GPIO);
	SetPINSEL(PULS3,PINSEL_GPIO);
	SetPINSEL(PULS4,PINSEL_GPIO);


	*/

	//2°)A aquellos pines configurados como GPIO, les configuro su DIRECCION en FIOxDIR
	//void SetDIR(registro* puerto,uint8_t pin,uint8_t direccion)
	//SALIDAS:
	SetDIR (LEDXpresso,SALIDA);
	SetDIR (FILA1,SALIDA);
	SetDIR (FILA2,SALIDA);
	SetDIR (FILA3,SALIDA);
	SetDIR (FILA4,SALIDA);
	SetDIR (FILA5,SALIDA);
	SetDIR (FILA6,SALIDA);
	SetDIR (FILA7,SALIDA);
	SetDIR (FILA8,SALIDA);
	SetDIR (CLOCK,SALIDA);
	SetDIR (RESET,SALIDA);
	//SALIDAS EXTRA
	SetDIR (SALIDA1,SALIDA);
	SetDIR (SALIDA2,SALIDA);
	SetDIR (SALIDA3,SALIDA);
	SetDIR (SALIDA4,SALIDA);
	SetDIR (SALIDA5,SALIDA);
	SetDIR (SALIDA6,SALIDA);

	SetDIR (DHT_DATA,ENTRADA);
	/*
	//PULSADORES
	SetDIR (PULS1,ENTRADA);
	SetDIR (PULS2,ENTRADA);
	SetDIR (PULS3,ENTRADA);
	SetDIR (PULS4,ENTRADA);


	*/


	//Empiezo el programa con los estados iniciales
	SetPIN(LEDXpresso,OFF);
	SetPIN(FILA1,OFF);
	SetPIN(FILA2,OFF);
	SetPIN(FILA3,OFF);
	SetPIN(FILA4,OFF);
	SetPIN(FILA5,OFF);
	SetPIN(FILA6,OFF);
	SetPIN(FILA7,OFF);
	SetPIN(FILA8,OFF);
	SetPIN(CLOCK,ON);
	SetPIN(RESET,ON);
	SetPIN(SALIDA1,OFF);
	SetPIN(SALIDA2,OFF);
	SetPIN(SALIDA3,OFF);
	SetPIN(SALIDA4,OFF);
	SetPIN(SALIDA5,OFF);
	SetPIN(SALIDA6,OFF);


}


/********************************************************************************
	\fn  void InicPLL (void)
	\brief: Este bloque de codigo habilita el oscilador externo como fuente de clk
			del micro, y configura un dispositivo conocido como PLL (Phase Locked Loop)
			para generar un clock interno de 100MHz a partir del oscilador conectado.
			SE RECOMIENDA NO MODIFICAR PARA SU USO EN EL KIT DE INFO2
	\author & date: CATEDRA INFO2- Nov2012
 	\param 	void
	\return void
*/
void InicPLL ( void )
{
	SCS       = SCS_Value;

	if (SCS_Value & (1 << 5))               /* If Main Oscillator is enabled      */
		while ((SCS & (1<<6)) == 0);/* Wait for Oscillator to be ready    */

	CCLKCFG   = CCLKCFG_Value;      /* Setup Clock Divider                */

	PCLKSEL0  = PCLKSEL0_Value;     /* Peripheral Clock Selection         */
	PCLKSEL1  = PCLKSEL1_Value;

	CLKSRCSEL = CLKSRCSEL_Value;    /* Select Clock Source for PLL0       */

	PLL0CFG   = PLL0CFG_Value;      /* configure PLL0                     */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	PLL0CON   = 0x01;             /* PLL0 Enable                        */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	while (!(PLL0STAT & (1<<26)));/* Wait for PLOCK0                    */

	PLL0CON   = 0x03;             /* PLL0 Enable & Connect              */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	while (!(PLL0STAT & ((1<<25) | (1<<24))));/* Wait for PLLC0_STAT & PLLE0_STAT */

	PLL1CFG   = PLL1CFG_Value;
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	PLL1CON   = 0x01;             /* PLL1 Enable                        */
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	while (!(PLL1STAT & (1<<10)));/* Wait for PLOCK1                    */

	PLL1CON   = 0x03;             /* PLL1 Enable & Connect              */
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	while (!(PLL1STAT & ((1<< 9) | (1<< 8))));/* Wait for PLLC1_STAT & PLLE1_STAT */

	PCONP     = PCONP_Value;        /* Power Control for Peripherals      */

	CLKOUTCFG = CLKOUTCFG_Value;    /* Clock Output Configuration         */

	FLASHCFG  = (FLASHCFG & ~0x0000F000) | FLASHCFG_Value;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// fn  void InicTimeo0 (void)
	//author & date: CATEDRA INFO2- Nov2012
 	//param 	void
	//return void
//-----------------------------------------------------------------------------
void InicTimer0(void){

	PCONP |= 1 << 1; 				// Habilitar Timer 0
	PCLKSEL0 |= 1 << 2; 			// Clock for timer PCLK = CCLK Selecciono clock
	T0MR0 = 5000;				// Configuro el tiempo del match 0
	T0MCR = 0x00000003;				// Configuro match 0 para interrumpir y resetear timer
	ISER0 |=(0x01 << 1);       		// Habilito Interrupcion TIMER0
	T0TCR = 0x00000002;				// Apago y reseteo el temporizador
	T0TCR = 0x00000001;				// Enciendo el temporizador

}
void InicTimer1(void){

	PCONP |= 1 << 2; 				// Habilitar Timer 1
	PCLKSEL1 |= 1 << 2; 			// Clock for timer PCLK = CCLK Selecciono clock
	T1MR0 = 500000;				// Configuro el tiempo del match 0
	T1MCR = 0x00000003;				// Configuro match 0 para interrumpir y  resetear timer
	T1TCR = 0x00000002;				// Apago y reseteo el temporizador
	T1TCR = 0x00000001;				// Enciendo el temporizador
	ISER0 |=(0x01 << 2);       		// Habilito Interrupcion TIMER1

}

void InicTimer2(void)
{

	PCONP |= 1 << 22; 				// Habilitar Timer 2
	PCLKSEL0 |= 1 << 2; 			// Clock for timer PCLK = CCLK Selecciono clock
	T2MR0 = 250;				    // Configuro el tiempo del match 0 cada 10 microsegundos
	T2MCR = 0x00000003;				// Configuro match 2 para interrumpir
	T2TCR = 0x00000002;				// Apago y reseteo el temporizador
	T2TCR = 0x00000001;				// Enciendo el temporizador
	ISER0 |=(0x01 << 3);       		// Habilito Interrupcion TIMER2

}

