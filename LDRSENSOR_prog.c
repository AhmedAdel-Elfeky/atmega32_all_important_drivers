/*
 * LDRSENSOR_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "ADC_int.h"
#include "LDRSENSOR_int.h"



u8 LDR_u8GetLdrReading_Digital(u8 u8ChannelCPY)
{
	u8 LdrReadingLOC;
	LdrReadingLOC= ADC_u8GetADCReading(u8ChannelCPY);
	return LdrReadingLOC;
}

