/*
 * Push_Button_PRG.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Ahmed Ehab
 */

#include"LIB\stdtypes.h"
#include"LIB\bitmath.h"

#include"../../MCAL/DIO/DIO_INT.h"
#include "PUSH_BUTTON_INT.h"

u8 PUSH_BUTTON_u8Init(DIO_PORT PortNo,DIO_PIN PinNo,PULLUP PullupStatus)
{
	u8 Local_u8ErrorStatus=RT_OK;
	Local_u8ErrorStatus=DIO_u8SetPinDir(PortNo,PinNo,INPUT);
	switch(PullupStatus)
	{
		case PULLUP_DIS:
			DIO_u8SetPinVal(PortNo,PinNo,LOW);
			break;
		case PULLUP_EN:
			DIO_u8SetPinVal(PortNo,PinNo,HIGH);
			break;
		default:
			Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
u8 PUSH_BUTTON_u8GetVal(DIO_PORT PortNo,DIO_PIN PinNo,u8 *Copy_u8Reading)
{
	u8 Local_u8ErrorStatus=RT_OK;
	Local_u8ErrorStatus=DIO_u8GetPinVal(PortNo,PinNo,Copy_u8Reading);
	return Local_u8ErrorStatus;
}
