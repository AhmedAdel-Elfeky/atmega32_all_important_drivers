/*
 * WDT_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "WDT_int.h"
#include "utils.h"

#define WDTCR  *((volatile u8*)0x41)


void WDT_vidEnable_5V(u8 u8ResetTimeCPY)
{
	WDTCR=0b00001000; //enable Watchdog
	switch(u8ResetTimeCPY)
	{
		case _16_3ms:
		{
			RESETBIT(WDTCR,0);
			RESETBIT(WDTCR,1);
			RESETBIT(WDTCR,2);
			break;
		}
		case _32_5ms:
		{
			SETBIT(WDTCR,0);
			RESETBIT(WDTCR,1);
			RESETBIT(WDTCR,2);
			break;
		}
		case _65ms:
		{
			RESETBIT(WDTCR,0);
			SETBIT(WDTCR,1);
			RESETBIT(WDTCR,2);
			break;
		}
		case __13s:
		{
			SETBIT(WDTCR,0);
			SETBIT(WDTCR,1);
			RESETBIT(WDTCR,2);
			break;
		}
		case __26s:
		{
			RESETBIT(WDTCR,0);
			RESETBIT(WDTCR,1);
			SETBIT(WDTCR,2);
			break;
		}
		case __52s:
		{
			SETBIT(WDTCR,0);
			RESETBIT(WDTCR,1);
			SETBIT(WDTCR,2);
			break;
		}
		case _1s:
		{
			RESETBIT(WDTCR,0);
			SETBIT(WDTCR,1);
			SETBIT(WDTCR,2);
			break;
		}
		case _2_1s:
		{
			SETBIT(WDTCR,0);
			SETBIT(WDTCR,1);
			SETBIT(WDTCR,2);
			break;
		}
		default:{break;}
	}
	return;
}

void WDT_vidDisable_5V(void)
{
	SETBIT(WDTCR,4);
	WDTCR=0;
	return;
}



