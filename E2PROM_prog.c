/*
 * E2PROM_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "I2C_int.h"
#include "E2PROM_int.h"


void E2PROM_vidWriteData(u8 u8BlockNumCPY, u8 u8AddressCPY, u8 u8DataCPY)
{
	u8 u8TempAddressLOC;
	u8TempAddressLOC=(0b01010000|u8BlockNumCPY);
	do
	{
		I2C_vidSendStartBit();
		I2C_vidWriteAddress(u8TempAddressLOC,0);

	}while(I2C_u8GetStatus()!=0x18);

	I2C_vidWriteData(u8AddressCPY);
	I2C_vidWriteData(u8DataCPY);
	I2C_vidSendStopBit();

	return;
}

u8 E2PROM_vu8ReadData( u8 u8BlockNumCPY , u8 u8AddressCPY )
{
	u8 u8TempAddressLOC;
	u8 u8DataReadLOC;
	// choosing block
	u8TempAddressLOC=(0b01010000|u8BlockNumCPY);

	do
	{
		I2C_vidSendStartBit();
		I2C_vidWriteAddress(u8TempAddressLOC,0);
	}while(I2C_u8GetStatus()!=0x18);

	I2C_vidWriteData(u8AddressCPY);
	I2C_vidSendStartBit();
	I2C_vidWriteAddress(u8TempAddressLOC,1);
	u8DataReadLOC= I2C_u8ReadDataACK();
	I2C_vidSendStopBit();

	return u8DataReadLOC;
}
