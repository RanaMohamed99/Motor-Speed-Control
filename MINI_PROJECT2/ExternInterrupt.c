/*
 *
 *   Module: External Interrupt
 *
 *   File Name:  ExternInterrupt.c
 *
 *   Description: Source File for the External Interrupt
 *
 *   Created on: 1 Jun 2021
 *
 *   Author: Rana Mohamed
 */


/************************************INCLUDES*********************************/

#include "ExternInterrupt.h"


/*********************************FUNCTIONS DEFINITIONS**********************/


void INT_activate(){

#if (INTRPT_TYPE==0)

    	 /*Let the pin be an output pin PB3=0
    	  * GICR -> SET INT0 PIN
    	  * MUCUR -> SET BOTH PINS CONCERNING INT0 (ISC01,ISC00)
    	  *    for rising edge
    	  */
	     GICR |= 1<<INT0;
	     MCUCR |= (1<<ISC01) | (1<<ISC00);


#elif (INTRPT_TYPE==1)

	  /*Let the pin be an output pin PD3=0
	  * GICR -> SET INT1 PIN
	  * MUCUR -> SET BOTH PINS CONCERNING INT1 (ISC11,ISC10)
	  *          for rising edge
	  */
    	DDRD &=~(1<<PD3);
	    GICR |= 1<<INT1;
	    MCUCR |= (1<<ISC11) | (1<<ISC10);

#elif (INTRPT_TYPE==2)

	    GICR |= 1<<INT2;
	    MCUCSR |= ISC2;




#endif


}


ISR(INT1_vect){
	    MOTOR_PORT ^=(1<< MOTOR_INPUT1);
	    MOTOR_PORT ^=(1<< MOTOR_INPUT2);

    	 }



