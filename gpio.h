#ifndef _GPIO_H
#define _GPIO_H
#include <stdio.h>
#include "stm32f446re.h"

enum GPIO_ErrorType_t
{
	GPIO_OK,
	GPIO_NOK,
	GPIO_DEFAULT_ERR=0xFF
};
enum GPIO_PortName_t
{
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D,
	GPIO_PORT_E,
	GPIO_PORT_H
};
enum GPIO_PinState_t
{
	GPIO_PIN_STATE_HIGH,
	GPIO_PIN_STATE_LOW,
	GPIO_PIN_STATE_DEFAULT=0xFF
};
enum GPIO_PinNumber_t
{
	GPIO_PIN_0 ,GPIO_PIN_1 ,GPIO_PIN_2 ,GPIO_PIN_3,
	GPIO_PIN_4 ,GPIO_PIN_5 ,GPIO_PIN_6 ,GPIO_PIN_7,
	GPIO_PIN_8 ,GPIO_PIN_9 ,GPIO_PIN_10,GPIO_PIN_11,
	GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15
};
class GPIO_PinConfigs
{
	public:
		GPIO_PortName_t  portName;
		GPIO_PinNumber_t pinNumber;
		GPIO_PinState_t  pinState;
	private:
		
};
class gpio
{
	
	private:
		
		
	
	
	public:
		GPIO_ErrorType_t gpioErr;
		gpio(GPIO_PortName_t PortName);
		GPIO_PinState_t  GPIO_PinStateGet(GPIO_PinConfigs* pinConfigs);
		GPIO_ErrorType_t GPIO_PinStateSet(GPIO_PinConfigs* pinConfigs, GPIO_PinState_t pinState);
		GPIO_ErrorType_t GPIO_PinStateTog(GPIO_PinConfigs* pinConfigs);

	
};

#endif