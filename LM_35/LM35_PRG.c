/*
 * LM35_PRG.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Ahmed Ehab
 */


#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/ADC/ADC_INT.h"

#include "LM35_INT.h"

u8 LM35_u8GetReading(DIO_PIN PinNo,f32* Temp)
{
	u8 Local_u8ErrorStatus=RT_OK;
	u16 Val;
	if(PinNo>=DIO_PIN0 && PinNo<=DIO_PIN7)
	{
		Local_u8ErrorStatus=ADC_u8GetDigitalRead (PinNo, ADC_SINGLE_CONVERSION, &Val);
		*Temp=Val*500/1023;

	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
