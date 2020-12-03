/*
 * STEPPER_INT.H
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED ADEL
 */

#ifndef STEPPER_INT_H_
#define STEPPER_INT_H_

#define STP_PORT A
#define PINK 0
#define YELLOW 1
#define ORANGE 2
#define BLUE 3

#define CLKWISE 0
#define ANTI_CLKWISE 1

void STP_vidStepperOperation(u8 u8StateCPY,u8 u8DirectionCPY, u8 u8AngleCPY ,u8 u8SpeedCPY);

#endif /* STEPPER_INT_H_ */


// full turn 128 for loop
