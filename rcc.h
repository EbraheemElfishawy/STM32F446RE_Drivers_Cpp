#ifndef _RCC_H
#define _RCC_H
#include <stdio.h>
#include "stm32f446re.h"

enum RCC_ErrorType_t
{
	RCC_OK,
	RCC_NOK,
	RCC_DEFAULT_ERR=0xFF
};
enum RCC_GpioPortName_t
{
	RCC_GPIO_PORT_A,
	RCC_GPIO_PORT_B,
	RCC_GPIO_PORT_C,
	RCC_GPIO_PORT_D,
	RCC_GPIO_PORT_E,
	RCC_GPIO_PORT_H
};
class RCC_Configs
	
{
	public:
		
	private:
		
};
class rcc
{
	private:
		
	public:
        RCC_ErrorType_t rccErr;
		rcc();
		RCC_ErrorType_t RCC_gpioPortInit(RCC_GpioPortName_t gpioPortName);

};

#endif
