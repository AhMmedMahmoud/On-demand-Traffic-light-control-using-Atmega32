/*
 * timer2.c
 *
 * Created: 8/23/2022 8:42:00 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "timer2.h"
#include "../../Utilities/registers.h"



/*
	normal mode
	disconnect PIN 0C0
*/
void timer2_init()
{
	TCCR2 &= ~( (1<<WGM20) | (1<<WGM21) );   // normal mode
	TCCR2 &= ~( (1<<COM20) | (1<<COM21) );   // disconnect PIN OC0
}




/*
	 clock source to be used by Timer2  is clk/1024
*/
void timer2_start()
{
	TCCR2 |= ((1<<CS20) | (1<<CS21) | (1<<CS22));              // timer clock is clk/1024 --> starting timer
	TCNT2 = 110;
}




/*
	 clock source to be used by Timer2  is  No clock source
*/
void timer2_stop()
{
	TCCR2 &= ~((1<<CS20) | (1<<CS21) | (1<<CS22));             // timer clock is disconnected --> disable timer
}



/*
	this functions clear overflow flag
*/
void timer2_clearOverFlowFlag()
{
	TIFR |= (1<<TOV2);            // clear overflow flag by writting 1   (commom bug)
}



/*
	set timer curernt value
*/
void timer2_setCurrentValue(uint8_t value)
{
	TCNT2 = value;
}


/*
	check if there is overflow or no overflow
	if there , return OVERFLOW
	else retunr NOTOVERFLOW
*/
EN_timer2_OverFlowState_t timer2_checkOverFlow()
{
	return ((((TIFR & (1<<TOV2) )>>TOV2) == 1) ? TIMER2_OVERFLOW : TIMER2_NOTOVERFLOW);
}

/*
	return current value in timer2
*/
uint8_t timer2_getCurrnetValue()
{
	return TCNT2;
}