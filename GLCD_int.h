/*
 * GLCD_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef GLCD_INT_H_
#define GLCD_INT_H_
/**************************************configurations*********************************/
#define GLCD_DATA_PORT      PORT_C

#define GLCD_E_CTRL_PORT    PORT_A
#define GLCD_E_CTRL_PIN     PIN_5

#define GLCD_RW_CTRL_PORT   PORT_A
#define GLCD_RW_CTRL_PIN    PIN_6

#define GLCD_RS_CTRL_PORT   PORT_A
#define GLCD_RS_CTRL_PIN    PIN_7

#define GLCD_CS1_CTRL_PORT  PORT_A
#define GLCD_CS1_CTRL_PIN   PIN_4

#define GLCD_CS2_CTRL_PORT  PORT_A
#define GLCD_CS2_CTRL_PIN   PIN_3
/************************************************************************************/
#define GLCD_DISPLAY_ON_CM  0x3f
#define GLCD_DISPLAY_OFF_CM 0x3E

#define LINE_0 0
#define LINE_1 1
#define LINE_2 2
#define LINE_3 3
#define LINE_4 4
#define LINE_5 5
#define LINE_6 6
#define LINE_7 7

#define GLCD_CS1 1
#define GLCD_CS2 2

extern u8 N1[6];
extern u8 N0[6];
extern u8 N2[6];
extern u8 N3[6];
extern u8 N4[6];
extern u8 N5[6];
extern u8 N6[6];
extern u8 N7[6];
extern u8 N8[6];
extern u8 N9[6];
void GLCD_vidWriteCommand(u8 u8CommandCPY);
void GLCD_vidWriteData(u8 u8DataCPY);
void GLCD_vidXPageSelect(u8 u8XPageCPY);
void GLCD_vidDisplayCharacter(u8 *CharPtr);
void GLCD_vidInitialize(void);
void GLCD_vidGoToLine(u8 u8LineCPY);
void GLCD_vidSetYaddress(u8 u8AddressCPY);
void GLCD_vidClearALL(void);
void GLCD_vidSetStartLine(u8 u8LineCPY);
void GLCD_vidGoTo(u8 u8PageSelCPY,u8 u8LineCPY,u8 u8ColmCPY);
void GLCD_vidDisplayWord(u8** WordPtr,u8 u8SizeOfWord);
void GLCD_vidDisplayNumber(u32 u32NumberCPY);





#endif /* GLCD_INT_H_ */
