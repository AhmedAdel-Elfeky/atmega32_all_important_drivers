/*
 * UART_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef UART_INT_H_
#define UART_INT_H_

#define ASYNCHRONOUS_UART 0
#define SYNCHRONOUS_UART  1
#define UART_MODE_SELECT       ASYNCHRONOUS_UART
#define ODD_PARITY_UART   2
#define EVEN_PARITY_UART  1
#define NO_PARITY_UART    0
#define UART_PARITY_MODE       NO_PARITY_UART
#define ONE_STOP_BIT_UART 0
#define TWO_STOP_BIT_UART 1
#define UART_STOP_BIT          ONE_STOP_BIT_UART
#define FIVE_DATA_BIT     0
#define SIX_DATA_BIT      1
#define SEVEN_DATA_BIT    2
#define EIGHT_DATA_BIT    3
#define NINE_DATA_BIT     4
#define UART_NUM_OF_DATA_BITS  EIGHT_DATA_BIT
#define UART_ENABLE		  1
#define UART_DISABLE 	  0
#define UART_DOUBLE_SPEED	   UART_DISABLE
#define UART_MPCM_MODE		   UART_DISABLE
#define RXC_INTERRUPT_UART     UART_DISABLE
#define TXC_INTERRUPT_UART     UART_DISABLE
#define UDR_EMPTY_INTERRUPT_UART UART_DISABLE
// UBRR=(Fosc/16*baudrate)-1
#define _9600_BAUD_RATE  0
#define _19200_BAUD_RATE  1
#define _1200_BAUD_RATE  2
#define BAUD_RATE_UART 		    _1200_BAUD_RATE
#define TX_DISABLE 0
#define TX_ENABLE 1
#define RX_DISABLE 0
#define RX_ENABLE 1
#define TX_PORT PORT_D
#define TX_PIN PIN_1
#define RX_PORT PORT_D
#define RX_PIN PIN_0

void UART_vidInit(void);
void UART_vidSendData(u8 u8DataCPY);
u8 UART_u8ReceiveData(void);
void UART_vidRXState(u8 u8StateCPY);
void UART_vidTXState(u8 u8StateCPY);



#endif /* UART_INT_H_ */
