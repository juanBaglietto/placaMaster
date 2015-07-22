/*
 * FW_Pantalla.h
 *
 *  Created on: 24/10/2013
 *      Author: Nicolas
 */
#include "Regs.h"

#ifndef FW_PANTALLA_H_
#define FW_PANTALLA_H_

void LedMultiplexation(void);
void FillBuffer(uint8_t str[]);
void ResetON(void);
void ResetOFF(void);
void ClockON(void);
void ClockOFF(void);
void SendDataToMatrix(uint8_t index);
void SendZeroToMatrix(void);
void prendermatriz(void);
void apagarmatriz(void);
void VaciarBuffer(void);
void IncrementarIndices(void);
void get_message (void);

#endif /* FW_PANTALLA_H_ */
