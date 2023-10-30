/*
 * SERVO_PRG.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Ahmed Ehab
 */


#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"

#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/TIMER1/TIMER1_INT.h"

#include "SERVO_INT.h"
#include "SERVO_CONFIG.h"

#include "util/delay.h"
u8 SERVO_u8InitChA(void)
{
	DIO_u8SetPinDir(DIO_PORTD, DIO_PIN5, OUTPUT);
	TIMER1_u8Init(TIMER1_MODE_e_FAST_PWM_ICR1);
	TIMER1_vidSetICRValue((u16)20000);
	TIMER1_u8ClkSelect(TIMER1_CLK_SELECT_e_PRE_8);
	TIMER1_vidSetFastPwmMode(2, TIMER1_CHANNEL_e_CHANNEL_A);
}
u8 SERVO_u8InitChB(void)
{
	DIO_u8SetPinDir(DIO_PORTD, DIO_PIN4, OUTPUT);
	TIMER1_u8Init(TIMER1_MODE_e_FAST_PWM_ICR1);
	TIMER1_vidSetICRValue((u16)20000);
	TIMER1_u8ClkSelect(TIMER1_CLK_SELECT_e_PRE_8);
	TIMER1_vidSetFastPwmMode(2, TIMER1_CHANNEL_e_CHANNEL_B);
}

u8 SERVO_u8SetAngleChA (f32 Copy_u8Angle)
{
	u8 Local_u8ErrStatus=RT_OK;
	u16 TempOCR1A=0;
	if(Copy_u8Angle<=ServoMaxAngle && Copy_u8Angle>=ServoMinAngle)
	{
		u16 Temp=SERVO_UPPER_LIMIT-SERVO_LOWER_LIMIT;
		TempOCR1A=SERVO_LOWER_LIMIT+(u16)((Copy_u8Angle*Temp)/180);
	}
	OCR1A_REG=TempOCR1A;
}

u8 SERVO_u8SetAngleChB (f32 Copy_u8Angle)
{
	u8 Local_u8ErrStatus=RT_OK;
	u16 TempOCR1B=0;
	if(Copy_u8Angle<=ServoMaxAngle && Copy_u8Angle>=ServoMinAngle)
	{
		u16 Temp=SERVO_UPPER_LIMIT-SERVO_LOWER_LIMIT;
		TempOCR1B=SERVO_LOWER_LIMIT+(u16)((Copy_u8Angle*Temp)/180);
		OCR1B_REG=TempOCR1B;
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}

u8 SERVO_u8SmoothOpenChA (f32 Copy_u8Angle)
{
	u8 Local_u8ErrStatus=RT_OK;
	u16 TempOCR1A=0;
	if(Copy_u8Angle<=ServoMaxAngle && Copy_u8Angle>=ServoMinAngle)
	{
		u16 Temp=SERVO_UPPER_LIMIT-SERVO_LOWER_LIMIT;
		TempOCR1A=SERVO_LOWER_LIMIT+(u16)((Copy_u8Angle*Temp)/180);
		for(int i=SERVO_LOWER_LIMIT;i<=TempOCR1A;i+=5)
		{
			OCR1A_REG=i;
			_delay_ms(20);
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}

u8 SERVO_u8SmoothCloseChA (f32 Copy_u8Angle)
{
	u8 Local_u8ErrStatus=RT_OK;
	u16 TempOCR1A=0;
	if(Copy_u8Angle<=ServoMaxAngle && Copy_u8Angle>=ServoMinAngle)
	{
		u16 Temp=SERVO_UPPER_LIMIT-SERVO_LOWER_LIMIT;
		TempOCR1A=SERVO_LOWER_LIMIT+(u16)((Copy_u8Angle*Temp)/180);
		Temp=OCR1A_REG;
		for(int i=Temp;i>=TempOCR1A;i-=5)
		{
			OCR1A_REG=i;
			_delay_ms(20);
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}

u8 SERVO_u8SmoothOpenChB (f32 Copy_u8Angle)
{
	u8 Local_u8ErrStatus=RT_OK;
	u16 TempOCR1B=0;
	if(Copy_u8Angle<=ServoMaxAngle && Copy_u8Angle>=ServoMinAngle)
	{
		u16 Temp=SERVO_UPPER_LIMIT-SERVO_LOWER_LIMIT;
		TempOCR1B=SERVO_LOWER_LIMIT+(u16)((Copy_u8Angle*Temp)/180);
		for(int i=SERVO_LOWER_LIMIT;i<=TempOCR1B;i+=5)
		{
			OCR1B_REG=i;
			_delay_ms(20);
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}

u8 SERVO_u8SmoothCloseChB (f32 Copy_u8Angle)
{
	u8 Local_u8ErrStatus=RT_OK;
	u16 TempOCR1B=0;
	if(Copy_u8Angle<=ServoMaxAngle && Copy_u8Angle>=ServoMinAngle)
	{
		u16 Temp=SERVO_UPPER_LIMIT-SERVO_LOWER_LIMIT;
		TempOCR1B=SERVO_LOWER_LIMIT+(u16)((Copy_u8Angle*Temp)/180);
		Temp=OCR1B_REG;
		for(int i=Temp;i>=TempOCR1B;i-=5)
		{
			OCR1B_REG=i;
			_delay_ms(20);
		}
	}
	else
	{
		Local_u8ErrStatus=RT_NOK;
	}
	return Local_u8ErrStatus;
}
