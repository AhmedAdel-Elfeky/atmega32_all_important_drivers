/*
 * GLCD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "utils.h"
#include "DIO_int.h"
#include "GLCD_int.h"
#include <util/delay.h>
#define F_CPU 12000000
/*
u8 H[6]={0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00};
u8 E[6]={0x7F, 0x49, 0x49, 0x49, 0x41, 0x00};
u8 L[6]={0x7F, 0x40, 0x40, 0x40, 0x40, 0x00};
u8 O[6]={0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00};
u8 W[6]={0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00};
u8 R[6]={0x7F, 0x09, 0x19, 0x29, 0x46, 0x00};
u8 D[6]={0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00};
*/

u8 N1[6]={0x00,0x42, 0x7f, 0x40, 0x00, 0x00};
u8 N0[6]={0x3E,0x51, 0x49, 0x45, 0x3E, 0x00};
u8 N2[6]={0x42,0x61, 0x51, 0x49, 0x46, 0x00};
u8 N3[6]={0x21,0x41, 0x45, 0x4B, 0x31, 0x00};
u8 N4[6]={0x18,0x14, 0x12, 0x7F, 0x10, 0x00};
u8 N5[6]={0x27,0x45, 0x45, 0x45, 0x39, 0x00};
u8 N6[6]={0x3C,0x4A, 0x49, 0x49, 0x30, 0x00};
u8 N7[6]={0x01,0x71, 0x09, 0x05, 0x03, 0x00};
u8 N8[6]={0x36,0x49, 0x49, 0x49, 0x36, 0x00};
u8 N9[6]={0x06,0x49, 0x49, 0x29, 0x1E, 0x00};

/* write Command */
void GLCD_vidWriteCommand(u8 u8CommandCPY)
{
	DIO_vidSetPortValue(GLCD_DATA_PORT,u8CommandCPY);
	DIO_vidSetPinValue(GLCD_RS_CTRL_PORT,GLCD_RS_CTRL_PIN,LOW);
	DIO_vidSetPinValue(GLCD_RW_CTRL_PORT,GLCD_RW_CTRL_PIN,LOW);
	DIO_vidSetPinValue(GLCD_E_CTRL_PORT,GLCD_E_CTRL_PIN,HIGH);
	_delay_us(100);
	DIO_vidSetPinValue(GLCD_E_CTRL_PORT,GLCD_E_CTRL_PIN,LOW);
	_delay_us(1000);
	return;
}

/* write data */
void GLCD_vidWriteData(u8 u8DataCPY)
{

	DIO_vidSetPortValue(GLCD_DATA_PORT,u8DataCPY);
	DIO_vidSetPinValue(GLCD_RS_CTRL_PORT,GLCD_RS_CTRL_PIN,HIGH);
	DIO_vidSetPinValue(GLCD_RW_CTRL_PORT,GLCD_RW_CTRL_PIN,LOW);
	DIO_vidSetPinValue(GLCD_E_CTRL_PORT,GLCD_E_CTRL_PIN,HIGH);
	_delay_us(100);
	DIO_vidSetPinValue(GLCD_E_CTRL_PORT,GLCD_E_CTRL_PIN,LOW);
	_delay_us(1000);
	return;
}

/*select page1 or page 2 */
void GLCD_vidXPageSelect(u8 u8XPageCPY)
{
	switch(u8XPageCPY)
	{
	case GLCD_CS1 :
	{
		DIO_vidSetPinValue(GLCD_CS1_CTRL_PORT,GLCD_CS1_CTRL_PIN,HIGH);
		DIO_vidSetPinValue(GLCD_CS2_CTRL_PORT,GLCD_CS2_CTRL_PIN,LOW);
		break;
	}
	case GLCD_CS2 :
	{
		DIO_vidSetPinValue(GLCD_CS1_CTRL_PORT,GLCD_CS1_CTRL_PIN,LOW);
		DIO_vidSetPinValue(GLCD_CS2_CTRL_PORT,GLCD_CS2_CTRL_PIN,HIGH);
		break;
	}
	}
}

/* display character */
void GLCD_vidDisplayCharacter(u8 *CharPtr)
{
	u8 u8ColCounterLOC=0;
	for (u8ColCounterLOC=0 ; u8ColCounterLOC<6 ; u8ColCounterLOC++)
	{
		GLCD_vidWriteData(CharPtr[u8ColCounterLOC]);
	}
	return;
}

/* display word */
void GLCD_vidDisplayWord(u8** WordPtr,u8 u8SizeOfWord)
{
	for(u8 i=0;i<u8SizeOfWord;i++)
	{
		GLCD_vidDisplayCharacter(WordPtr[i]);
	}
}

/* clear the display All pixels are off  */
void GLCD_vidClearALL(void)
{
	GLCD_vidXPageSelect(GLCD_CS1);
	GLCD_vidGoToLine(LINE_0);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_1);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_2);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_3);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_4);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_5);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_6);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_7);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}

	GLCD_vidXPageSelect(GLCD_CS2);
	GLCD_vidGoToLine(LINE_0);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_1);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_2);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_3);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_4);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_5);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_6);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}
	GLCD_vidGoToLine(LINE_7);
	GLCD_vidSetYaddress(0);
	for(u8 i=0;i<64;i++)
	{
		GLCD_vidWriteData(0);
	}

	return;
}

