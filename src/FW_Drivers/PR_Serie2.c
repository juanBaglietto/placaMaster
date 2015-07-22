/**
 	\file PR_serie.c
 	\brief Primitiva de comunicación serie
 	\details buffers de RX y TX protegidos
 	\author Pablo Irrera Condines
 	\date 2013.05.08
*/

#include "Aplicacion.h"

extern uint8_t txStart;
// Buffer de Transmision
uint8_t bufferTx2[TXBUFFER_SIZE];
// Buffer de Recepcion
uint8_t bufferRx2[RXBUFFER_SIZE];

// Indices de Transmision
uint8_t tx_in2,tx_out2;
// Indices de Recepcion
uint8_t rx_in2,rx_out2;
// Flags de estado de los buffers
uint8_t tx_buffer_full2 = 0, tx_buffer_empty2 = 1;
uint8_t rx_buffer_full2 = 0, rx_buffer_empty2 = 1;

uint8_t PushTx(uint8_t dato)
{
	if(tx_buffer_full2)
		return 1;	//buffer lleno

	bufferTx2[tx_in2] = dato;
	tx_in2++;
	tx_in2 %= TXBUFFER_SIZE;
	tx_buffer_empty2 = 0;	//si agrego un dato el buffer ya no esta vacio

	if(tx_in2 == tx_out2)
		tx_buffer_full2 = 1;	//se lleno el buffer

	if (txStart == 0)
	{
		txStart = 1;
		START_TX();
	}
	return 0;	//dato agregado al buffer
}

uint8_t PopTx( uint8_t *dato )
{
	if(tx_buffer_empty2)
		return 1;	//buffer vacio

	*dato = (uint8_t) bufferTx2[tx_out2];
	tx_out2++;
	tx_out2 %= TXBUFFER_SIZE;
	tx_buffer_full2 = 0;	//si saco un dato el buffer ya no esta lleno

	if(tx_out2 == tx_in2)
		tx_buffer_empty2 = 1;	//se vacio el buffer

	return 0;	//dato sacado del buffer
}

uint8_t PushRx( uint8_t dato )
{
	if(rx_buffer_full2)
		return 1;	//buffer lleno

	bufferTx2[rx_in2] = dato;
	rx_in2 ++;
	rx_in2 %= RXBUFFER_SIZE;
	rx_buffer_empty2 = 0;	//si agrego un dato el buffer ya no esta vacio

	if(rx_in2 == rx_out2)
		rx_buffer_full2 = 1;	//se lleno el buffer

	return 0;	//dato agregado al buffer
}

uint8_t PopRx( uint8_t *dato )
{
	if(rx_buffer_empty2)
		return 1;	//buffer vacio

	*dato = (uint8_t) bufferTx2[rx_out2];
	rx_out2++;
	rx_out2 %= RXBUFFER_SIZE;
	rx_buffer_full2 = 0;	//si saco un dato el buffer ya no esta lleno

	if(rx_out2 == rx_in2)
		rx_buffer_empty2 = 1;	//se vacio el buffer

	return 0;	//dato sacado del buffer
}

void EnviarString (const char *str)
{
	uint32_t i;
	for( i = 0 ; str[i] ; i++ )
		PushTx( str[i] );
}
