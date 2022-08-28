/*
 * interrupts.c
 *
 * Created: 8/22/2022 11:30:47 AM
 *  Author: user
 */ 

#include "interrupts.h"
#include "../../Utilities/registers.h"


/*
1- this functions initialize INT0
2- it enables global interrupts
3- configure causer of int0 is raising edge
4- enable INT0 unit
*/
void INT0_init()
{
	SREG |= 1<<7;      // enable global interrupts
	MCUCR |= 0x03;     // causer of int0 is raising edge
	GICR |= 1<<6;      // enable int0 unit
}

