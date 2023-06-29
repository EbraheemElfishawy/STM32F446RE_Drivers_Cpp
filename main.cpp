#if 1
   /*CLASS1*/
   #include "uart.h"
   #include "led.h"
   /*There are 3 types of allocation*/
	 
   Led LedRed(RED,ON);                      /*1- Static allocation*/
	 Led LedBuiltIn(BUILTIN,ON);                      /*1- Static allocation*/
   LedState_Type LedRedState;
   LedState_Type LedGreenState;
   LedState_Type LedBlueState;
   int main()
   {
	
			USART2_Init();
			Led LedGreen(GREEN,OFF);              /*2- Automatic allocation*/
       Led *LedBlue = new Led(BLUE,OFF);     /*3- Dynamic allocation, new is like malloc in c*/
	
       LedRedState   = LedRed.getState();
       LedGreenState = LedGreen.getState();
       LedBlueState  = LedBlue->getState();                /*Here we used the arrow operator*/

       LedBlue->setState(ON);
       LedBlueState  = LedBlue->getState();
			delete LedBlue;                     /*Use keyword delete to free the pointer*/
       LedBlueState  = LedBlue->getState();
    
   	while(1)
   	{
   	}
	
   }
#endif

#if 0
#include "uart.h"
#include "led.h"
#include "powerLed.h"
LedState_Type PowerLed1_state;
Led_Elec_Type PowerLed2_power;
Led_Elec_Type powerLed3_current;

int main()
{
	
		USART2_Init();
    powerLed pLed1(RED,OFF,DIAM_7MM,CURR_HIGH,VOL_NORMAL);
    powerLed pLed2(BLUE,OFF,DIAM_7MM,CURR_HIGH,VOL_NORMAL);
    powerLed *pLed3 = new powerLed (GREEN,OFF,DIAM_5MM,CURR_VERY_HIGH,VOL_HIGH);
    PowerLed1_state = pLed1.getState();
    PowerLed2_power = pLed2.PowerLed_computePower();
    powerLed3_current = pLed3->PowerLed_getCurrent();
    pLed1.setState(OFF);
    pLed2.setState(OFF);
    pLed3->setState(ON);
    delete pLed3;

	while(1)
	{
	}
	
}

#endif