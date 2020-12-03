/*
 * I2C_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

#define POLLING 1
#define INTERRUPT 2
#define I2C_METHOD POLLING

void I2C_vidInit(void);
void I2C_vidSendStartBit(void);
void I2C_vidSendStopBit(void);
void I2C_vidWriteAddress(u8 u8AddressCPY,u8 u8WorRCPY);
void I2C_vidWriteData(u8 u8DataCPY);
u8 I2C_u8GetStatus(void);
u8 I2C_u8ReadDataACK(void);
u8 I2C_u8ReadDataNACK(void);
void I2C_vidTransmitByte(u8 u8AddressCPU,u8 u8DataCPY);
u8 I2C_u8ReceiveByte(u8 u8AddressCPU);
void I2C_vidTransmitBuffer(u8* u8BufferCPY,u8 u8AddressCPY,u8 u8NumOfBytesCPY);
void I2C_vidReceiveBuffer(u8 u8AddressCPY,u8* u8SaveInArrayCPY,u8 u8NumOfBytesCPY);


#endif /* I2C_INT_H_ */