/* initialize the glcd */
void GLCD_vidInitialize(void)
{
	/* display pg1/2 */
	GLCD_vidXPageSelect(GLCD_CS1);
	GLCD_vidWriteCommand(GLCD_DISPLAY_ON_CM);
	GLCD_vidXPageSelect(GLCD_CS2);
	GLCD_vidWriteCommand(GLCD_DISPLAY_ON_CM);
	_delay_us(100);

	/* enable pg1/2 */
	GLCD_vidXPageSelect(GLCD_CS1);
	GLCD_vidSetStartLine(0);
	GLCD_vidXPageSelect(GLCD_CS2);
	GLCD_vidSetStartLine(0);
	_delay_us(100);
	GLCD_vidClearALL();

	return;
}

/* Got to the line(0----7) */
void GLCD_vidGoToLine(u8 u8LineCPY)
{
	u8 u8LineAddressLOC;
	switch(u8LineCPY)
	{
	case LINE_0:
	{
		u8LineAddressLOC = 0xB8;
		break;
	}
	case LINE_1:
	{
		u8LineAddressLOC = 0xB9;
		break;
	}
	case LINE_2:
	{
		u8LineAddressLOC = 0xBA;
		break;
	}
	case LINE_3:
	{
		u8LineAddressLOC = 0xBB;
		break;
	}
	case LINE_4:
	{
		u8LineAddressLOC = 0xBC;
		break;
	}
	case LINE_5:
	{
		u8LineAddressLOC = 0xBD;
		break;
	}
	case LINE_6:
	{
		u8LineAddressLOC = 0xBE;
		break;
	}
	case LINE_7:
	{
		u8LineAddressLOC = 0xBF;
		break;
	}
	default:
	{
		u8LineAddressLOC = 0xB8;
		break;
	}
	}
	GLCD_vidWriteCommand(u8LineAddressLOC);
	return;
}

/* set the column */
void GLCD_vidSetYaddress(u8 u8AddressCPY)
{
	if(u8AddressCPY < 64)
	{
		GLCD_vidWriteCommand(u8AddressCPY | (0x40));
	}
	else{}
	return;
}

/* set start line of display */
void GLCD_vidSetStartLine(u8 u8LineCPY)
{
	if(u8LineCPY < 64)
	{
		GLCD_vidWriteCommand(u8LineCPY | (0xC0));
	}
	else{}
	return;
}

/* Got to a specific dot to write */
void GLCD_vidGoTo(u8 u8PageSelCPY,u8 u8LineCPY,u8 u8ColmCPY)
{
	GLCD_vidXPageSelect(u8PageSelCPY);
	GLCD_vidGoToLine(u8LineCPY);
	GLCD_vidSetYaddress(u8ColmCPY);
	return;
}

/* Display a numeric value like y=54 */
void GLCD_vidDisplayNumber(u32 u32NumberCPY)
 {
	 u32 u32CopyNumLOC;
	 u8 u8LenghtLOC=0 , arr[10]={0} ;
	 s8 i;
	 u32CopyNumLOC=u32NumberCPY;
	 if(u32NumberCPY==0)
	 {
		 GLCD_vidDisplayCharacter(N0);
	 }
	 else
	 {
		 while(u32CopyNumLOC != 0)
		 {
			 u8LenghtLOC++;
			 u32CopyNumLOC/=10;
		 }
		 for(i=0;i<u8LenghtLOC;i++)
		 {
			 arr[i] = u32NumberCPY % 10;
			 u32NumberCPY/=10;
		 }
		 for(i=u8LenghtLOC-1;i>=0;i--)
		 {
			 switch(arr[i])
			 {
			 case 0:
			 {
				 GLCD_vidDisplayCharacter(N0);
				 break;
			 }
			 case 1:
			 {
				 GLCD_vidDisplayCharacter(N1);
				 break;
			 }
			 case 2:
			 {
				 GLCD_vidDisplayCharacter(N2);
				 break;
			 }
			 case 3:
			 {
				 GLCD_vidDisplayCharacter(N3);
				 break;
			 }
			 case 4:
			 {
				 GLCD_vidDisplayCharacter(N4);
				 break;
			 }
			 case 5:
			 {
				 GLCD_vidDisplayCharacter(N5);
				 break;
			 }
			 case 6:
			 {
				 GLCD_vidDisplayCharacter(N6);
				 break;
			 }
			 case 7:
			 {
				 GLCD_vidDisplayCharacter(N7);
				 break;
			 }
			 case 8:
			 {
				 GLCD_vidDisplayCharacter(N8);
				 break;
			 }
			 case 9:
			 {
				 GLCD_vidDisplayCharacter(N9);
				 break;
			 }
			 default:{break;}
			 }
	 }
	 }
	 return;
 }




