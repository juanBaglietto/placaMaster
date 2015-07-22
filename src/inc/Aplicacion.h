/*
 * Aplicacion.h
 *
 *  Created on: 24/10/2013
 *      Author: Nicolas
 */

#ifndef APLICACION_H_
#define APLICACION_H_

#include <cr_section_macros.h>
#include <NXP/crp.h>

#include "DHTxx.h"
#include "FW_Pantalla.h"
#include"KitInfo2.h"
#include"KitInic.h"
#include "Regs.h"
#include "TimersM.h"
#include"UtilesInfo2.h"
#include "FW_UARTs.h"
#include "PR_Serie.h"
#include "TimersM.h"

typedef struct{
	uint8_t mentira[2];
	uint8_t vel;
	uint8_t str[101];
	uint8_t arrayID[4];
	uint8_t Tipo_Elem;
}Elemento;

#define	ELEMENTO_TEXTO			0
#define	ELEMENTO_TEMPERATURA	1
#define	ELEMENTO_HUMEDAD		2

#define		MAXBUFFER		700

#define		MATRIXWIDTH		32
#define		TOPE			16


#define 	CANTESCLAVAS	3
#define 	PROTOCOL_ID		0
#define 	BROADCAST_ID	4
#define		INICIO_TX		0xAA //170
#define		FIN_PAQUETE		0xEE //238
#define		ACK				0xEE
#define		FIN_TX			0xCC//204


#endif /* APLICACION_H_ */
