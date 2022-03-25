/*
 *
 *   Module: LCD
 *
 *   File Name: lcd.c
 *
 *   Description: Source File for the TIMER
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */

/************************************INCLUDES************************************/
#include "lcd.h"


/*********************************FUNCTIONS DEFINITIONS**************************/

void LCD_init(){
	/*Configuration of the DATA DIRECTION REGISTERS for the  LCD*/
	Data_DIRECTION_Port=0xFF;
	CONTROL_PORT_DIRECTION |=(1<<RS) | (1<<RW) | (1<<E);
    /*Command to specify that LCD has 2 rows and 8columns */
	LCD_sendCommand(0x38);
	/*Command cursor off*/
	LCD_sendCommand(0x0c);
	/*command to clear screen*/
	LCD_sendCommand(0x01);
}

void LCD_sendCommand(uint8 command){
	CONTROL_DATA_PORTY &= ~((1<<RS) | (1<<RW));
	_delay_ms(1);
	CONTROL_DATA_PORTY |= 1<<E;
	_delay_ms(1);
	DATA_PORTX= command;
	_delay_ms(1);
	CONTROL_DATA_PORTY &=~ (1<< E);
}

void LCD_displayCharacter(uint8 data){
	CONTROL_DATA_PORTY |=1<<RS;
	_delay_ms(1);
	CONTROL_DATA_PORTY |= 1<<E;
	_delay_ms(1);
	DATA_PORTX= data;
	_delay_ms(1);
	CONTROL_DATA_PORTY &=~ (1<<E);
}

void LCD_displayString(const char *string){
	uint8 i=0;
	while(string[i] !='\0'){
		LCD_displayCharacter(string[i]);
		i++;
	}

}

void LCD_goToRowCol(uint8 row, uint8 col){
	uint8 Address;

		/* first of all calculate the required address */
		switch(row)
		{
			case 0:
					Address=col;
					break;
			case 1:
					Address=col+0x40;
					break;
			case 2:
					Address=col+0x10;
					break;
			case 3:
					Address=col+0x50;
					break;
		}
		/* to write to a specific address in the LCD
		 * we need to apply the corresponding command 0b10000000+Address */
		LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}



void LCD_clear(){
	LCD_sendCommand(CLEAR_COMMAND);
}



void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}
