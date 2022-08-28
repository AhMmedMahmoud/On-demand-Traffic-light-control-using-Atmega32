/*
 * led.c
 *
 * Created: 8/22/2022 5:40:50 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "led.h"
#include "../../MCAL/DIO/dio.h"

/*
1-this functions initializes led
2-return OK_LED if initialization is done
3-return LED_INITIALIZATION_FAILED if initialization is failed
*/
EN_ledError_t LED_init(uint8_t ledPin , uint8_t ledPort)
{
	switch ( DIO_init(ledPin,ledPort,OUT) )
	{
		case OK:	return OK_LED;
		default:	return LED_INITIALIZATION_FAILED;
	}
}



/*
1-this functions turns on led
2-return OK_LED if turning on is done
3-return LED_TURING_ON_FAILED if turning on is failed
*/
EN_ledError_t LED_on(uint8_t ledPin , uint8_t ledPort)
{
	switch ( DIO_write(ledPin,ledPort,HIGH) )
	{
		case OK:	return OK_LED;
		default:	return LED_TURING_ON_FAILED;
	}
}



/*
1-this functions turns off led
2-return OK_LED if turning off is done
3-return LED_TURING_OFF_FAILED if turning off is failed
*/
EN_ledError_t LED_off(uint8_t ledPin , uint8_t ledPort)
{
	switch ( DIO_write(ledPin,ledPort,LOW) )
	{
		case OK:	return OK_LED;
		default:	return LED_TURING_OFF_FAILED;
	}
}



/*
1-this functions toggles led
2-return OK_LED if toggling is done
3-return LED_TOGGLING_FAILED if toggling is failed
*/
EN_ledError_t LED_toggle(uint8_t ledPin , uint8_t ledPort)
{
	switch ( DIO_toggle(ledPin,ledPort) )
	{
		case OK:	return OK_LED;
		default:	return LED_TOGGLING_FAILED;
	}
}
