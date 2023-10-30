/*
 * PRG.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Ahmed Ehab
 */
#include "LIB/stdtypes.h"
#include "../../MCAL/DIO/DIO_INT.h"
#include "util/delay.h"
#include "CLCD_CONFIG.h"
#include "CLCD_INT.h"

void CLCD_vidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin low for command select*/
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);

	/*Set RW PIN to LOW to enable writing*/
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);

	/*Send command*/
	DIO_u8SetPortVal(LCD_DATA_PORT,Copy_u8Command);

	/*Enable pulse*/
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
}
void CLCD_vidSendData(u8 Copy_u8Data)
{
	/*Set RS pin high for data select*/
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);

	/*Set RW PIN to LOW to enable writing*/
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);

	/*Send data*/
	DIO_u8SetPortVal(LCD_DATA_PORT,Copy_u8Data);

	/*Enable pulse*/
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
}
void CLCD_vidInit(void)
{
	/*wait for more than 30 ms*/
	_delay_ms(40);

	/*send initialization command with font size and number of lines*/
	/*function for choosing 8*5 font size and 2 lines for writing*/
	CLCD_vidSendCommand(0b00111000);

	/*Display on & off control:*****DCB*/
	/*Display enable , disable cursor , disable blink cursor*/
	CLCD_vidSendCommand(0b00001100);

	/*command for clear display*/
	CLCD_vidSendCommand(0b00000001);

}
u8 CLCD_u8SendString(u8* Copy_u8String)
{
	u8 i=0;
	u8 Local_u8ErrorStatus=RT_OK;
	if( Copy_u8String==((void*)0))
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	else
	{
		/*Set RS pin low for command select*/
		DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);

		/*Set RW PIN to LOW to enable writing*/
		DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);

		/*Send command*/
		while(Copy_u8String[i]!='\0')
		{
			DIO_u8SetPortVal(LCD_DATA_PORT,Copy_u8String[i]);
			/*Enable pulse*/
			DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
			_delay_ms(2);
			DIO_u8SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
			i++;
		}
	}
	return Local_u8ErrorStatus;
}
u8 CLCD_u8GOTOXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8ErrorStatus=RT_OK,Local_u8Address=0x00;
	switch (Copy_u8XPos)
	{
	case 0:
		Local_u8Address=Copy_u8YPos;
		break;
	case 1:
		Local_u8Address=0x40+Copy_u8YPos;
		break;
	default:
		Local_u8ErrorStatus=RT_NOK;
		break;
	}
	CLCD_vidSendCommand(Local_u8Address|=(1<<7));
	return Local_u8ErrorStatus;
}
u8 CLCD_u8WriteSpecialCharacter(u8* Copy_u8Character,u8 Copy_u8CharNum,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8ErrorStatus=RT_OK,Local_u8Address=((Copy_u8CharNum*8)|(1<<6));
	if(Copy_u8CharNum<=7)
	{
		CLCD_vidSendCommand(Local_u8Address);
		for(u8 i=0;i<=7;i++)
		{
			CLCD_vidSendData(Copy_u8Character[i]);
		}
		Local_u8ErrorStatus=CLCD_u8GOTOXY(Copy_u8XPos,Copy_u8YPos);
		CLCD_vidSendData(Copy_u8CharNum);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
void CLCD_vidWriteInteger(u32 Copy_u32Number)
{
	u8 i=9,temp=0,Num[10]={0};
	while(Copy_u32Number>0)
	{
		Num[i]=Copy_u32Number%10;
		Copy_u32Number/=10;
		i--;
	}
	i++;
	for(;i<=9;i++)
	{
		CLCD_vidSendData(48+Num[i]);
	}
}
u8 CLCD_u8WriteFloat(f32 Copy_f32Number)
{
	u8 i=9,temp=0,Num[10]={0},FloatingNum[7]={0};
	u32 Copy_u32Num=Copy_f32Number,Copy_u32temp;
	Copy_u32temp=((Copy_f32Number*10000000)-(Copy_u32Num*10000000));
	CLCD_vidWriteInteger(Copy_u32Num);
	i=6;
	while(Copy_u32temp>0)
	{
		FloatingNum[i]=Copy_u32temp%10;
		Copy_u32temp/=10;
		i--;
	}
	CLCD_vidSendData('.');
	for(i=0;i<=6;i++)
	{
		if(FloatingNum[i]==0)
		{
			temp=0;
			for(u8 k=i;k<=6;k++)
			{
				if(FloatingNum[k]!=0)
				{
					temp=1;
				}
			}
		}
		else
		{
			temp=1;
		}
		if(temp==1)
		{
			CLCD_vidSendData(48+FloatingNum[i]);
		}
	}
}
void CLCD_vidClearDisplay(void)
{
	CLCD_vidSendCommand(0b00000001);
}
