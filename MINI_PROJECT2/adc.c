/*
 *
 *   Module: ADC
 *
 *   File Name:  adc.c
 *
 *   Description: Source File for the LCD
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */


/************************************INCLUDES***********************************/

#include"adc.h"

/**********************************GLOBAL VARIABLES*****************************/

int ADC_VALUE=0;

/*********************************FUNCTIONS DEFINITIONS**************************/

void ADC_init(){
	ADC_MUX_SEL_REG=0;
	ADC_CONTROL_STATUS_REG= (1<<ADC_ENABLE) | (1<<ADC_PRESCALER_SELECT0) | (1<<ADC_PRESCALER_SELECT1);
}


uint16 ADC_readChannel(uint8 channel){

	ADC_MUX_SEL_REG = (ADC_MUX_SEL_REG & 0xE0) | (0x1F & channel);

	SET_BIT(ADC_CONTROL_STATUS_REG, ADC_START_CONV);

	while(BIT_IS_CLEAR(ADC_CONTROL_STATUS_REG, ADC_INTERRUPT_FLAG));

	SET_BIT(ADC_CONTROL_STATUS_REG, ADC_INTERRUPT_FLAG);

return ADC_REG;
}












