/*
 * LED_INT.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Ahmed Ehab
 */

#ifndef LED_INT_H_
#define LED_INT_H_

u8 LED_u8InitLed(DIO_PORT PortNo,DIO_PIN PinNo);
u8 LED_u8ToggleLed(DIO_PORT PortNo,DIO_PIN PinNo);
u8 LED_u8BlinkLed(DIO_PORT PortNo,DIO_PIN PinNo,u16 Delay);
u8 LED_u8SetState(DIO_PORT PortNo,DIO_PIN PinNo,u8 State);
#endif /* LED_INT_H_ */
