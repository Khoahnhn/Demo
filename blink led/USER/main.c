#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "GPIO.h"

GPIO_InitTypeDef phuctran;
void config(void);

void delay()
{
	int i;
	for(i=0;i<1000000;i++);	
}

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	config();
	while(1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_9);
		GPIO_ResetBits(GPIOA,GPIO_Pin_10);
	//	delay();
		
		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		
		
		delay();
		GPIO_SetBits(GPIOA,GPIO_Pin_9);
		GPIO_SetBits(GPIOA,GPIO_Pin_10);
		
	//	delay();
		
		
	//	delay();
		GPIO_SetBits(GPIOB,GPIO_Pin_1);
		delay();
			
	}
}

void config(void)
{
	//B5
	/*
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA,ENABLE);
	phuctran.GPIO_Pin=GPIO_Pin_5;
	phuctran.GPIO_Mode=GPIO_Mode_Out_PP;
	phuctran.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&phuctran);
	*/
	//A8
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	phuctran.GPIO_Pin=GPIO_Pin_9;
	phuctran.GPIO_Mode=GPIO_Mode_Out_PP;
	phuctran.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&phuctran);
	
	phuctran.GPIO_Pin=GPIO_Pin_10;
	phuctran.GPIO_Mode=GPIO_Mode_Out_PP;
	phuctran.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&phuctran);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	phuctran.GPIO_Pin=GPIO_Pin_1;
	phuctran.GPIO_Mode=GPIO_Mode_Out_PP;
	phuctran.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&phuctran);
	
}

