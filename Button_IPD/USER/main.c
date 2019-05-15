#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "GPIO.h"
#include "stm32f10x.h"
#include "misc.h"
#define LED GPIO_Pin_5
#define BUTTON GPIO_Pin_3

GPIO_InitTypeDef  GPIO_InitStructure;
void Fn_GPIO_Init1 (void);
int main (void){
	SystemInit();
	SystemCoreClockUpdate();
	Fn_GPIO_Init1();
	while(1){
		if(GPIO_ReadInputDataBit(GPIOA, BUTTON) == 1){
			GPIO_WriteBit(GPIOA, LED, Bit_RESET);
		}
		else{
			GPIO_WriteBit(GPIOA, LED, Bit_SET);
		}
	}
}
void Fn_GPIO_Init1 (void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//led A5
	GPIO_InitStructure.GPIO_Pin = LED;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//button A3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin = BUTTON ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
