#include "stm32f4xx.h"                  // Device header
#include <stdio.h>
#include "retarget_stm32f4xx.h"

void delay_ms(int);

int main(){
	char superBuffer[80];
	UART2_init();
	while(1){
		delay_ms(0xFFFFF);
		printf("Comando: ");
		gets(superBuffer);
		printf(">>%s\n",superBuffer);
	}
	//return 0;
}


void delay_ms(int delay_time){
	int i;
	for(i=0;i<delay_time;i++){
	}
}
