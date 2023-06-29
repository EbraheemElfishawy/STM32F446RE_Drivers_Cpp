#ifndef __LED_H
#define __LED_H
#include <stdint.h>
#include "uart.h"
#include "stm32f446xx.h"

#define LED_PORT				GPIOA 		/*All leds are connected to GPIOA*/
#define LED_PORT_CLOCK			(1U<<0)		/*To enable clock for GPIOA as GPIOAEN bit = 0 in AHB1ENR*/

#define LED_BUILTIN_PIN			(5)		/*As the built-in led is connected to PA5*/
#define LED_RED_PIN				(0)		/*As red 		  led is connected to PA0*/
#define LED_GREEN_PIN			(1)		/*As green 		  led is connected to PA1*/
#define LED_BLUE_PIN			(4)		/*As blue 		  led is connected to PA4*/

#define LED_BUILTIN_MODE_BIT	(1<<(LED_BUILTIN_PIN*2U)) /*10: As every pin takes 2 bits in MODER register*/
#define LED_RED_MODE_BIT		(1<<(LED_RED_PIN*2U)) /*0 : As every pin takes 2 bits in MODER register*/
#define LED_GREEN_MODE_BIT		(1<<(LED_GREEN_PIN*2U))	/*2 : As every pin takes 2 bits in MODER register*/
#define LED_BLUE_MODE_BIT		(1<<(LED_BLUE_PIN*2U))	/*8 : As every pin takes 2 bits in MODER register*/

typedef enum 
{
	RED = 0,
	GREEN,
	BLUE,
	BUILTIN
}LedColor_Type;
typedef enum 
{
	OFF = 0,
	ON
}LedState_Type;

/*LED's attribute*/
 class Led
{
	private:
		LedColor_Type color; 		/* Color of LED*/
		LedState_Type state;		/* State of LED*/
	public:
		Led(LedColor_Type _color, LedState_Type _state);
		void setState(LedState_Type _state);
		LedState_Type getState(void)const;	
};

#endif
