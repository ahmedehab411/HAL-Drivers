/*
 * SERVO_INT.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Ahmed Ehab
 */

#ifndef SERVO_INT_H_
#define SERVO_INT_H_

u8 SERVO_u8InitChA(void);
u8 SERVO_u8InitChB(void);
u8 SERVO_u8SetAngleChA (f32 Copy_u8Angle);
u8 SERVO_u8SetAngleChB (f32 Copy_u8Angle);
u8 SERVO_u8SmoothOpenChA (f32 Copy_u8Angle);
u8 SERVO_u8SmoothCloseChA (f32 Copy_u8Angle);
u8 SERVO_u8SmoothOpenChB (f32 Copy_u8Angle);
u8 SERVO_u8SmoothCloseChB (f32 Copy_u8Angle);
#endif /* SERVO_INT_H_ */
