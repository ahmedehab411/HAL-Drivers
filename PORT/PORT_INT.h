/*
 * PORT_INT.h
 *
 *  Created on: Oct 5, 2023
 *      Author: Ahmed Ehab
 */

#ifndef PORT_INT_H_
#define PORT_INT_H_

typedef enum
{
	PORT_VAL_e_LOW,
	PORT_VAL_e_HIGH,
	PORT_VAL_e_FULL_LOW=0x00,
	PORT_VAL_e_FULL_HIGH=0xFF,

}PORT_VAL_e;

typedef enum
{
	PORT_MODE_e_FULL_PORT_MODE,
	PORT_MODE_e_PIN_MODE

}PORT_MODE_e;

typedef enum
{
	PORT_DIR_e_INPUT=0,
	PORT_DIR_e_OUTPUT=1,
	PORT_DIR_e_FULL_INPUT=0x00,
	PORT_DIR_e_FULL_OUTPUT=0xFF
}PORT_DIR_e;

u8 PORT_u8Init(void);

#endif /* PORT_INT_H_ */
