/*
 * FW_UARTs.h
 *
 *  Created on: 26/10/2013
 *      Author: Nicolas
 */

#ifndef FW_UARTS_H_
#define FW_UARTS_H_

void InitUART2 (void);
void InitUART3 (void);
void procesaDato(uint8_t* datoLlegado);

#define START_TX()		(PopTx((uint8_t*)&U2THR))
#define START_TX485()	(PopTx3((uint8_t*)&U3THR))

uint8_t upper (uint8_t c);
uint8_t lower (uint8_t c);

#endif /* FW_UARTS_H_ */
