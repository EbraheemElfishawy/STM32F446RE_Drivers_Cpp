#include "Led.h"

Led::Led(LedColor_Type _color, LedState_Type _state)
/*Option 2*/
// :color(_color),
//  state(_state)
{
    /*Option 1*/
    this->state = _state;
    this->color = _color;
		/*Hardware  init*/
		RCC->AHB1ENR |= LED_PORT_CLOCK;
		switch (this->color)
    {
    case RED    :
			// LED_PORT->MODER &= ~(uint32_t)((3)<<LED_RED_MODE_BIT);
			LED_PORT->MODER |=  (uint32_t)(LED_RED_MODE_BIT);
		
			LED_PORT->ODR   &= ~(uint32_t)(1<<LED_RED_PIN);
			LED_PORT->ODR   |=  (uint32_t)((this->state) << (LED_RED_PIN));
			break;
    case GREEN  :
			// LED_PORT->MODER &= ~(uint32_t)((3)<<LED_GREEN_MODE_BIT);
			LED_PORT->MODER |=  (uint32_t)(LED_GREEN_MODE_BIT);
		
			LED_PORT->ODR   &= ~(uint32_t)(1<<LED_GREEN_PIN);
			LED_PORT->ODR   |=  (uint32_t)((this->state) << (LED_GREEN_PIN));
			break;
    case BLUE   :
			// LED_PORT->MODER &= ~(uint32_t)((3)<<LED_BLUE_MODE_BIT);
			LED_PORT->MODER |=  (uint32_t)(LED_BLUE_MODE_BIT);
		
			LED_PORT->ODR   &= ~(uint32_t)(1<<LED_BLUE_PIN);
			LED_PORT->ODR   |=  (uint32_t)((this->state) << (LED_BLUE_PIN));
            break;
		case BUILTIN :
			// LED_PORT->MODER &= ~(uint32_t)((3)<<LED_BUILTIN_MODE_BIT);
			LED_PORT->MODER |=  (uint32_t)(LED_BUILTIN_MODE_BIT);
		
			LED_PORT->ODR   &= ~(uint32_t)(1<<LED_BUILTIN_PIN);
			LED_PORT->ODR   |=  (uint32_t)((this->state) << (LED_BUILTIN_PIN));
            break;
    default:
        break;
    }
}
void Led::setState(LedState_Type _state)
{
    this->state = _state;

    switch (this->color)
    {
    case RED    :
        LED_PORT->ODR   &= ~(uint32_t)(1<<LED_RED_PIN);
		LED_PORT->ODR   |=  (uint32_t)((this->state) << (LED_RED_PIN)); break;
    case GREEN  :
        LED_PORT->ODR   &= ~(uint32_t)(1<<LED_GREEN_PIN);
		LED_PORT->ODR   |=  (uint32_t)((this->state) << (LED_GREEN_PIN));
        break;
    case BLUE   :
        LED_PORT->ODR   &= ~(uint32_t)(1<<LED_BLUE_PIN);
		LED_PORT->ODR   |=  (uint32_t)((this->state) << (LED_BLUE_PIN));
        break;
    default:
        break;
    }
}
LedState_Type Led::getState(void)const
{
	switch (this->color)
    {
    case RED    : break;
    case GREEN  : break;
    case BLUE   : break;
    default:
        break;
    }
    return this->state;
}