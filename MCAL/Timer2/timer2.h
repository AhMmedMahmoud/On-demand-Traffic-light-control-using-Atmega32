/*
 * timer2.h
 *
 * Created: 8/23/2022 8:41:43 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include  "../../Utilities/types.h"



/*
	enum represents overflow state
*/
typedef enum EN_timer2_OverFlowState_t
{
	TIMER2_NOTOVERFLOW , TIMER2_OVERFLOW
}EN_timer2_OverFlowState_t;


// functions prototypes
void timer2_init();
void timer2_start();
void timer2_stop();
void timer2_clearOverFlowFlag();
void timer2_setCurrentValue(uint8_t value);
EN_timer2_OverFlowState_t timer2_checkOverFlow();
uint8_t timer2_getCurrnetValue();

// timer2 registers pins
#define WGM20 PIN6
#define WGM21 PIN3
#define COM20 PIN4
#define COM21 PIN5
#define CS20  PIN0
#define CS21  PIN1
#define CS22  PIN2
#define TOV2  PIN6


#endif /* TIMER2_H_ */