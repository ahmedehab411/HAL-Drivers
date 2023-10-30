/*
 * KEYBAD_CONFIG.h
 *
 *  Created on: Oct 28, 2021
 *      Author: Ahmed Ehab
 */

#ifndef KEYBAD_CONFIG_H_
#define KEYBAD_CONFIG_H_

#define KEYBAD_PORT DIO_PORTD
#define NO_PRESSED_KEY 20

#define ColumnNum 4
#define RowNum 4
#define KEYPAD_ARR {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'c',0,'=','+'}}

#define KEYBAD_ROW_0 DIO_PIN0
#define KEYBAD_ROW_1 DIO_PIN1
#define KEYBAD_ROW_2 DIO_PIN2
#define KEYBAD_ROW_3 DIO_PIN3
#define KEYBAD_COLUMN_0 DIO_PIN4
#define KEYBAD_COLUMN_1 DIO_PIN5
#define KEYBAD_COLUMN_2 DIO_PIN6
#define KEYBAD_COLUMN_3 DIO_PIN7

#endif /* KEYBAD_CONFIG_H_ */
