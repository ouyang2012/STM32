#include "stm32f10x.h"                  // Device header
#include "Delay.h"


void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}


uint8_t KeyNumname(void)
{
	
	uint8_t Key_Num;
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0);
		Delay_ms(20);
		Key_Num = 1;
	}
	
	return Key_Num;
}
