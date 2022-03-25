/*
 *
 *   Module: ADC
 *
 *   File Name:  adc.h
 *
 *   Description: Header File for the ADC
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */

#ifndef ADC_H_
#define ADC_H_

/************************************INCLUDES***********************************/

#include <avr/io.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"


/************************************DEFINITIONS*********************************/

#define ADC_MUX_SEL_REG ADMUX
#define VOLT_REF_SELECTION0 REFS0
#define VOLT_REF_SELECTION1 REFS0


#define ADC_CONTROL_STATUS_REG ADCSRA
#define ADC_ENABLE ADEN
#define ADC_START_CONV ADSC
#define ADC_INTERRUPT_FLAG ADIF
#define ADC_PRESCALER_SELECT0 ADPS0
#define ADC_PRESCALER_SELECT1 ADPS1
#define ADC_PRESCALER_SELECT2 ADPS2

#define ADC_REG ADC

/*****************************EXTERN AND GLOBAL VARIABLES************************/

extern int ADC_VALUE;


/*********************************FUNCTIONS PROTOTYPES***************************/


void ADC_init();

uint16 ADC_readChannel(uint8 channel);




#endif /* ADC_H_ */
