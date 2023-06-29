#ifndef __UART_H
#define __UART_H


#include <stdio.h>
#include "stm32f446re.h"

void 		 USART2_Init(void);
uint16_t USART2_Write(uint16_t ch);
uint16_t USART2_Read(void);

void test_setup(void);

#endif
