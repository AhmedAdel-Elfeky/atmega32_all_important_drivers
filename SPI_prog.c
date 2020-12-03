/*
 * SPI_int.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */


#include "std_types.h"
#include "utils.h"
#include "SPI_int.h"

#define SPCR *((volatile u8*)0x2D)
#define SPSR *((volatile u8*)0x2E)
#define SPDR *((volatile u8*)0x2F)
#define SREG *((volatile u8*)0x5F)


void SPI_vidInit(void)
{
	// choose Master/slave
#if SPI_MODE==MASTER_MODE
	SETBIT(SPCR,4);
#elif SPI_MODE==SLAVE_MODE
	RESETBIT(SPCR,4);
#else
#endif
	// choose polarity
#if CLK_POLARITY==IDLE_HIGH
	SETBIT(SPCR,3);
#elif CLK_POLARITY==IDLE_LOW
	RESETBIT(SPCR,3);
#else
#endif
	// choose phase
#if CLK_PHASE==SAMPLE_AT_LEADING
	RESETBIT(SPCR,2);
#elif CLK_PHASE==SAMPLE_AT_TRAILING
	SETBIT(SPCR,2);
#else
#endif
	// Data order
#if DATA_ORDER==LSB_TRANSIMITT_FIRST
	SETBIT(SPCR,5);
#elif DATA_ORDER==MSP_TRANSIMITT_FIRST
	RESETBIT(SPCR,5);
#else
#endif
	// clk
#if SPI_CLK==FOSC_2
	RESETBIT(SPCR,0);
	RESETBIT(SPCR,1);
	SETBIT(SPSR,0);
#elif SPI_CLK==FOSC_4
	RESETBIT(SPCR,0);
	RESETBIT(SPCR,1);
	RESETBIT(SPSR,0);
#elif SPI_CLK==FOSC_8
	SETBIT(SPCR,0);
	RESETBIT(SPCR,1);
	SETBIT(SPSR,0);
#elif SPI_CLK==FOSC_16
	SETBIT(SPCR,0);
	RESETBIT(SPCR,1);
	RESETBIT(SPSR,0);
#elif SPI_CLK==FOSC_32
	RESETBIT(SPCR,0);
	SETBIT(SPCR,1);
	SETBIT(SPSR,0);
#elif SPI_CLK==FOSC_64
	RESETBIT(SPCR,0);
	SETBIT(SPCR,1);
	RESETBIT(SPSR,0);
#elif SPI_CLK==FOSC_128
	SETBIT(SPCR,0);
	SETBIT(SPCR,1);
	RESETBIT(SPSR,0);
#else
#endif

#if SPI_INTERRUPT== SPI_ENABLE
	SETBIT(SPCR,7);
	SETBIT(SREG,7);
#elif SPI_INTERRUPT==SPI_DISABLE
	RESETBIT(SPCR,7);
#else
#endif
	// enable SPI
	SETBIT(SPCR,6);

	return;
}

void SPI_vidTransmitter(u8 u8DataCPY)
{
	while(GETBIT(SPSR,7)==0) //wait
	{
		// nothing
	}
	SPDR=u8DataCPY;

	return;
}

u8 SPI_u8Receiver(void) //wait
{
	while(GETBIT(SPSR,7)==0)
		{
			// nothing
		}
	return SPDR;
}

void SPI_vidState(u8 u8StateCPY)
{
	switch(u8StateCPY)
	{
	case SPI_ENABLE:
		SETBIT(SPCR,6);
		break;
	case SPI_DISABLE:
		RESETBIT(SPCR,6);
		break;
	default:break;
	}
	return;
}

void SPI_vidModeSlect(u8 u8ModeCPY)
{
	switch(u8ModeCPY)
	{
	case MASTER_MODE:
		SETBIT(SPCR,4);
		break;
	case SLAVE_MODE:
		RESETBIT(SPCR,4);
		break;
	default:break;
	}
	return;
}



/*
void SPI_vidSlaveInit(void)
{
	// choose
		RESETBIT(SPCR,4);
	// choose polarity =
		RESETBIT(SPCR,3);
	// choose phase
		SETBIT(SPCR,2);
	// Data order
		SETBIT(SPCR,5);
	// enable SPI
		SETBIT(SPCR,6);

	return;
}


*/








