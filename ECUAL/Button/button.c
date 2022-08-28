/*
 * button.c
 *
 * Created: 8/22/2022 6:06:03 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "button.h"
#include "../../MCAL/DIO/dio.h"


/*
1-this functions initializes button
2-return OK_BUTTON if initialization is done
3-return BUTTON_INITIALIZATION_FAILED if initialization is failed
*/
EN_buttonError_t Button_init(uint8_t buttonPin, uint8_t buttonPort)
{
	switch( DIO_init(buttonPin,buttonPort,IN) )
	{
		case OK: return OK_BUTTON;
		default: return BUTTON_INITIALIZATION_FAILED;
	}
}


/*
1-this functions reads button
2-return OK_BUTTON if reading is done
3-return BUTTON_READING_FAILED if reading is failed
*/
EN_buttonError_t Button_read(uint8_t buttonPin, uint8_t buttonPort , uint8_t* value)
{
	switch( DIO_read(buttonPin,buttonPort,value) )
	{
		case OK: return OK_BUTTON;
		default: return BUTTON_READING_FAILED;
	}
}