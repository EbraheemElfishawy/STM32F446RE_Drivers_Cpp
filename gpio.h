#ifndef _GPIO_H
#define _GPIO_H
#include <stdio.h>
#include "stm32f446re.h"
#define u8GPIO_ONE	1

#define MODER_MASK     		0b11
#define MODER_PIN_ACCESS 	2

#define PUPDR_MASK     		0b11
#define PUPDR_PIN_ACCESS 	2

#define OTYPER_MASK     	0b1
#define OTYPER_PIN_ACCESS 	1


#define OSPEEDR_MASK     	0b11
#define OSPEEDR_PIN_ACCESS 	2


#define AFR_MASK     		0b1111
#define AFR_PIN_ACCESS 		4

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
	GPIO_PORT_H,
	GPIO_PORT_MAX
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
	GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15,
	GPIO_PIN_MAX
};

enum GPIO_PinMode_t
{
	GPIO_PinMode_INPUT=0,
	GPIO_PinMode_OUTPUT,
	GPIO_PinMode_ALTERNATE_FUNCTION,
	GPIO_PinMode_ANALOG
};// Check this in p187

enum GPIO_PinOutputSpeed_t
{
	GPIO_PinOutputSpeed_LOW=0,
	GPIO_PinOutputSpeed_MEDIUM,
	GPIO_PinOutputSpeed_FAST,
	GPIO_PinOutputSpeed_HIGH
};//p187

enum GPIO_PinOutputType_t
{
	GPIO_PinOutputType_PUSH_PULL=0,
	GPIO_PinOutputType_OPEN_DRAIN
};//p188

enum GPIO_PinPullUpDown_t
{
	GPIO_PinPullUpDown_NOPULL=0,
	GPIO_PinPullUpDown_PULLUP,
	GPIO_PinPullUpDown_PULLDOWN
};//p189

enum GPIO_PinAltFunc_t
{
	GPIO_PinAltFunc_AF0=0,
	GPIO_PinAltFunc_AF1,
	GPIO_PinAltFunc_AF2,
	GPIO_PinAltFunc_AF3,
	GPIO_PinAltFunc_AF4,
	GPIO_PinAltFunc_AF5,
	GPIO_PinAltFunc_AF6,
	GPIO_PinAltFunc_AF7,
	GPIO_PinAltFunc_AF8,
	GPIO_PinAltFunc_AF9,
	GPIO_PinAltFunc_AF10,
	GPIO_PinAltFunc_AF11,
	GPIO_PinAltFunc_AF12,
	GPIO_PinAltFunc_AF13,
	GPIO_PinAltFunc_AF14,
	GPIO_PinAltFunc_AF15
};//p189

class GPIO_PinConfigs
{
	public:
		GPIO_PinConfigs();
		GPIO_ErrorType_t GPIO_PinConfigsIsOk();
		GPIO_ErrorType_t pinConfigsErr;
		GPIO_ErrorType_t pinInitErr;
		GPIO_PortName_t  portName;
		GPIO_PinNumber_t pinNumber;
		GPIO_PinState_t  pinState			=GPIO_PIN_STATE_LOW;
		GPIO_PinMode_t   pinMode			=GPIO_PinMode_OUTPUT;
		GPIO_PinOutputSpeed_t pinOutputSpeed=GPIO_PinOutputSpeed_LOW;
		GPIO_PinOutputType_t  pinOutputType	=GPIO_PinOutputType_PUSH_PULL;
		GPIO_PinPullUpDown_t  pinPullUpDown	=GPIO_PinPullUpDown_NOPULL;
		GPIO_PinAltFunc_t pinAltFunc;
	private:
		
};
class gpio
{
	private:
		
	public:
		GPIO_ErrorType_t gpioErr;
		GPIO_TypeDef* GPIO_PortReg;
		gpio(GPIO_PortName_t PortName);
		GPIO_ErrorType_t GPIO_PinInit		(GPIO_PinConfigs* pinConfigs);
		GPIO_PinState_t  GPIO_PinStateGet	(GPIO_PinConfigs* pinConfigs);
		GPIO_ErrorType_t GPIO_PinStateSet	(GPIO_PinConfigs* pinConfigs, GPIO_PinState_t pinState);
		GPIO_ErrorType_t GPIO_PinStateToggle(GPIO_PinConfigs* pinConfigs);

	
};

#endif