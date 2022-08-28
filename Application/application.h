/*
 * application.h
 *
 * Created: 8/22/2022 6:00:15 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../Utilities/types.h"


/*
	enum represents modes
*/
typedef enum EN_Modes_t
{
	NORMAL, PEDESTRIAN
}EN_Modes_t;




/*
	enum represents states
*/
typedef enum EN_States_t
{
	FIRST, SECOND , THIRD , FOURTH
}EN_States_t;




/*
	enum represents press state
*/
typedef enum EN_pressState_t
{
	SHORT_PRESS, LONG_PRESS
}EN_pressState_t;



/*
	enum represents Cars leds flow directions
*/
typedef enum EN_carsLedsFlowDirection_t
{
	DOWN, UP
}EN_carsLedsFlowDirection_t;



// functions prototypes
void setup();
void startApp();
EN_pressState_t checkPress(uint8_t buttonPin,uint8_t buttonPort);
void toggleYellowLed();
void blink(uint8_t led1_pin , uint8_t led1_port , uint8_t led2_pin , uint8_t led2_port);


#endif /* APPLICATION_H_ */