/*
 * _7seg_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "DIO_int.h"
#include "sevenseg_int.h"

#define ALL_OUTPUT 255

void SEVENSEG_vidDisplay7 (u8 u8DataPortCPY,u8 u8NumCPY )
{
    DIO_vidSetPortValue(u8DataPortCPY,ALL_OUTPUT);
    switch(u8NumCPY)
    {
        case 0:
        {
        	DIO_vidSetPortValue(u8DataPortCPY,0b0100000 );
        	break;
        }
        case 1:
        {
        	DIO_vidSetPortValue(u8DataPortCPY,0b1111001 );
        	break;
        }
        case 2:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b1000100 );
            break;
        }
        case 3:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b1010000 );
            break;

        }
        case 4:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b0011001 );
            break;
        }
        case 5:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b0010010 );
            break;
        }
        case 6:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b0000010 );
            break;

        }
        case 7:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b1111000 );
            break;

        }
        case 8:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b0000000 );
            break;

        }
        case 9:
        {
            DIO_vidSetPortValue(u8DataPortCPY,0b0010000 );
            break;

        }
        default:
        {
            DIO_vidSetPortValue(u8DataPortCPY,ALL_OUTPUT );

        }
     }
    return;
}



