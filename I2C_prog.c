/*
 * I2C_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "utils.h"
#include "I2C_int.h"

#define TWAR *((volatile u8*)0x22)
#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#define TWDR *((volatile u8*)0x23)
#define TWSR *((volatile u8*)0x21)


void I2C_vidInit(void)
{
	// bit rate
	TWBR = 72;
	// pre-scaler
	RESETBIT(TWSR,0);
	RESETBIT(TWSR,1);
	// address
	TWAR=0x50;
	//enable ACK
	SETBIT(TWCR,6);
	// enable twi
	SETBIT(TWCR,2);

#if I2C_METHOD == POLLING
	SETBIT(TWCR,0);  //TWIE is off
#elif I2C_METHOD == INTERRUPT
	SETBIT(TWCR,0);   // set the TWIE (enable)
	SETBIT(SREG,7);
#endif
	return;
}

void I2C_vidSendStartBit(void)
{
	// set start bit
	SETBIT(TWCR,5);
	// clear flag
	SETBIT(TWCR,7);
	// reset start bit
	RESETBIT(TWCR,5);

	// wait on flag
	#if I2C_METHOD == POLLING
	while(GETBIT(TWCR,7)==0)
	{
		//
	}

	#endif


	return;
}

void I2C_vidSendStopBit(void)
{
	// set stop bit
	SETBIT(TWCR,4);
	// clear flag
	SETBIT(TWCR,7);

	return;
}

void I2C_vidWriteAddress(u8 u8AddressCPY,u8 u8WorRCPY)
{

	TWDR=(u8AddressCPY<<1)|u8WorRCPY;
	SETBIT(TWCR,7);
	#if I2C_METHOD == POLLING
	while(GETBIT(TWCR,7)==0)
	{
		//
	}

	#endif

	return;
}

void I2C_vidWriteData(u8 u8DataCPY)
{
	TWDR=u8DataCPY;
	SETBIT(TWCR,7);
	#if I2C_METHOD == POLLING
	while(GETBIT(TWCR,7)==0)
	{
		//
	}

	#endif
	return;
}

u8 I2C_u8GetStatus(void)
{
	u8 u8StatusLOC;
	u8StatusLOC=TWSR & 0xf8;
	return u8StatusLOC;
}

u8 I2C_u8ReadDataACK(void)
{
	// enable ACK
	SETBIT(TWCR,6);
	SETBIT(TWCR,7);
	#if I2C_METHOD == POLLING
	while(GETBIT(TWCR,7)==0)
	{
		//
	}

	#endif
	return TWDR;
}

u8 I2C_u8ReadDataNACK(void)
{
	// Disable NACK
	RESETBIT(TWCR,6);
	SETBIT(TWCR,7);
	#if I2C_METHOD == POLLING
	while(GETBIT(TWCR,7)==0)
	{
		//
	}

	#endif
	return TWDR;
}

void I2C_vidTransmitByte(u8 u8AddressCPU,u8 u8DataCPY)
{
	I2C_vidSendStartBit();
	I2C_vidWriteAddress(u8AddressCPU,0);
	I2C_vidWriteData(u8DataCPY);
	I2C_vidSendStopBit();

	return;
}

u8 I2C_u8ReceiveByte(u8 u8AddressCPU)
{
	u8 u8ReceivedDatsLOC;
	I2C_vidSendStartBit();
	I2C_vidWriteAddress(u8AddressCPU,0);
	u8ReceivedDatsLOC = I2C_u8ReadDataACK();
	I2C_vidSendStopBit();
	return u8ReceivedDatsLOC;
}

void I2C_vidTransmitBuffer(u8* u8BufferCPY,u8 u8AddressCPY,u8 u8NumOfBytesCPY)
{
	u8 u8LopCtr;
	I2C_vidSendStartBit();
	I2C_vidWriteAddress(u8AddressCPY,0);
	for(u8LopCtr=0;u8LopCtr<u8NumOfBytesCPY;u8LopCtr++)
	{
		I2C_vidWriteData(u8BufferCPY[u8LopCtr]);
	}
	I2C_vidSendStopBit();

	return;
}

void I2C_vidReceiveBuffer(u8 u8AddressCPY,u8* u8SaveInArrayCPY,u8 u8NumOfBytesCPY)
{
	u8 u8LopCtr=0;
	I2C_vidSendStartBit();
	I2C_vidWriteAddress(u8AddressCPY,0);
	for(u8LopCtr=0;u8LopCtr<u8NumOfBytesCPY;u8LopCtr++)
	{
		u8SaveInArrayCPY[u8LopCtr]= I2C_u8ReadDataACK();
	}
	I2C_vidSendStopBit();
	return ;
}

