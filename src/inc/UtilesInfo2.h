 /*
 * UtilesInfo2.h
 *
 *  Created on: 30/03/2013
 *      Author: Marcelo
 *  modificado on: 25/06/13
 *  Author: GOS
 */


#ifndef UTILESINFO2_H_
#define UTILESINFO2_H_

#include "Regs.h"

	//Prototipos de las funciones utilitarias
void SetPINSEL ( uint8_t  , uint8_t  ,uint8_t );
void SetPINMODE( uint8_t  , uint8_t  ,uint8_t );
void SetPINMODEOD( uint8_t port , uint8_t pin ,uint8_t modo);
void SetDIR( uint8_t  , uint8_t  , uint8_t  );
void SetPIN( uint8_t  , uint8_t  , uint8_t  );
uint8_t GetPIN( uint8_t  , uint8_t  , uint8_t );

	// dirección en FIODIR
	#define 	ENTRADA			0
	#define 	SALIDA			1

	// identificadores de los puertos
	#define 	P0			0
	#define 	P1			1
	#define 	P2			2
	#define 	P3			3
	#define 	P4			4


#endif /* UTILESINFO2_H_ */
