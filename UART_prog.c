/*
 * UART_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "utils.h"
#include "UART_int.h"

#define UDR   *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)
#define SREG  *((volatile u8*)0x5F)


void UART_vidInit(void)
{
	//select UCSRC reg
	SETBIT(UCSRC,15);


	// select mode of uart
#if UART_MODE_SELECT == UART_ASYNCHRONOUS
	RESETBIT(UCSRC,6);
	#if UART_DOUBLE_SPEED == UART_DISABLE
		RESETBIT(UCSRA,1);
	#elif UART_DOUBLE_SPEED ==UART_ENABLE
		SETBIT(UCSRA,1);
	#else
	#endif
#elif UART_MODE_SELECT == UART_SYNCHRONOUS
	SETBIT(UCSRC,6);
#endif
	// parity mode
#if UART_PARITY_MODE == NO_PARITY_UART
	SETBIT(UCSRC,15);
	RESETBIT(UCSRC,5);
	RESETBIT(UCSRC,4);
#elif UART_PARITY_MODE == ODD_PARITY_UART
	SETBIT(UCSRC,5);
	SETBIT(UCSRC,4);
#elif UART_PARITY_MODE == EVEN_PARITY_UART
	SETBIT(UCSRC,5);
	RESETBIT(UCSRC,4);
#endif
	// number of stop bits
#if UART_STOP_BIT == ONE_STOP_BIT_UART
	RESETBIT(UCSRC,3);
#elif UART_STOP_BIT == TWO_STOP_BIT_UART
	SETBIT(UCSRC,3);
#endif
	// select num of bits
#if UART_NUM_OF_DATA_BITS == EIGHT_DATA_BIT
	SETBIT(UCSRC,1);
	SETBIT(UCSRC,2);
	RESETBIT(UCSRB,2);
#elif UART_NUM_OF_DATA_BITS == SEVEN_DATA_BIT
	RESETBIT(UCSRC,1);
	SETBIT(UCSRC,2);
	RESETBIT(UCSRB,2);
#elif UART_NUM_OF_DATA_BITS == SIX_DATA_BIT
	SETBIT(UCSRC,1);
	RESETBIT(UCSRC,2);
	RESETBIT(UCSRB,2);
#elif UART_NUM_OF_DATA_BITS == FIVE_DATA_BIT
	RESETBIT(UCSRC,1);
	RESETBIT(UCSRC,2);
	RESETBIT(UCSRB,2);
#elif UART_NUM_OF_DATA_BITS == NINE_DATA_BIT
	SETBIT(UCSRC,1);
	SETBIT(UCSRC,2);
	SETBIT(UCSRB,2);
#endif

#if RXC_INTERRUPT_UART == UART_ENABLE
	SETBIT(UCSRB,7);
	SETBIT(SREG,7);
#elif RXC_INTERRUPT_UART == UART_DISABLE
	RESETBIT(UCSRB,7);
#else
#endif

#if TXC_INTERRUPT_UART == UART_ENABLE
	SETBIT(UCSRB,6);
	SETBIT(SREG,7);
#elif TXC_INTERRUPT_UART == UART_DISABLE
	RESETBIT(UCSRB,6);
#else
#endif

#if UDR_EMPTY_INTERRUPT_UART == UART_ENABLE
	SETBIT(UCSRB,5);
	SETBIT(SREG,7);
#elif UDR_EMPTY_INTERRUPT_UART == UART_DISABLE
	RESETBIT(UCSRB,5);
#else
#endif

	// UBRR=(Fosc/16*baudrate)-1
#if BAUD_RATE_UART == _9600_BAUD_RATE
	UBRRL=77;
	UBRRH = 0;
#elif BAUD_RATE_UART == _19200_BAUD_RATE
	UBRRL=35;
	UBRRH=0;
#elif BAUD_RATE_UART==_1200_BAUD_RATE
	RESETBIT(UCSRC,15);
	UBRRL=0b01110000;
	UBRRH=0b10;
#else
#endif

	// enable RX,TX
	SETBIT(UCSRB,3);
	SETBIT(UCSRB,4);

	return;
}

void UART_vidSendData(u8 u8DataCPY)
{
	while(GETBIT(UCSRA,5)==0)
	{
		// wait until TX empty
	}
	UDR=u8DataCPY;

	return;
}

u8 UART_u8ReceiveData(void)
{
	u8 DataLOC=0;
	while(GETBIT(UCSRA,7)==0)
	{
		// wait until
	}
	DataLOC=UDR;

	return DataLOC;
}

void UART_vidTXState(u8 u8StateCPY)
{
	switch(u8StateCPY)
	{
	case TX_DISABLE:
		RESETBIT(UCSRB,3);
		break;
	case TX_ENABLE:
		SETBIT(UCSRB,3);
		break;
	default:break;
	}
return;
}

void UART_vidRXState(u8 u8StateCPY)
{
	switch(u8StateCPY)
	{
	case RX_DISABLE:
		RESETBIT(UCSRB,4);
		break;
	case RX_ENABLE:
		SETBIT(UCSRB,4);
		break;
	default:break;
	}
return;
}

