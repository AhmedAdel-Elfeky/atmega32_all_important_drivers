/*
 * DCMOTOR_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef DCMOTOR_INT_H_
#define DCMOTOR_INT_H_

#define DC_MOTOR_PORT A
#define RIGHT_PIN 0
#define LEFT_PIN 1

#define RIGHT_TURN (u8)1
#define LEFT_TURN (u8)2
#define STOP_TURN (u8)0

void DC_MOTOR_vidMotorOperation(u8 u8State);

#endif /* DCMOTOR_INT_H_ */
