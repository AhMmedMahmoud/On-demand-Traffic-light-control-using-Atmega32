/*
 * application.c
 *
 * Created: 8/22/2022 6:00:28 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "application.h"
#include "../MCAL/Interrupts/interrupts.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/Button/button.h"
#include "../MCAL/Timer0/timer0.h"
#include "../MCAL/Timer2/timer2.h"

#define F_CPU 1000000U
#define LONG_PRESS_TIME_ms 300

uint8_t mode;    // variable to store current mode
uint8_t state;	 // variable to store current state
uint8_t flow;	 // variable to determine which led will be turning on after blinking of cars yellow led  


/*
 1-this functions is called after button is pressed to check the press state (short press or long press)
 using timer2
 2- if the timer2 counting for 300 ms and the button Read isnot toggled --> return long press
 3- if  button Read  is toggled before timer2 counting 300ms            --> breakTimer2 , return short press
*/
EN_pressState_t checkPress(uint8_t buttonPin,uint8_t buttonPort)
{
	uint8_t read;
	uint8_t overFlows;
	overFlows = 0;        // need 2
	timer2_start();
	while(1)
	{
		Button_read(buttonPin,buttonPort,&read);
		if( timer2_checkOverFlow() == TIMER2_OVERFLOW)
		{
			overFlows++;
			timer2_clearOverFlowFlag();
			timer2_setCurrentValue(110);
		}
		if(overFlows == 2)break;
		if(read == 0)break;
	}
	timer2_stop();
	return ((overFlows<= 1) ? SHORT_PRESS : LONG_PRESS);
}





/*
1-this function is called when Pedestrian button is pressed
2-if mode is normal, check press state 
at long press do no thing 
at short press break busy wait and update mode to pedestrain 
3-if mode is pedestrian, do no thing
*/
ISR(EXT_INT0)
{
	if(mode == NORMAL)       // if button pressed in normal mode
	{
		timer0_stop();       // stop timer0
		if(checkPress(PedestrianButtonPin,PedestrianButtonPort) == SHORT_PRESS)     // check long press or short press
		{
			timer0_overCome();       // overcome timer
			mode = PEDESTRIAN;       // set mode to PEDESTRIAN
		}	
		else
		{	
			increaseElapsedTime(LONG_PRESS_TIME_ms);	   // compansate time taking by checking king of press
			timer0_start();			                       // start timer0
		}
	}
}


/*
function to be stored in pointer to function defined in timer driver
*/
void toggleYellowLed()
{
	LED_toggle(CarsYellowLedPin,CarsYellowLedPort);   // toggle cars yellow led
}




/*
	initialize cars' green led
	initialize cars' yellow led
	initialize cars' red led
	initialize Pedestrian green led
	initialize Pedestrian yellow led
	initialize Pedestrian red led
	initialize Pedestrian button
	initialize INT0
	initialize timer0
	initialize timer2
	set mode to normal
	set state to FIRST
	set CarsledsFlow to Down
*/
void setup()
{	
	LED_init(CarsGreenLedPin,CarsGreenLedPort);					// initialize cars' green led
	LED_init(CarsYellowLedPin,CarsYellowLedPort);				// initialize cars' yellow led
	LED_init(CarsRedLedPin,CarsRedLedPort);						// initialize cars' red led		
	LED_init(PedestrianGreenLedPin,PedestrianGreenLedPort);		// initialize Pedestrian green led
	LED_init(PedestrianYellowLedPin,PedestrianYellowLedPort);	// initialize Pedestrian yellow led
	LED_init(PedestrianRedLedPin,PedestrianRedLedPort);			// initialize Pedestrian red led		
	Button_init(PedestrianButtonPin,PedestrianButtonPort);		// initialize Pedestrian button
	INT0_init();												// initialize INT0		
	timer0_init();												// initialize timer0		
	timer2_init();												// initialize timer2
	mode = NORMAL;                                              // set mode to normal
	state = FIRST;                                              // set state to FIRST
	setfCallBack(toggleYellowLed);                              // store address led_toggle in pointer to function defined in timer driver
}


/*
	blinking led1 , led2 for 5s
	total on time for led = 2.5s
	total off time for led = 2.5s
	delay is provided by timer0
*/
void blink(uint8_t led1_pin , uint8_t led1_port , uint8_t led2_pin , uint8_t led2_port)
{
	int i = 0;
	for(i = 0 ; i < 10 ; i++)
	{
		LED_toggle(led1_pin,led1_port);				 // toggle yellow for cars      ------> Cars prepare for stopping
		LED_toggle(led2_pin,led2_port);              // toggle yellow for pedestrian------> pedestrian prepare for moving
		timer0_delay_qS(2);                          // wait 0.5s
	}
}





