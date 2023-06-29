

#include "uart.h"
/*We have to use UASRT2 specifically as it is the only channel connected to STlink com port*/
void USART2_Init(void)
{
/*1- Enable clock acsess to uart */
	/*USART2 is connected through bus: APB1
	To enable clock acces of USART2 from bit (17) USART2EN in register RCC_APB1ENR
	*/
	RCC->APB1ENR |= 1<<17;
/*2- Enable clock acsess to portA
	portA is connected through bus: AHB1
	To enable clock acces of portA from bit (0) in register RCC_AHB1ENR
	(for USART2 tx(PA2),rx(PA3) pins)
	*/
	RCC->AHB1ENR |= 1<<0;
	/*3- Enable pins for alternate function, (for USART2 tx(PA0),rx(PA1) pins)*/
	GPIOA->AFR[0] &= ~(uint32_t)(0x0000FF00);	/*Clear AFR[0] Low register*/
	GPIOA->AFR[0] |=  (uint32_t)(0x00000700); /*AFR[0] Low register: PA2: USART4_TX*/
	GPIOA->AFR[0] |=  (uint32_t)(0x00007000); /*AFR[0] Low register: PA3: USART4_RX*/
	/*4- Enable alternate function for PA2 and PA3 as alternate function*/
	GPIOA->MODER  &= ~(uint32_t)(0x000000F0);
	GPIOA->MODER  |=  (uint32_t)(0x00000020); 	/*PA3 as alternate function*/
	GPIOA->MODER  |=  (uint32_t)(0x00000080); 	/*PA2 as alternate function*/
	/*5- Configre USART2*/
	USART2->BRR   |= 0x0683;
	USART2->CR1   |= 0x000C;/*Enable TX(Bit 3 TE: Transmitter enable = 1) and RX(Bit 2 RE: Receiver enable = 1)*/
	USART2->CR2   |= 0x0000;/*Enable 1 stop bit( Bits 13:12 STOP: STOP bits = 00)*/
	USART2->CR3   |= 0x0000;
	USART2->CR1   |= 0x2000;/*Finally enble USART2(bit 13 UE: USART enable = 1)*/
}
uint16_t USART2_Write(uint16_t ch)
{
	while(!(USART2->SR & 0x0080)){}
	USART2->DR = (ch & 0xFF);
	return ch;
}
uint16_t USART2_Read(void)
{
	while(!(USART2->SR & 0x0020)){}
	return (uint16_t)(USART2->DR);
}
/* The code below is the interface to the standard I/O library.
 * All the I/o ae directed to the console.
 */
struct FILE 
{ 
	int handle; 
	/* Whatever you require here. If the only file you are using is */
  /* standard output using printf() for debugging, no file handling */
  /* is required. */
};
/* FILE is typedef'd in stdio.h. */
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};

int fgetc(FILE *f)
{
	int c;
	c = USART2_Read(); /*Read the character from console*/
	
	if(c == '\r') 		/* If '\r', after it is echoed, a '\n' is appended*/
	{
		USART2_Write((uint16_t)c);	/* echo*/
		c = '\n';
	}
	USART2_Write((uint16_t)c); 	/* echo*/
	return c;
}
int fputc(int c, FILE *f) 
{
  return (int) USART2_Write((uint16_t)c);/* Write the character to console*/
}

static int n;
static char str[80];

void test_setup(void)
{
	printf("Please enter a number: ");
	scanf("%d", &n);
	printf("The nuber entered is: %d \r\n",n);
	printf("Please type a character string: ");
	gets(str);
	printf("The entered character string is: ");
	puts(str);
  printf("\r\n");
}









