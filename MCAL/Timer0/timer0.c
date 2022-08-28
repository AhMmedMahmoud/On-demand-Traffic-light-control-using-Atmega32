/*
 * timer0.c
 *
 * Created: 8/22/2022 6:38:40 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "timer0.h"
#include "../../Utilities/registers.h"


uint16_t elapsed_time_in_ms = 0;       // variable represent time elapsed before reaching wanted delay
void (*fCallBack)(void);               // pointer to function



/*
	normal mode
	disconnect PIN 0C0
*/
void timer0_init()
{	
	TCCR0 &= ~( (1<<WGM00) | (1<<WGM01) );   // normal mode	
	TCCR0 &= ~( (1<<COM00) | (1<<COM01) );   // disconnect PIN OC0
}




/*
	 clock source to be used by Timer0  is clk/1024
*/
void timer0_start()
{
	TCCR0 |= ((1<<CS00) | (1<<CS02));              // timer clock is clk/1024 --> starting timer
}




/*
	 clock source to be used by Timer0  is  No clock source
*/
void timer0_stop()
{
	TCCR0 &= ~((1<<CS00) | (1<<CS02));             // timer clock is disconnected --> disable timer
}



/*
breaking busy wait delay by assign max value of unsigned int to variable elapsed_time_in_ms
*/
void timer0_overCome()
{
	elapsed_time_in_ms = MAX_16;
}


/*
	this function increase elapsed time
*/
void increaseElapsedTime(uint16_t value)
{
	elapsed_time_in_ms += value;
}



/*
function takes no.of seconds and generate busy wait delay
CPU frequency is 1 MHZ
the functions can be ended at any time by controlling the value of variable elapsed_time_in_ms
*/
void timer0_delay_s(uint8_t seconds)         // busy wait delay
{
	TCNT0 = 12;                              // make current value in timer0 is 0
	elapsed_time_in_ms = 0;
	timer0_start();
	while(elapsed_time_in_ms < seconds*1000)
	{
		if( (TIFR & (1<<TOV0) ) == 1)       // at overflow flag   (244 ticks --> 249.85 ms)
		{
			elapsed_time_in_ms += 250;      //increment elapsed_time by 250
			TIFR |= (1<<TOV0);              // clear overflow flag by writting 1   (commom bug)
			TCNT0 = 12;                     // make current value in timer0 is 0
		}
	}
	timer0_stop();
}




/*
function takes no of quarters of second and generate busy wait delay
CPU frequency is 1 MHZ
the functions can be ended at any time by controlling the value of variable elapsed_time_in_ms
*/
void timer0_delay_qS(uint16_t times)    // busy wait delay
{
	TCNT0 = 12;                              // make current value in timer0 is 0
	elapsed_time_in_ms = 0;					 // make elapsed_time is 0
	timer0_start();                          // start timer0
	while(elapsed_time_in_ms < times*250)
	{
		if( (TIFR & (1<<TOV0) ) == 1)     // at overflow flag   (244 ticks --> 249.85 ms)
		{
			elapsed_time_in_ms += 250;    //increment elapsed_time by 250
			TIFR |= (1<<TOV0);            // clear overflow flag by writting 1   (commom bug)
			TCNT0 = 12;                   // make current value in timer0 is 12
		}
	}
	timer0_stop();
}




/*
set fCallBack
*/
void setfCallBack(void (*callBack)(void))
{
	fCallBack = callBack;
}



/*
this function used to call function  pointed by fCallBack as times as you want
*/
void callFunctionEachQarteSecond(uint16_t times)
{
	TCNT0 = 12;                              // make current value in timer0 is 12
	elapsed_time_in_ms = 0;                  // make elapsed_time is 0
	timer0_start();                          // start timer0
	while(elapsed_time_in_ms < times*1000)
	{
		if( (TIFR & (1<<TOV0) ) == 1)       // at overflow flag   (244 ticks --> 249.85 ms)
		{
			elapsed_time_in_ms += 250;      // increment elapsed_time by 250
			TIFR |= (1<<TOV0);              // clear overflow flag by writting 1   (commom bug)
			TCNT0 = 12;                     // make current value in timer0 is 12
			fCallBack();                    // call function which is pointed by fCallBack
		}
	}
	timer0_stop();
}




/*
	check if there is overflow or no overflow
	if there , return TIMER0_OVERFLOW
	else retunr TIMER0_NOTOVERFLOW
*/
EN_timer0_OverFlowState_t timer0_checkOverFlow()
{
	return (((TIFR & (1<<TOV0) ) == 1) ? TIMER0_OVERFLOW : TIMER0_NOTOVERFLOW);
}




/*
	return current value in timer0
*/
uint8_t timer0_getCurrnetValue()
{
	return TCNT0;
}



/*
	this functions clear overflow flag
*/
void timer0_clearOverFlowFlag()
{
	TIFR |= (1<<TOV0);            // clear overflow flag by writting 1   (commom bug)
}



/*
	set timer curernt value
*/
void timer0_setCurrentValue(uint8_t value)
{
	TCNT0 = value;
}