/*
 *
 *   Module: LCD
 *
 *   File Name:  lcd.h
 *
 *   Description: Header File for the LCD
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */

#ifndef LCD_H_
#define LCD_H_

/************************************INCLUDES************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/************************************DEFINITIONS*********************************/

/*Definitions for DATA Pins*/
#define Data_DIRECTION_Port DDRC
#define DATA_PORTX PORTC

/*Definitions for Control Pins*/
#define CONTROL_PORT_DIRECTION DDRD
#define CONTROL_DATA_PORTY PORTD
#define RS  PD0
#define RW  PD1
#define E  PD2

#define CLEAR_COMMAND 0x01
#define SET_CURSOR_LOCATION 0x80

/*********************************FUNCTIONS PROTOTYPES***************************/
void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_goToRowCol(uint8 row, uint8 col);
void LCD_clear();
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_intgerToString(int data);


#endif /* LCD_H_ */
