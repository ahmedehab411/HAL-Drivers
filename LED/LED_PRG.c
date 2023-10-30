/*
 * LED_PRG.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Ahmed Ehab
 */

#include"LIB\stdtypes.h"
#include"LIB\bitmath.h"
#include"util/delay.h"

#include"../../MCAL/DIO/DIO_INT.h"
#include"LED_INT.h"
u8 LED_u8InitLed(DIO_PORT PortNo,DIO_PIN PinNo)
{
	u8 Local_u8ErrorStatus=RT_OK;
	Local_u8ErrorStatus=DIO_u8SetPinDir(PortNo,PinNo,OUTPUT);
	return Local_u8ErrorStatus;
}
u8 LED_u8ToggleLed(DIO_PORT PortNo,DIO_PIN PinNo)
{
	u8 Local_u8ErrorStatus=RT_OK;
	u8 x=0;
	Local_u8ErrorStatus=DIO_u8GetPinVal(PortNo,PinNo,&x);
	Local_u8ErrorStatus=DIO_u8SetPinVal(PortNo,PinNo,!x);
	return Local_u8ErrorStatus;
}
u8 LED_u8BlinkLed(DIO_PORT PortNo,DIO_PIN PinNo,u16 Delay)
{
	u8 Local_u8ErrorStatus=RT_OK;
	Local_u8ErrorStatus=DIO_u8SetPinVal(PortNo,PinNo,HIGH);
	_delay_ms(Delay);
	Local_u8ErrorStatus=DIO_u8SetPinVal(PortNo,PinNo,LOW);
	_delay_ms(Delay);
}
u8 LED_u8SetState(DIO_PORT PortNo,DIO_PIN PinNo,u8 State)
{
	u8 Local_u8ErrorStatus=RT_OK;
	Local_u8ErrorStatus=DIO_u8SetPinVal(PortNo,PinNo,State);
	return Local_u8ErrorStatus;
}
