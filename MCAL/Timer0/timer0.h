/*
 * timer0.h
 *
 * Created: 8/22/2022 6:38:26 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../Utilities/types.h"


/*
	enum represents overflow state
*/
typedef enum EN_timer0_OverFlowState_t
{
	TIMER0_NOTOVERFLOW , TIMER0_OVERFLOW
}EN_timer0_OverFlowState_t;


// functions prototypes
void timer0_init();
void timer0_start();
void timer0_stop();
void timer0_clearOverFlowFlag();
void timer0_setCurrentValue(uint8_t value);
EN_timer0_OverFlowState_t timer0_checkOverFlow();
uint8_t timer0_getCurrnetValue();
void timer0_overCome();
void timer0_delay_s(uint8_t seconds);
void timer0_delay_qS(uint16_t times);
void setfCallBack(void (*callBack)(void));
void callFunctionEachQarteSecond(uint16_t times);
void increaseElapsedTime(uint16_t value);


// timer0 registers pins
#define WGM00 PIN6
#define WGM01 PIN3
#define COM00 PIN4
#define COM01 PIN5
#define CS00  PIN0
#define CS02  PIN2
#define TOV0  PIN0

#endif /* TIMER0_H_ */