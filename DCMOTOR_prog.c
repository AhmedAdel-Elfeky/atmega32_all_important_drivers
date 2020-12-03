/*
 * DCMOTOR_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#include "std_types.h"
#include "DCMOTOR_int.h"
#include "DIO_int.h"


void DC_MOTOR_vidMotorOperation(u8 u8State)
{
	switch(u8State)
		{
		case RIGHT_TURN:
			{
				DIO_vidSetPinValue(DC_MOTOR_PORT,RIGHT_PIN,1);
				DIO_vidSetPinValue(DC_MOTOR_PORT,LEFT_PIN,0);
				break;
			}
		case LEFT_TURN:
			{
				DIO_vidSetPinValue(DC_MOTOR_PORT,RIGHT_PIN,0);
				DIO_vidSetPinValue(DC_MOTOR_PORT,LEFT_PIN,1);
				break;
			}
		case STOP_TURN:
			{
				DIO_vidSetPinValue(DC_MOTOR_PORT,RIGHT_PIN,0);
				DIO_vidSetPinValue(DC_MOTOR_PORT,LEFT_PIN,0);
				break;
			}

		}
	return;
}
