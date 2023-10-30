/*
 * PORT_CONFIG.h
 *
 *  Created on: Oct 5, 2023
 *      Author: Ahmed Ehab
 */

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*
 * Choose Operation Mode of the PORT Direction
 *
 * 		PORT_MODE_e_FULL_PORT_MODE
 * 		PORT_MODE_e_PIN_MODE
 * */
#define		PORTA_DIR_MODE		PORT_MODE_e_PIN_MODE
#define 	PORTB_DIR_MODE		PORT_MODE_e_PIN_MODE
#define 	PORTC_DIR_MODE		PORT_MODE_e_PIN_MODE
#define 	PORTD_DIR_MODE		PORT_MODE_e_PIN_MODE

/*
 * Choose Operation Mode of the PORT Value
 *
 * 		PORT_MODE_e_FULL_PORT_MODE
 * 		PORT_MODE_e_PIN_MODE
 * 		NOTE:any Custom input can be added
 * */
#define		PORTA_VAL_MODE		PORT_MODE_e_PIN_MODE
#define 	PORTB_VAL_MODE		PORT_MODE_e_PIN_MODE
#define 	PORTC_VAL_MODE		PORT_MODE_e_PIN_MODE
#define 	PORTD_VAL_MODE		PORT_MODE_e_PIN_MODE

/*
 * Setting Port Direction ("PORT_DIR_MODE 	PORT_MODE_e_FULL_PORT_MODE")
 * 		PORT_DIR_e_FULL_INPUT
 *		PORT_DIR_e_FULL_OUTPUT
 *		NOTE:any Custom input can be added
 * */
#define 	PORTA_DIR			PORT_DIR_e_FULL_INPUT
#define 	PORTB_DIR			PORT_DIR_e_FULL_INPUT
#define 	PORTC_DIR			PORT_DIR_e_FULL_INPUT
#define 	PORTD_DIR			PORT_DIR_e_FULL_INPUT

/*
 * Setting Port Value ("PORT_VAL_MODE 	PORT_MODE_e_FULL_PORT_MODE")
 * 		PORT_VAL_e_FULL_LOW
 *		PORT_VAL_e_FULL_HIGH
 *		NOTE:any Custom input can be added
 * */
#define 	PORTA_VAL			PORT_VAL_e_FULL_LOW
#define 	PORTB_VAL			PORT_VAL_e_FULL_LOW
#define 	PORTC_VAL			PORT_VAL_e_FULL_LOW
#define 	PORTD_VAL			PORT_VAL_e_FULL_LOW

/*
 * Setting Pin Direction	("PORT_DIR_MODE 	PORT_MODE_e_PIN_MODE")
 * 		PORT_DIR_e_INPUT
 *		PORT_DIR_e_OUTPUT
 *		NOTE:any Custom input can be added
 * */
/*PORTA Pins Configuration*/
#define 	PORTA_PIN0_DIR		PORT_DIR_e_INPUT
#define 	PORTA_PIN1_DIR		PORT_DIR_e_INPUT
#define 	PORTA_PIN2_DIR		PORT_DIR_e_INPUT
#define 	PORTA_PIN3_DIR		PORT_DIR_e_INPUT
#define 	PORTA_PIN4_DIR		PORT_DIR_e_INPUT
#define 	PORTA_PIN5_DIR		PORT_DIR_e_INPUT
#define 	PORTA_PIN6_DIR		PORT_DIR_e_INPUT
#define 	PORTA_PIN7_DIR		PORT_DIR_e_INPUT


/*PORTB Pins Configuration*/
#define 	PORTB_PIN0_DIR		PORT_DIR_e_INPUT
#define 	PORTB_PIN1_DIR		PORT_DIR_e_INPUT
#define 	PORTB_PIN2_DIR		PORT_DIR_e_INPUT
#define 	PORTB_PIN3_DIR		PORT_DIR_e_INPUT
#define 	PORTB_PIN4_DIR		PORT_DIR_e_INPUT
#define 	PORTB_PIN5_DIR		PORT_DIR_e_INPUT
#define 	PORTB_PIN6_DIR		PORT_DIR_e_INPUT
#define 	PORTB_PIN7_DIR		PORT_DIR_e_INPUT


