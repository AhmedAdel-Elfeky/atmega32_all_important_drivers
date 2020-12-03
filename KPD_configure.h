/*
 * PROCESS.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef KPD_CONFIGURE_H_
#define KPD_CONFIGURE_H_



	    DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,0,INPUT); //R1 input
		DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,1,INPUT); //R2 input
		DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,2,INPUT); //R3 input
		DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,3,INPUT);
		DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,4,OUTPUT);  //C4 output
		DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,5,OUTPUT);
		DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,6,OUTPUT);
		DIO_vidSetPinDirection(KPD_u8CONNECTED_PORT,7,OUTPUT);  //C1 output

		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,0,HIGH); //R1 pullup resistor
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,1,HIGH);
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,2,HIGH);
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,3,HIGH);
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,4,LOW); //low
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,5,LOW);
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,6,LOW);
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,7,LOW);

#endif /* KPD_CONFIGURE_H_ */