/*
In normal mode:
Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
The Yellow LED will blink for five seconds before moving to Green or Red LEDs.
In pedestrian mode:
Change from normal mode to pedestrian mode when the pedestrian button is pressed.
If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
Traffic lights signals are going to the normal mode again.
*/
void startApp()
{
	switch(mode)
	{
		
		case NORMAL:        switch(state)		
							{
								case FIRST:		LED_on(CarsGreenLedPin,CarsGreenLedPort);		 // turn on green for cars									
												timer0_delay_s(5);                               // for 5s
												LED_off(CarsGreenLedPin,CarsGreenLedPort);		 // turn off green for cars 
												
												if(mode == PEDESTRIAN)                 // if interrupt switches mode to PEDESTRIAN
													state =FOURTH;                     // switch state to Fourth
												else								   // no interrupt	
													state = SECOND;                    // switch state to second
												flow = DOWN;						   // set flow to down
												
												break;
																					
								case SECOND:	callFunctionEachQarteSecond(5);			//blinking cars yellow led for 5s (total on time = 2.5 , total on time = 2.5)	
															
												if(mode == PEDESTRIAN)					// if interrupt switches mode to PEDESTRIAN
													state =FOURTH;						// switch state to Fourth
													
												else if(flow == DOWN)					// if flow is down			
													state = THIRD;						// switch state to third
													
												else if(flow == UP)						// if flow is up
													state = FIRST;						// switch state to first
													
												break;
											
								case THIRD:     LED_on(CarsRedLedPin,CarsRedLedPort);		// turn on red for cars
												timer0_delay_s(5);                          // for 5s
												LED_off(CarsRedLedPin,CarsRedLedPort);      // turn off red for cars
											
												if(mode == NORMAL)							// if mode is normal
												{
													state = SECOND;							// switch state to second
													flow = UP;								// switch flow to up
												}
												
												break;											
							}
							break;
							
							
							
		case PEDESTRIAN:	if(state == FOURTH)	
							{
																													   // cars green led is turned off 
							LED_off(CarsYellowLedPin,CarsYellowLedPort);										       // cars yellow is turned off									   
							LED_on(PedestrianRedLedPin,PedestrianRedLedPort);                                          // turn on red for pedestrian --> pedestrian, DONOT MOVE																				
							blink(PedestrianYellowLedPin,PedestrianYellowLedPort,CarsYellowLedPin,CarsYellowLedPort);  // blink yellow leds --> inform pedestrian going after 5s
																				  									   //                   --> inform cars stopping after 5s
																												  	   // for 5s						
							LED_off(PedestrianRedLedPin,PedestrianRedLedPort);										   // turn off red for pedestrian 
							LED_off(PedestrianYellowLedPin,PedestrianYellowLedPort);								   // turn off yellow for pedestrian
							}											
											
							LED_on(CarsRedLedPin,CarsRedLedPort);                    // turn on red for cars        ------> cars, DONOT MOVE
							LED_on(PedestrianGreenLedPin,PedestrianGreenLedPort);    // turn on green for pedestrian------> pedestrian, MOVE	
							timer0_delay_s(5);										 // for 5s			
							LED_off(CarsRedLedPin,CarsRedLedPort);                   // turn off red for cars    
											   
											   
							blink(PedestrianYellowLedPin,PedestrianYellowLedPort,CarsYellowLedPin,CarsYellowLedPort); // blink yellow leds ---> inform cars going after 5s
																													  //                   ---> inform pedestrian stopping after 5s
																				 									  // for 5s		
							LED_off(PedestrianGreenLedPin,PedestrianGreenLedPort);									  // turn off green for pedestrian
											
											
							LED_on(CarsGreenLedPin,CarsGreenLedPort);                // turn on green for cars
							LED_on(PedestrianRedLedPin,PedestrianRedLedPort);        // turn on red for pedestrian
							timer0_delay_s(5);                                       // for 5s											
							LED_off(CarsGreenLedPin,CarsGreenLedPort);               // turn off red for pedestrian
							LED_off(PedestrianRedLedPin,PedestrianRedLedPort);       // turn off red for pedestrian
			   
							mode = NORMAL;		// switch mode to normal
							state = SECOND;		// switch state to second
							break;													
	}
}
