#include "rcc.h"


/**
 * @brief This pointer is intentionally used to make it easy to watch RCC registers 
 * from live watch using debugger 
 */
RCC_TypeDef* RCC_MemoryMapBase = (RCC_TypeDef*) RCC_BASE;


/**
 * @brief This is the default constructor which is used to
 * 
 * @param 
 */
rcc::rcc()
{
	rccErr = RCC_OK;
	
}
/**
 * @brief This public function is used to initialize clock for
 * GPIO ports
 * @param gpioPortName 
 * @return RCC_ErrorType_t 
 */
RCC_ErrorType_t rcc::RCC_gpioPortInit(RCC_GpioPortName_t gpioPortName)
{
    RCC_ErrorType_t errReturn = RCC_DEFAULT_ERR;
    switch(gpioPortName)
	{
		case RCC_GPIO_PORT_A:
			RCC_MemoryMapBase->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
            errReturn = RCC_OK;
		    break;
		case RCC_GPIO_PORT_B:
			RCC_MemoryMapBase->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
            errReturn = RCC_OK;
		    break;
		case RCC_GPIO_PORT_C:
			RCC_MemoryMapBase->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
            errReturn = RCC_OK;
		    break;
		case RCC_GPIO_PORT_D:
			RCC_MemoryMapBase->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
            errReturn = RCC_OK;
		    break;
		case RCC_GPIO_PORT_E:
			RCC_MemoryMapBase->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
            errReturn = RCC_OK;
		    break;
		case RCC_GPIO_PORT_H:
			RCC_MemoryMapBase->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
            errReturn = RCC_OK;
		    break;
		default:
            errReturn = RCC_DEFAULT_ERR;
            break;
	}
    return errReturn;
}