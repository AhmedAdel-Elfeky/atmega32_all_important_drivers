/*
 * Key_pad_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#include "std_types.h"
#include "DIO_int.h"
#include "KPD_int.h"


#define u8COL_START ((u8)4)
#define u8COL_END ((u8)8)
#define u8ROW_START ((u8)0)
#define u8ROW_END ((u8)4)


const static u8 kau8KeyMapping[4][4]=
{
		{1,2,3,'A'},
		{4,5,6,'B'},
		{7,8,9,'C'},
		{'*',0,'#','D'}
};

u8 KPD_u8GetPressedKey(void)
{
	u8 u8ColCtrLoc;
	u8 u8RowCtrLoc;

	u8 u8PressedKeyLoc = u8NOT_PRESSED;

	for(u8ColCtrLoc= u8COL_START ; u8ColCtrLoc < u8COL_END ;u8ColCtrLoc++)
	{
		DIO_vidSetPinValue( KPD_u8CONNECTED_PORT, u8ColCtrLoc ,LOW);
		for(u8RowCtrLoc=u8ROW_START ; u8RowCtrLoc <u8ROW_END ; u8RowCtrLoc++ )
		{
			if(DIO_u8GetPinValue(KPD_u8CONNECTED_PORT,u8RowCtrLoc)==LOW)
			{
				u8PressedKeyLoc=kau8KeyMapping[u8RowCtrLoc-u8ROW_START][u8ColCtrLoc-u8COL_START];
				while(DIO_u8GetPinValue(KPD_u8CONNECTED_PORT,u8RowCtrLoc)==0);

			}else{}
		}
		DIO_vidSetPinValue(KPD_u8CONNECTED_PORT,u8ColCtrLoc,HIGH);
	}



	return u8PressedKeyLoc;
}

