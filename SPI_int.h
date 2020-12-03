/*
 * SPI_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

#define SPI_ENABLE  1
#define SPI_DISABLE 0
#define SPI_INTERRUPT    		SPI_ENABLE
#define MASTER_MODE 1
#define SLAVE_MODE  0
#define SPI_MODE       			MASTER_MODE
#define IDLE_HIGH	1
#define IDLE_LOW 	0
#define CLK_POLARITY 			IDLE_HIGH
#define SAMPLE_AT_LEADING	1
#define SAMPLE_AT_TRAILING	0
#define CLK_PHASE		 		SAMPLE_AT_TRAILING
#define LSB_TRANSIMITT_FIRST 1
#define MSP_TRANSIMITT_FIRST 0
#define DATA_ORDER 				MSP_TRANSIMITT_FIRST
#define FOSC_2		0
#define FOSC_4		1
#define FOSC_8		2
#define FOSC_16		3
#define FOSC_32		4
#define FOSC_64	 	5
#define FOSC_182	6
#define SPI_CLK				 	FOSC_16

void SPI_vidInit(void);
void SPI_vidTransmitter(u8 u8DataCPY);
//void SPI_vidSlaveInit(void);
u8 SPI_u8Receiver(void);
void SPI_vidState(u8 u8StateCPY);
void SPI_vidModeSlect(u8 u8ModeCPY);



#endif /* SPI_INT_H_ */
