/*
 * WDT_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef WDT_INT_H_
#define WDT_INT_H_

//#define XX (u8)100
#define _16_3ms (u8)1
#define _32_5ms (u8)2
#define _65ms   (u8)3
#define __13s   (u8)4
#define __26s   (u8)5
#define __52s   (u8)6
#define _1s     (u8)7
#define _2_1s   (u8)8

void WDT_vidEnable_5V(u8 u8ResetTimeCPY);
void WDT_vidDisable_5V(void);

#endif /* WDT_INT_H_ */
