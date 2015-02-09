#include "retarget_stm32f4xx.h"

int sendchar(int ch){
	while((USART2->SR&(0x1<<7))==0);
	USART2->DR=(char) ch;
	return ch;
}

int  getkey(void){
	while(!((USART2->SR)&(0x1<<5)));//loop if RXNE = 0 (data has not been received)
	return USART2->DR;
} 

void UART2_init(void){
	RCC->AHB1ENR|=(0x1);//Turn on GPIOA
	RCC->APB1ENR|=(0x1<<17);//Turn on USART2
	
	//configure GPIOA  A2, A3 for UART type functions
	GPIOA->MODER&=~((0x3<<4)|(0x3<<6));
	GPIOA->MODER|=((0x2<<4)|(0x2<<6));
	GPIOA->AFR[0]|=((0x7<<8)|(0x7<<12)); //A2=Tx A3=Rx
	GPIOA->PUPDR|=(0x1<<6);//A3 with Pull ups
	//configure UART
	//Configure Baud Rate
	USART2->BRR|=(0xCC<<4)|(0x1);//intdiv=0xCC frac_div=0x1 freqin=9600bps 
	USART2->CR1|=(0x1<<15) //OVER8;
								|(0x1<<13)//UE =1
								|(0x1<<3)//TEN =1
								|(0x1<<2);//REN =1				  
}
