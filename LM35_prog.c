/*
 * LM35.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */
#include "std_types.h"
#include "ADC_int.h"
#include "LM35_int.h"



u8 LM35_u8GetTemperature_Digital(u8 u8ChannelCPY)
{
	u8 u8TemperatureLOC;
	u8TemperatureLOC= ADC_u8GetADCReading(u8ChannelCPY);
	return u8TemperatureLOC;
}



