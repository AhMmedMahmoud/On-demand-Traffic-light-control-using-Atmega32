/*
 * Light traffic.c
 *
 * Created: 8/22/2022 11:06:41 AM
 * Author : Ahmed Mahmoud Mohamed Ibrahim
 */ 


#include "Application/application.h"
int main(void)
{
	setup();  // initializations	
	while(1)
	{
		startApp();
	}
}



/*
User story 1
As a pedestrian when I will make a short press on the crosswalk button while the cars green light is on and pedestrian red light is off,
I will wait for the yellow lights to blink for five seconds then the cars red light is on and pedestrian green light is on for five seconds,
so that I can cross the street

i will press short when car green led is on
-----> pedestrian red light on                                           ---> pedestrian, donot move
-----> yellow lights to blink for five seconds                           ---> pedestrian, will move after 5s
                                                                         ---> cars, will stop after 5s
-----> cars red light on			                                     ---> cars, donot move																		 
-----> pedestrian red light is off   , pedestrian green light is on      ---> pedestrian, move
-----> yellow lights to blink for five seconds                           ---> pedestrian, will stop after 5s
-----> pedestrian red light on                                           ---> pedestrian, donot move
-----> car green light is on                                             ---> cars, move
*/

/*
User story 2
As a pedestrian when I will make a short press on the crosswalk button while the cars yellow light is blinking. pedestrian red light is on,
I will wait for all yellow lights to blink for five seconds then the cars red light is on and pededstrian green light is on for five seconds,
 so that I can cross the street
 
i will press short when car yellow led is blinking
-----> pedestrian red light on                                           ---> pedestrian, donot move
-----> yellow lights to blink for five seconds                           ---> pedestrian, will move after 5s
																		 ---> cars, will stop after 5s
-----> cars red light on			                                     ---> cars, donot move
-----> pedestrian red light is off   , pedestrian green light is on      ---> pedestrian, move
-----> yellow lights to blink for five seconds                           ---> pedestrian, will stop after 5s
-----> pedestrian red light on                                           ---> pedestrian, donot move
-----> car green light is on

*/


/*
User story 3
As a pedestrian when I will make a short press on the crosswalk button while the cars red light is on and pedestrian green light is on,
 I expect nothing to be done
*/


/*
User story 4
As a pedestrian when I made a long press on the crosswalk button, I expect nothing to be done.
*/



/*
User story 5
As a pedestrian when I made a double press on the crosswalk button, I expect that the first press will do the action and nothing to be done after the second press.
*/
