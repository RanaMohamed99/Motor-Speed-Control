/*
 *
 *   Module: MOTOR
 *
 *   File Name:  motor.h
 *
 *   Description: Header File for the MOTOR
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */

#ifndef MOTOR_H_
#define MOTOR_H_

/************************************INCLUDES************************************/
#include <avr/io.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"


/************************************DEFINITIONS*********************************/

#define MOTOR_DDR DDRB
#define MOTOR_PORT PORTB
#define MOTOR_INPUT1 PB0
#define MOTOR_INPUT2 PB1

/*********************************FUNCTIONS PROTOTYPES***************************/

/*function to initialise the motor*/
void motor_init();

#endif /* MOTOR_H_ */
