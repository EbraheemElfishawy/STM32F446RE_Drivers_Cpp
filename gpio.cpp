#include "gpio.h"
#include "rcc.h"
rcc GPIO_rcc_object;
GPIO_TypeDef* GPIO_RegArr[GPIO_PORT_MAX] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

/**
 * @brief Construct a new gpio pinconfigs::gpio pinconfigs object
 * 
 */
GPIO_PinConfigs::GPIO_PinConfigs()
{
	pinConfigsErr = GPIO_NOK;
	pinInitErr = GPIO_NOK;
}
/**
 * @brief Construct a new gpio pinconfigs::gpio pinconfigsisok object
 * 
 */
GPIO_ErrorType_t GPIO_PinConfigs::GPIO_PinConfigsIsOk()
{
	GPIO_ErrorType_t errReturn = GPIO_NOK;

	if((pinNumber<GPIO_PIN_MAX ) && (portName<GPIO_PORT_MAX))
	{
		pinConfigsErr = GPIO_OK;
		errReturn = GPIO_OK;
	}
	else
	{
		pinConfigsErr = GPIO_NOK;
		errReturn = GPIO_NOK;
	}

	return errReturn;
}


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
				GPIO_PortReg = GPIO_RegArr[PortName];
				GPIO_rcc_object.rccErr = RCC_OK;
			break;
			case GPIO_PORT_MAX:
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
/**
 * @brief the function  initialize the GPIO pin according to the input parameter
 * 
 * @param pinConfigs the initialization values of the pin
 * @return GPIO_ErrorType_t 
 */
GPIO_ErrorType_t gpio::GPIO_PinInit(GPIO_PinConfigs* pinConfigs)
{
	GPIO_ErrorType_t errReturn = GPIO_DEFAULT_ERR;

	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (gpioErr == GPIO_OK) && (pinConfigs->GPIO_PinConfigsIsOk() == GPIO_OK))	
	{
		/*1- Set GPIO Mode Input, Output, Analog, Alternate Function*/
		GPIO_PortReg->MODER &=~ (uint32_t) ( (MODER_MASK		  << ((pinConfigs->pinNumber)*MODER_PIN_ACCESS)) );
		GPIO_PortReg->MODER |=  (uint32_t) ( (pinConfigs->pinMode << ((pinConfigs->pinNumber)*MODER_PIN_ACCESS)) );

		/*2- Select GPIO Pull State: Pullup, Pulldown, Nopull state*/
		GPIO_PortReg->PUPDR &=~ (uint32_t) ( (PUPDR_MASK		  		<< ((pinConfigs->pinNumber)*PUPDR_PIN_ACCESS)) );
		GPIO_PortReg->PUPDR |=  (uint32_t) ( (pinConfigs->pinPullUpDown << ((pinConfigs->pinNumber)*PUPDR_PIN_ACCESS)) );

		/*3- Select Output Type, Output speed in case of general purpose output mode*/
		if(pinConfigs->pinMode == GPIO_PinMode_OUTPUT)
		{
			/*Select output type: Push-pull, Output drain*/
			GPIO_PortReg->OTYPER  &= ~(OTYPER_MASK 			   << (pinConfigs->pinNumber)*OTYPER_PIN_ACCESS ); //clear MODER pins
			GPIO_PortReg->OTYPER  |= ((pinConfigs->pinPullUpDown) << (pinConfigs->pinNumber)*OTYPER_PIN_ACCESS);

			/*Select output speed: Low, Medium, High, Very High*/
			GPIO_PortReg->OSPEEDR &= ~(OSPEEDR_MASK 	  << pinConfigs->pinNumber ); //clear MODER pins
			GPIO_PortReg->OSPEEDR |= ((pinConfigs->pinOutputSpeed) << (pinConfigs->pinNumber)*OSPEEDR_PIN_ACCESS);
			if (pinConfigs->pinState == GPIO_PIN_STATE_LOW)
			{
				GPIO_PortReg->ODR &= (uint32_t)(~(u8GPIO_ONE<<pinConfigs->pinNumber));
			}
			else if(pinConfigs->pinState == GPIO_PIN_STATE_HIGH)
			{
				GPIO_PortReg->ODR |= (uint32_t)(u8GPIO_ONE<<pinConfigs->pinNumber);
			}
			else
			{

			}
			pinConfigs->pinInitErr=GPIO_OK;
		}
		else if(pinConfigs->pinMode == GPIO_PinMode_ALTERNATE_FUNCTION)
		{
			uint8_t Local_u8RegNum 	  = (pinConfigs->pinNumber)/8;
			uint8_t Local_u8pinNumber = (pinConfigs->pinNumber)%8;
			/*Select output type: Push-pull, Output drain*/
			GPIO_PortReg->OTYPER  &= ~(OTYPER_MASK 			   << (pinConfigs->pinNumber)*OTYPER_PIN_ACCESS ); //clear MODER pins
			GPIO_PortReg->OTYPER  |= ((pinConfigs->pinPullUpDown) << (pinConfigs->pinNumber)*OTYPER_PIN_ACCESS);

			/*Select output speed: Low, Medium, High, Very High*/
			GPIO_PortReg->OSPEEDR &= ~(OSPEEDR_MASK 	  << pinConfigs->pinNumber ); //clear MODER pins
			GPIO_PortReg->OSPEEDR |= ((pinConfigs->pinOutputSpeed) << (pinConfigs->pinNumber)*OSPEEDR_PIN_ACCESS);

			/*Select The Pin Alternate Function*/
			
			GPIO_PortReg->AFR[Local_u8RegNum] &= ~(AFR_MASK << Local_u8pinNumber *AFR_PIN_ACCESS); //clear MODER pins
			GPIO_PortReg->AFR[Local_u8RegNum] |= ((pinConfigs->pinAltFunc) << (Local_u8pinNumber * AFR_PIN_ACCESS));

			pinConfigs->pinInitErr=GPIO_OK;
		}
		else
		{
			pinConfigs->pinInitErr=GPIO_NOK;
		}
	}
	else
	{
		errReturn = GPIO_DEFAULT_ERR;
		pinConfigs->pinInitErr = GPIO_NOK;
	}
	return errReturn;
}
/**
 * @brief 
 * 
 * @param pinConfigs 
 * @return GPIO_PinState_t 
 */
