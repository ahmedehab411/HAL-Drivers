/*
 * POT_PRG.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Ahmed Ehab
 */


#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/ADC/ADC_INT.h"

#include "POT_INT.h"

u8 POT_u8GetVal(DIO_PIN PinNo,u16 *Val)
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(PinNo>=DIO_PIN0 && PinNo<=DIO_PIN7)
	{
		Local_u8ErrorStatus=ADC_u8GetDigitalRead (PinNo, ADC_SINGLE_CONVERSION, Val);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
