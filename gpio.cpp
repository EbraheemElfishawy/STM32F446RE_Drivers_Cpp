#include "gpio.h"
#include "rcc.h"
rcc GPIO_rcc_object;
/*This is the default constructor which is used to enable rcc clock for GPIO*/
gpio::gpio(GPIO_PortName_t PortName)
{
	gpioErr = GPIO_OK;
	if(GPIO_rcc_object.rccErr == RCC_OK)
	{
		switch(PortName)
		{
			case GPIO_PORT_A:
			case GPIO_PORT_B:
			case GPIO_PORT_C:
			case GPIO_PORT_D:
			case GPIO_PORT_E:
			case GPIO_PORT_H:
				GPIO_rcc_object.RCC_gpioPortInit((RCC_GpioPortName_t) PortName);
				GPIO_rcc_object.rccErr = RCC_OK;
			break;
			default:
				GPIO_rcc_object.rccErr = RCC_NOK;
				gpioErr = GPIO_NOK;
				break;
		}
	}
	else
	{

	}
	
	
}
GPIO_PinState_t   gpio::GPIO_PinStateGet(GPIO_PinConfigs* pinConfigs)
{
	GPIO_PinState_t pinState = GPIO_PIN_STATE_DEFAULT;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (gpioErr == GPIO_OK))
	{
		
	}
	else
	{
		pinState = GPIO_PIN_STATE_DEFAULT;
	}
		
	return pinState;
	
}
GPIO_ErrorType_t  gpio::GPIO_PinStateSet(GPIO_PinConfigs* pinConfigs, GPIO_PinState_t pinState)
{
	GPIO_ErrorType_t errReturn = GPIO_DEFAULT_ERR;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (gpioErr == GPIO_OK))	{
		
	}
	else
	{
		errReturn = GPIO_DEFAULT_ERR;
	}
	return errReturn;
	
}
GPIO_ErrorType_t  gpio::GPIO_PinStateTog(GPIO_PinConfigs* pinConfigs)
{
	GPIO_ErrorType_t errReturn = GPIO_DEFAULT_ERR;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (gpioErr == GPIO_OK))	{
		
	}
	else
	{
		errReturn = GPIO_DEFAULT_ERR;
	}
	return errReturn;
	
}