GPIO_PinState_t  gpio::GPIO_PinStateGet(GPIO_PinConfigs* pinConfigs)
{
	GPIO_PinState_t pinState = GPIO_PIN_STATE_DEFAULT;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (pinConfigs->pinInitErr == GPIO_OK))
	{
		pinState = (GPIO_PinState_t) ((GPIO_PortReg->IDR >> pinConfigs->pinNumber) & u8GPIO_ONE);
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
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (pinConfigs->pinInitErr == GPIO_OK))	
	{
		if (pinState == GPIO_PIN_STATE_LOW)
		{
			GPIO_PortReg->ODR &= (uint32_t)(~(u8GPIO_ONE<<pinConfigs->pinNumber));
		}
		else if(pinState == GPIO_PIN_STATE_HIGH)
		{
			GPIO_PortReg->ODR |= (uint32_t)(u8GPIO_ONE<<pinConfigs->pinNumber);
		}
	}
	else
	{
		errReturn = GPIO_DEFAULT_ERR;
	}
	return errReturn;
	
}
GPIO_ErrorType_t  gpio::GPIO_PinStateToggle(GPIO_PinConfigs* pinConfigs)
{
	GPIO_ErrorType_t errReturn = GPIO_DEFAULT_ERR;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (pinConfigs->pinInitErr == GPIO_OK))	
	{
		GPIO_PortReg->ODR ^= (uint32_t)(u8GPIO_ONE<<pinConfigs->pinNumber);
	}
	else
	{
		errReturn = GPIO_DEFAULT_ERR;
	}
	return errReturn;
	
}