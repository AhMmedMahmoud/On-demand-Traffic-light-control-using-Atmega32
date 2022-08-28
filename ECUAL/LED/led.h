/*
 * led.h
 *
 * Created: 8/22/2022 5:41:07 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"


/*
	enum represents led errors
*/
typedef enum EN_ledError_t
{
	OK_LED , LED_INITIALIZATION_FAILED, LED_TURING_ON_FAILED, LED_TURING_OFF_FAILED , LED_TOGGLING_FAILED
}EN_ledError_t;

// functions prototypes
EN_ledError_t LED_init(uint8_t ledPin , uint8_t ledPort);
EN_ledError_t LED_on(uint8_t ledPin , uint8_t ledPort);
EN_ledError_t LED_off(uint8_t ledPin , uint8_t ledPort);
EN_ledError_t LED_toggle(uint8_t ledPin , uint8_t ledPort);


// pins and ports of Cars leds
// pins and ports of Pedestrian leds

#define PedestrianGreenLedPort   Port_B
#define PedestrianYellowLedPort  Port_B
#define PedestrianRedLedPort     Port_B

#define PedestrianGreenLedPin   PIN0
#define PedestrianYellowLedPin  PIN1
#define PedestrianRedLedPin     PIN2

#define CarsGreenLedPort   Port_A
#define CarsYellowLedPort  Port_A
#define CarsRedLedPort     Port_A

#define CarsGreenLedPin   PIN0
#define CarsYellowLedPin  PIN1
#define CarsRedLedPin     PIN2

#endif /* LED_H_ */