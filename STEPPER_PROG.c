/*
 * STEPPER_PROG.C
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#include "std_types.h"
#include "DIO_int.h"
#include "util/delay.h"
#include "STEPPER_INT.h"
#define ENABLE 1
#define DISABLE 0

void STP_vidStepperOperation(u8 u8StateCPY,u8 u8DirectionCPY, u8 u8AngleCPY ,u8 u8SpeedCPY)
{
	u8 u8TurnLOC=0;
	switch(u8StateCPY)
	{
		case ENABLE:
		{
			switch(u8DirectionCPY)
			{
				case CLKWISE:
				{
					switch(u8AngleCPY)
					{
						case 45:
						{
							for(u8TurnLOC=0;u8TurnLOC<=32;u8TurnLOC++)
							{
							DIO_vidSetPinValue(STP_PORT,PINK,1);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,1);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,1);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,1);
							_delay_ms(u8SpeedCPY);
							}
							break;
						}
						case 90:
						{
							for(u8TurnLOC=0;u8TurnLOC<=64;u8TurnLOC++)
							{
							DIO_vidSetPinValue(STP_PORT,PINK,1);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
						    _delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,1);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,1);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,1);
							_delay_ms(u8SpeedCPY);
							}
							break;
						}
						default:
						{
							break;
						}
					}
					break;
				}
				case ANTI_CLKWISE:
				{
					switch(u8AngleCPY)
					{
						case 45:
						{
							for(u8TurnLOC=0;u8TurnLOC<=32;u8TurnLOC++)
							{
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,1);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,1);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,1);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,1);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							}
							break;
						}
						case 90:
						{
							for(u8TurnLOC=0;u8TurnLOC<=64;u8TurnLOC++)
							{
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,1);
						    _delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,1);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,0);
							DIO_vidSetPinValue(STP_PORT,YELLOW,1);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							DIO_vidSetPinValue(STP_PORT,PINK,1);
							DIO_vidSetPinValue(STP_PORT,YELLOW,0);
							DIO_vidSetPinValue(STP_PORT,ORANGE,0);
							DIO_vidSetPinValue(STP_PORT,BLUE,0);
							_delay_ms(u8SpeedCPY);
							}
							break;
						}
						default:
							{
							break;
							}
					}
					break;
				}
				default:
				{
					break;
				}
			}
			break;
		}
		case DISABLE:
		{
			DIO_vidSetPinValue(STP_PORT,PINK,0);
			DIO_vidSetPinValue(STP_PORT,YELLOW,0);
			DIO_vidSetPinValue(STP_PORT,ORANGE,0);
			DIO_vidSetPinValue(STP_PORT,BLUE,0);
			break;
		}
		default:
		{
			DIO_vidSetPinValue(STP_PORT,PINK,0);
			DIO_vidSetPinValue(STP_PORT,YELLOW,0);
			DIO_vidSetPinValue(STP_PORT,ORANGE,0);
			DIO_vidSetPinValue(STP_PORT,BLUE,0);
			break;
		}
	}

	return;
}
