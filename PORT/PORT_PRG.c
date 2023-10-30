/*
 * PORT_PRG.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Ahmed Ehab
 */

#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "../DIO/DIO_INT.h"

#include "PORT_INT.h"
#include "PORT_CONFIG.h"

u8 PORT_u8Init(void)
{
	u8 Local_u8ErrorStatus=RT_OK;
	/*PORT A Initialization*/
	if(PORTA_DIR_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortDir(DIO_PORTA, PORTA_DIR);
	}
	else if(PORTA_DIR_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN0, PORTA_PIN0_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN1, PORTA_PIN1_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN2, PORTA_PIN2_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN3, PORTA_PIN3_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN4, PORTA_PIN4_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN5, PORTA_PIN5_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN6, PORTA_PIN6_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTA, DIO_PIN7, PORTA_PIN7_DIR);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	if(PORTA_VAL_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortVal(DIO_PORTA, PORTA_VAL);
	}
	else if(PORTA_VAL_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN0, PORTA_PIN0_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN1, PORTA_PIN1_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN2, PORTA_PIN2_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN3, PORTA_PIN3_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN4, PORTA_PIN4_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN5, PORTA_PIN5_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN6, PORTA_PIN6_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTA, DIO_PIN7, PORTA_PIN7_VAL);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	/*PORTB Initialization*/
	if(PORTB_DIR_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortDir(DIO_PORTB, PORTB_DIR);
	}
	else if(PORTB_DIR_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN0, PORTB_PIN0_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN1, PORTB_PIN1_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN2, PORTB_PIN2_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN3, PORTB_PIN3_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN4, PORTB_PIN4_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN5, PORTB_PIN5_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN6, PORTB_PIN6_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTB, DIO_PIN7, PORTB_PIN7_DIR);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	if(PORTB_VAL_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortVal(DIO_PORTB, PORTB_VAL);
	}
	else if(PORTB_VAL_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN0, PORTB_PIN0_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN1, PORTB_PIN1_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN2, PORTB_PIN2_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN3, PORTB_PIN3_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN4, PORTB_PIN4_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN5, PORTB_PIN5_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN6, PORTB_PIN6_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTB, DIO_PIN7, PORTB_PIN7_VAL);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	/*PORTC Initialization*/
	if(PORTC_DIR_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortDir(DIO_PORTC, PORTC_DIR);
	}
	else if(PORTC_DIR_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN0, PORTC_PIN0_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN1, PORTC_PIN1_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN2, PORTC_PIN2_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN3, PORTC_PIN3_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN4, PORTC_PIN4_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN5, PORTC_PIN5_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN6, PORTC_PIN6_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTC, DIO_PIN7, PORTC_PIN7_DIR);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	if(PORTC_VAL_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortVal(DIO_PORTC, PORTC_VAL);
	}
	else if(PORTC_VAL_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN0, PORTC_PIN0_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN1, PORTC_PIN1_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN2, PORTC_PIN2_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN3, PORTC_PIN3_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN4, PORTC_PIN4_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN5, PORTC_PIN5_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN6, PORTC_PIN6_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTC, DIO_PIN7, PORTC_PIN7_VAL);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	/*PORTD Initialization*/
	if(PORTD_DIR_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortDir(DIO_PORTD, PORTD_DIR);
	}
	else if(PORTD_DIR_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN0, PORTD_PIN0_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN1, PORTD_PIN1_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN2, PORTD_PIN2_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN3, PORTD_PIN3_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN4, PORTD_PIN4_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN5, PORTD_PIN5_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN6, PORTD_PIN6_DIR);
		Local_u8ErrorStatus=DIO_u8SetPinDir(DIO_PORTD, DIO_PIN7, PORTD_PIN7_DIR);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	if(PORTD_VAL_MODE==PORT_MODE_e_FULL_PORT_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPortVal(DIO_PORTD, PORTD_VAL);
	}
	else if(PORTD_VAL_MODE==PORT_MODE_e_PIN_MODE)
	{
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN0, PORTD_PIN0_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN1, PORTD_PIN1_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN2, PORTD_PIN2_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN3, PORTD_PIN3_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN4, PORTD_PIN4_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN5, PORTD_PIN5_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN6, PORTD_PIN6_VAL);
		Local_u8ErrorStatus=DIO_u8SetPinVal(DIO_PORTD, DIO_PIN7, PORTD_PIN7_VAL);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
