/*
 *
 *   Module: MOTOR
 *
 *   File Name:  motor.c
 *
 *   Description: Source File for the MOTOR
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */

/************************************INCLUDES************************************/
#include "motor.h"


/*********************************FUNCTIONS DEFINITIONS**************************/
void motor_init(){
	MOTOR_DDR |= ( 1<< MOTOR_INPUT1) | (1<< MOTOR_INPUT2);
	SET_BIT(MOTOR_PORT, MOTOR_INPUT1);
	CLEAR_BIT(MOTOR_PORT, MOTOR_INPUT2);

}
