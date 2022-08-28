/*
 * dio.c
 *
 * Created: 8/22/2022 12:02:43 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "dio.h"
#include "../../Utilities/registers.h"


/*
1-this functions configures pin as output or input
2-return OK, if configuration is done
3-return WRONG_PIN_NUMBER, if pin number is wrong
4-return WRONG_PORT_NUMBER, if port number is wrong
5-return WRONG_DIRECTION, if direction is wrong
*/
EN_dioError_t DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction)
{
	if( !(pinNumber==PIN7 || pinNumber==PIN6 || pinNumber==PIN5 || pinNumber==PIN4 || pinNumber==PIN3 || pinNumber==PIN2 || pinNumber==PIN1 || pinNumber==PIN0) )
		return WRONG_PIN_NUMBER;
	else if( !(portNumber == Port_A || portNumber == Port_B || portNumber == Port_C || portNumber == Port_D) )
		return WRONG_PORT_NUMBER;
	else if( !(direction == OUT || direction == IN) )
		return WRONG_DIRECTION;
	else
	{
		switch(portNumber)
		{
			case Port_A:		
							DDRA = ( DDRA & ~(1<<pinNumber) ) | (direction << pinNumber);
							break;
		
			case Port_B:		
							DDRB = ( DDRB & ~(1<<pinNumber) ) | (direction << pinNumber);		
							break;
		
			case Port_C:		
							DDRC = ( DDRC & ~(1<<pinNumber) ) | (direction << pinNumber);
							break;
		
			case Port_D:		
							DDRD = ( DDRD & ~(1<<pinNumber) ) | (direction << pinNumber);
							break;
		}
		return OK;
	}
}



/*
1-this functions writes value on (high or low)
2-return OK, if writing is done
3-return WRONG_PIN_NUMBER if pin number is wrong
4-return WRONG_PORT_NUMBER, if port number is wrong
5-return WRONG_VALUE if value is wrong
*/
EN_dioError_t DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value)
{
	if( !(pinNumber==PIN7 || pinNumber==PIN6 || pinNumber==PIN5 || pinNumber==PIN4 || pinNumber==PIN3 || pinNumber==PIN2 || pinNumber==PIN1 || pinNumber==PIN0) )
		return WRONG_PIN_NUMBER;
	else if( !(portNumber == Port_A || portNumber == Port_B || portNumber == Port_C || portNumber == Port_D) )
		return WRONG_PORT_NUMBER;
	else if( !(value == HIGH || value == LOW) )
		return WRONG_VALUE;
	else
	{
		switch(portNumber)
		{
			case Port_A:		
							PORTA = ( PORTA & ~(1<<pinNumber) ) | (value << pinNumber);
							break;
		
			case Port_B:		
							PORTB = ( PORTB & ~(1<<pinNumber) ) | (value << pinNumber);
							break;
		
			case Port_C:		
							PORTC = ( PORTC & ~(1<<pinNumber) ) | (value << pinNumber);
							break;
					
			case Port_D:		
							PORTD = ( PORTD & ~(1<<pinNumber) ) | (value << pinNumber);
							break;
		}
		return OK;
	}
}


/*
1-this functions toggles pin (high --> low  and  low --> high)
2-return OK, if toggling is done
3-return WRONG_PIN_NUMBER if pin number is wrong
4-return WRONG_PORT_NUMBER, if port number is wrong
*/
EN_dioError_t DIO_toggle(uint8_t pinNumber , uint8_t portNumber)
{
	if( !(pinNumber==PIN7 || pinNumber==PIN6 || pinNumber==PIN5 || pinNumber==PIN4 || pinNumber==PIN3 || pinNumber==PIN2 || pinNumber==PIN1 || pinNumber==PIN0) )
		return WRONG_PIN_NUMBER;
	else if( !(portNumber == Port_A || portNumber == Port_B || portNumber == Port_C || portNumber == Port_D) )
		return WRONG_PORT_NUMBER;
	else
	{
		switch(portNumber)
		{
			case Port_A:
							PORTA ^= (1<<pinNumber);
							break;
		
			case Port_B:
							PORTB ^= (1<<pinNumber);
							break;
		
			case Port_C:	
							PORTC ^=  (1<<pinNumber);
							break;
		
			case Port_D:	
							PORTD ^=  (1<<pinNumber);
							break;
		}
		return OK;
	}
}




/*
1-this functions reads value on pin
2-return OK, if reading is done
3-return WRONG_PIN_NUMBER if pin number is wrong
4-return WRONG_PORT_NUMBER, if port number is wrong
*/
EN_dioError_t DIO_read(uint8_t pinNumber , uint8_t portNumber , uint8_t *value)
{
	if( !(pinNumber==PIN7 || pinNumber==PIN6 || pinNumber==PIN5 || pinNumber==PIN4 || pinNumber==PIN3 || pinNumber==PIN2 || pinNumber==PIN1 || pinNumber==PIN0) )
		return WRONG_PIN_NUMBER;
	else if( !(portNumber == Port_A || portNumber == Port_B || portNumber == Port_C || portNumber == Port_D) )
		return WRONG_PORT_NUMBER;
	else
	{
		switch(portNumber)
		{
			case Port_A:
							*value = (PINA & (1<<pinNumber)) >> pinNumber;
							break;
			
			case Port_B:
							*value = (PINB & (1<<pinNumber)) >> pinNumber;
							break;
							
			case Port_C:
							*value = (PINC & (1<<pinNumber)) >> pinNumber;
							break;
			
			case Port_D:
							*value = (PIND & (1<<pinNumber)) >> pinNumber;
							break;
		}
		return OK;
	}
}