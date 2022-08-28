/*
 * dio.h
 *
 * Created: 8/22/2022 12:01:56 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/types.h"


/*
	enum represents errors in DIO
*/
typedef enum EN_dioError_t
{
	OK , WRONG_PIN_NUMBER , WRONG_PORT_NUMBER  , WRONG_DIRECTION , WRONG_VALUE
}EN_dioError_t;



/*
	enum represents pin directions
*/
typedef enum EN_pinDirections_t
{
	IN , OUT
}EN_pinDirections_t;



/*
	enum represents pin values
*/
typedef enum EN_pinValues_t
{
	LOW , HIGH
}EN_pinValues_t;


// functions prototypes
EN_dioError_t DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction);       
EN_dioError_t DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value);
EN_dioError_t DIO_toggle(uint8_t pinNumber , uint8_t portNumber);
EN_dioError_t DIO_read(uint8_t pinNumber , uint8_t portNumber , uint8_t *value);


#endif /* DIO_H_ */