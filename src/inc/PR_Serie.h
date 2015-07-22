/*
 * PR_Serie.h
 *
 *  Created on: 09/07/2013
 *      Author: Pablo
 */

#ifndef PR_SERIE_H_
#define PR_SERIE_H_


#include "Regs.h"

#define TXBUFFER_SIZE	200
#define RXBUFFER_SIZE	200
#define	TRANSMISION		1
#define	RECEPCION		0

//para UART2
uint8_t PushTx(uint8_t dato);
uint8_t PopTx( uint8_t *dato );
uint8_t PushRx(uint8_t dato);
uint8_t PopRx( uint8_t *dato );
void EnviarString (const char *str);

//para UART3
uint8_t PushTx3(uint8_t dato);
uint8_t PopTx3( uint8_t *dato );
uint8_t PushRx3(uint8_t dato);
uint8_t PopRx3( uint8_t *dato );
void EnviarString3 (uint8_t *str);
void CambiarEstadoTE(uint8_t estado);
void ActualizarDatos(void);
void EnviarInicioTx(void);
void EnviarPaquete(void);
void EnviarFinTX(void);

#endif /* PR_SERIE_H_ */
