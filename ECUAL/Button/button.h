/*
 * button.h
 *
 * Created: 8/22/2022 6:06:16 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"



/*
	enum represents Button errors
*/
typedef enum EN_buttonError_t
{
	OK_BUTTON , BUTTON_INITIALIZATION_FAILED, BUTTON_READING_FAILED
}EN_buttonError_t;


//functions prototypes
EN_buttonError_t Button_init(uint8_t buttonPin, uint8_t buttonPort);
EN_buttonError_t Button_read(uint8_t buttonPin, uint8_t buttonPort , uint8_t* value);





#define PedestrianButtonPin  PIN2
#define PedestrianButtonPort Port_D


#endif /* BUTTON_H_ */