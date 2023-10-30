/*
 * CLCD_CONFIG.h
 *
 *  Created on: Oct 6, 2021
 *      Author: Ahmed Ehab
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

/*Data Port Definition*/
#define LCD_DATA_PORT DIO_PORTA

/*Control Port Definition*/
#define LCD_CONTROL_PORT DIO_PORTB

/*Control Pins Definition*/
#define LCD_RS_PIN DIO_PIN0
#define LCD_RW_PIN DIO_PIN1
#define LCD_EN_PIN DIO_PIN2

#endif /* HAL_LCD_LCD_CONFIG_H_ */
