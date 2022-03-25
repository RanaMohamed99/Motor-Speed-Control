/*
 *
 *   Module: TIMER
 *
 *   File Name:  timers.h
 *
 *   Description: Header File for the TIMER
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */


#ifndef TIMERS_H_
#define TIMERS_H_

/************************************INCLUDES************************************/
#include"adc.h"

/************************************DEFINITIONS*********************************/

/*TCCR0 bits definition*/

#define TIMER_CONTROL_REG TCCR0
#define WAVE_GENERATION0 WGM00
#define WAVE_GENERATION1 WGM01
#define COMPARE_OUTPUT_MODE0 COM00
#define COMPARE_OUTPUT_MODE1 COM01
#define CLOCK0 CS00
#define CLOCK1 CS01
#define CLOCK2 CS02
#define DATA_DIRECTION_OUTCOMPPIN DDRB
#define PIN_NUMBER PB3

/*OCR0 definition*/
#define OUTPUT_COMP_REG OCR0

/*TIMSK bits definition*/
#define TIMER_INT_MASK_REG TIMSK
#define MODE_OF_OPERATION OCIE0

/*********************************FUNCTIONS PROTOTYPES***************************/

/*function to initialise the Timer*/
void TIMERS_init();

/*function to update the OC0*/
void UPDATE_OC0();

#endif /* TIMERS_H_ */
