/*
 * KEYBAD_PRG.c
 *
 *  Created on: Oct 28, 2021
 *      Author: Ahmed Ehab
 */

#include"LIB\stdtypes.h"
#include"LIB\bitmath.h"

#include "../../MCAL/DIO/DIO_INT.h"

#include"KEYBAD_CONFIG.h"
#include"KEYBAD_INT.h"

u8 KEYBAD_u8Init(void)
{
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_ROW_0,INPUT);
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_ROW_1,INPUT);
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_ROW_2,INPUT);
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_ROW_3,INPUT);
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_COLUMN_0,OUTPUT);
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_COLUMN_1,OUTPUT);
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_COLUMN_2,OUTPUT);
	DIO_u8SetPinDir(KEYBAD_PORT,KEYBAD_COLUMN_3,OUTPUT);
	DIO_u8SetPortVal(KEYBAD_PORT,FULL_HIGH);
}
u8 KEYBAD_u8GetPressedButton(void)
{
	u8 Local_u8PressedKey=NO_PRESSED_KEY;
	u8 Local_u8ColumnIndex,Local_u8RowIndex,Local_u8PinState;
	static u8 LOCAL_u8KEYBAD_ARRAY[RowNum][ColumnNum]=KEYPAD_ARR;
	static u8 Local_u8KeybadRowArr[RowNum]={KEYBAD_ROW_0,KEYBAD_ROW_1,KEYBAD_ROW_2,KEYBAD_ROW_3};
	static u8 Local_u8KeybadColumnArr[ColumnNum]={KEYBAD_COLUMN_0,KEYBAD_COLUMN_1,KEYBAD_COLUMN_2,KEYBAD_COLUMN_3};;
	for(Local_u8ColumnIndex=0;Local_u8ColumnIndex<ColumnNum;Local_u8ColumnIndex++)
	{
		DIO_u8SetPinVal(KEYBAD_PORT,Local_u8KeybadColumnArr[Local_u8ColumnIndex],LOW);
		for(Local_u8RowIndex=0;Local_u8RowIndex<RowNum;Local_u8RowIndex++)
		{
			DIO_u8GetPinVal(KEYBAD_PORT,Local_u8KeybadRowArr[Local_u8RowIndex],&Local_u8PinState);
			if(Local_u8PinState==LOW)
			{
				Local_u8PressedKey=LOCAL_u8KEYBAD_ARRAY[Local_u8RowIndex][Local_u8ColumnIndex];
				while(Local_u8PinState==LOW)
				{
					DIO_u8GetPinVal(KEYBAD_PORT,Local_u8KeybadRowArr[Local_u8RowIndex],&Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		DIO_u8SetPinVal(KEYBAD_PORT,Local_u8KeybadColumnArr[Local_u8ColumnIndex],HIGH);
	}
	return Local_u8PressedKey;
}
