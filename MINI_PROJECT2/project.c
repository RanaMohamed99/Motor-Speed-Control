/*
 *  File Name: project.c
 *
 *  Created on: 2 Jun 2021
 *
 *  Author: Rana Mohamed
 */

#include "ExternInterrupt.h"
#include "lcd.h"
#include "adc.h"
#include "timers.h";
#include "motor.h";

int main(){

	ADC_init();
	LCD_init();
	TIMERS_init();
	SREG |=(1<<7);
	motor_init();
	INT_activate();
	LCD_goToRowCol(0,5);
	LCD_displayString("Welcome");
	LCD_goToRowCol(1,3);
	LCD_displayString("Mini Project2");
	_delay_ms(200);
	LCD_clear();
	LCD_displayString("ADC Value = ");

	while(1){
		LCD_goToRowCol(0,12);
		ADC_VALUE=ADC_readChannel(0);
		LCD_intgerToString(ADC_VALUE);
	    UPDATE_OC0(ADC_VALUE);
	}
}

