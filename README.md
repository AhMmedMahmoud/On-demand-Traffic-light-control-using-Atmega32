# On-demand-Traffic-light-control-using-Atmega32
This project is for the EgFWD Embedded Systems Professional NanoDegree Scholarship. it was written in C using Microchip Studio and Proteus 8 professional.
## Aim
implement a traffic lights system with an on-demand crosswalk button.
## Procedure Details
### In normal mode:
- Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
- The Yellow LED will blink for five seconds before moving to Green or Red LEDs.
### In pedestrian mode:
- Change from normal mode to pedestrian mode when the pedestrian button is pressed.
- If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
- If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
- At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
- After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
- Traffic lights signals are going to the normal mode again.
## Project flowchart
![image](https://user-images.githubusercontent.com/104006521/187073420-ae479711-81ac-45de-877e-b852d0e83d45.png)
## Demonstration
![image](https://user-images.githubusercontent.com/104006521/189163262-51740bd8-f099-4609-91a6-f7091f1ade6c.png)
## Zip file 
[here](https://drive.google.com/file/d/1WsdtbdK5yDBTqDW3TDJmWxMp75G41XCO/view?usp=sharing)
