/*
 * Push_Button_INT.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Ahmed Ehab
 */

#ifndef PUSH_BUTTON_INT_H_
#define PUSH_BUTTON_INT_H_

typedef enum
{
	PULLUP_DIS=0,
	PULLUP_EN=1,
}PULLUP;

u8 PUSH_BUTTON_u8Init(DIO_PORT PortNo,DIO_PIN PinNo,PULLUP PullupStatus);
u8 PUSH_BUTTON_u8GetVal(DIO_PORT PortNo,DIO_PIN PinNo,u8 *Reading);

#endif /* PUSH_BUTTON_INT_H_ */