/*PORTC Pins Configuration*/
#define 	PORTC_PIN0_DIR		PORT_DIR_e_INPUT
#define 	PORTC_PIN1_DIR		PORT_DIR_e_INPUT
#define 	PORTC_PIN2_DIR		PORT_DIR_e_INPUT
#define 	PORTC_PIN3_DIR		PORT_DIR_e_INPUT
#define 	PORTC_PIN4_DIR		PORT_DIR_e_INPUT
#define 	PORTC_PIN5_DIR		PORT_DIR_e_INPUT
#define 	PORTC_PIN6_DIR		PORT_DIR_e_INPUT
#define 	PORTC_PIN7_DIR		PORT_DIR_e_INPUT


/*PORTD Pins Configuration*/
#define 	PORTD_PIN0_DIR		PORT_DIR_e_INPUT
#define 	PORTD_PIN1_DIR		PORT_DIR_e_INPUT
#define 	PORTD_PIN2_DIR		PORT_DIR_e_INPUT
#define 	PORTD_PIN3_DIR		PORT_DIR_e_INPUT
#define 	PORTD_PIN4_DIR		PORT_DIR_e_INPUT
#define 	PORTD_PIN5_DIR		PORT_DIR_e_INPUT
#define 	PORTD_PIN6_DIR		PORT_DIR_e_INPUT
#define 	PORTD_PIN7_DIR		PORT_DIR_e_INPUT


/*
 * Setting Pin Value	("PORT_VAL_MODE 	PORT_MODE_e_PIN_MODE")
 * 		PORT_VAL_e_LOW
 *		PORT_VAL_e_HIGH
 * */
/*PORTA Pins Configuration*/
#define 	PORTA_PIN0_VAL		PORT_VAL_e_LOW
#define 	PORTA_PIN1_VAL		PORT_VAL_e_LOW
#define 	PORTA_PIN2_VAL		PORT_VAL_e_LOW
#define 	PORTA_PIN3_VAL		PORT_VAL_e_LOW
#define 	PORTA_PIN4_VAL		PORT_VAL_e_LOW
#define 	PORTA_PIN5_VAL		PORT_VAL_e_LOW
#define 	PORTA_PIN6_VAL		PORT_VAL_e_LOW
#define 	PORTA_PIN7_VAL		PORT_VAL_e_LOW


/*PORTB Pins Configuration*/
#define 	PORTB_PIN0_VAL		PORT_VAL_e_LOW
#define 	PORTB_PIN1_VAL		PORT_VAL_e_LOW
#define 	PORTB_PIN2_VAL		PORT_VAL_e_LOW
#define 	PORTB_PIN3_VAL		PORT_VAL_e_LOW
#define 	PORTB_PIN4_VAL		PORT_VAL_e_LOW
#define 	PORTB_PIN5_VAL		PORT_VAL_e_LOW
#define 	PORTB_PIN6_VAL		PORT_VAL_e_LOW
#define 	PORTB_PIN7_VAL		PORT_VAL_e_LOW


/*PORTC Pins Configuration*/
#define 	PORTC_PIN0_VAL		PORT_VAL_e_LOW
#define 	PORTC_PIN1_VAL		PORT_VAL_e_LOW
#define 	PORTC_PIN2_VAL		PORT_VAL_e_LOW
#define 	PORTC_PIN3_VAL		PORT_VAL_e_LOW
#define 	PORTC_PIN4_VAL		PORT_VAL_e_LOW
#define 	PORTC_PIN5_VAL		PORT_VAL_e_LOW
#define 	PORTC_PIN6_VAL		PORT_VAL_e_LOW
#define 	PORTC_PIN7_VAL		PORT_VAL_e_LOW


/*PORTD Pins Configuration*/
#define 	PORTD_PIN0_VAL		PORT_VAL_e_LOW
#define 	PORTD_PIN1_VAL		PORT_VAL_e_LOW
#define 	PORTD_PIN2_VAL		PORT_VAL_e_LOW
#define 	PORTD_PIN3_VAL		PORT_VAL_e_LOW
#define 	PORTD_PIN4_VAL		PORT_VAL_e_LOW
#define 	PORTD_PIN5_VAL		PORT_VAL_e_LOW
#define 	PORTD_PIN6_VAL		PORT_VAL_e_LOW
#define 	PORTD_PIN7_VAL		PORT_VAL_e_LOW


#endif /* PORT_CONFIG_H_ */
