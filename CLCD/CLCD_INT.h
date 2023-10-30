/*
 * INT.h
 *
 *  Created on: Oct 6, 2021
 *      Author: Ahmed Ehab
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_
#include "CLCD_CONFIG.h"
void CLCD_vidSendCommand(u8 Copy_u8Command);

void CLCD_vidSendData(u8 Copy_u8Data);

void CLCD_vidInit(void);

u8 CLCD_u8SendString(u8* Copy_u8String);

u8 CLCD_u8GOTOXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

u8 CLCD_u8WriteSpecialCharacter(u8* Copy_u8Character,u8 Copy_u8CharNum,u8 Copy_u8XPos,u8 Copy_u8YPos);

u8 CLCD_u8WriteFloat(f32 Copy_u8Number);

void CLCD_vidClearDisplay(void);
#endif /* HAL_LCD_LCD_INT_H_ */
