/*
 *
 *   Module: TIMER
 *
 *   File Name:  timers.c
 *
 *   Description: Source File for the TIMER
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */


/************************************INCLUDES************************************/

#include "timers.h"


/**********************************GLOBAL VARIABLES*****************************/

int val=0;


/*********************************FUNCTIONS DEFINITIONS**************************/


void TIMERS_init(){
	/*
	 * DDRB |=1<<PB3
	 * TCCR0 -> F_CPU=1024, (WGM00, WGM01 -> FAST PWM)
	 * TIMSK -> OCEIO
	 * */
	TCNT0=0;
	DATA_DIRECTION_OUTCOMPPIN |=(1<<PIN_NUMBER);
	TIMER_CONTROL_REG = (1<<CLOCK1)| (1<< WAVE_GENERATION0) |(1<< WAVE_GENERATION1)| (1<<COMPARE_OUTPUT_MODE1);
	TIMER_INT_MASK_REG = 1<<MODE_OF_OPERATION;
	OUTPUT_COMP_REG= ADC_REG/4;
}



void UPDATE_OC0(){
	/*divide the value in ADC by 4 and assign it to OCR0*/
	val=ADC_REG;
	OUTPUT_COMP_REG= val/4;
}



