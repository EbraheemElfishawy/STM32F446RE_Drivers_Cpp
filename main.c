#include "uart.h"

int main()
{
	USART2_Init();
	test_setup();
	while(1)
	{
		//printf("The nuber entered is: %d \r\n");
	}
	
}
