#ifndef SYSTICK_TIMER_H_
#define SYSTICK_TIMER_H_
#include <stdio.h>
#include "stm32f446re.h"

#define STCR_MASK					0b1
#define STCR_CLKSOURCE_PIN_ACCESS 	2
#define STCR_TICKINT_PIN_ACCESS 	1
#define STCR_COUNTER_PIN_ACCESS 	0

#define HSI_FREQ  16000000UL
enum SYSTICK_ErrorType_t
{
	SYSTICK_OK,
	SYSTICK_NOK,
	SYSTICK_DEFAULT_ERR=0xFF
};
enum
{
	SYSTICK_AHB_8,
	SYSTICK_AHB
}SYSTICK_Source_t;
enum
{
	SYSTICK_TICKINT_ENABLED,
	SYSTICK_TICKINT_DISABLED
}SYSTICK_Interrupt_t;
enum
{
	SYSTICK_COUNTER_ENABLED,
	SYSTICK_COUNTER_DISABLED
}SYSTICK_Counter_t;
class SysTickConfigs
{
	public:
		SysTickConfigs();
		SysTickConfigsIsOk();
		SYSTICK_Source_t      clockSource;
		SYSTICK_Interrupt_t   sysTickInterruptEnable;
		SYSTICK_Counter_t	  systickCounterEnable;
	private:

}
class systickTimer
{
	public:
		systickTimer();
		SYSTICK_ErrorType_t SysTick_Init(SysTickConfigs_t *SysTickConfigs );
		SYSTICK_ErrorType_t SysTick_Start(uint32_t u32CopyValue_ms );
		SYSTICK_ErrorType_t SysTick_Delay_ms(uint32_t u32CopyDelayValue_ms );
		SYSTICK_ErrorType_t SysTick_voidSetCallBack(void (*Copy_Ptr)(void));
		//SYSTICK_ErrorType_t SysTick_Handler(void);
	private:

}
struct
{
	
}SysTickConfigs_t;



#endif /* SYSTICK_TIMER_H_ */