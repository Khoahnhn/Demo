
/*
  ******************************************************************************
  * @file		abc.c                                                              *
  * @author	Nguyen Quang Bien                                                  *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/
#include "GPIO.h" 
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
GPIO_InitTypeDef GPIO_Phuc; 
void Config_GPIO(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Phuc.GPIO_Pin = GPIO_Pin_2;
	GPIO_Phuc.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Phuc.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Phuc);   
}
void On(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}
void Off(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

/********************************* END OF FILE ********************************/
/******************************************************************************/
