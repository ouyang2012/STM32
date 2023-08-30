#include "stm32f10x.h"                  // Device header
#include "Delay.h"


void Reflective_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}


uint8_t ReflectiveNumname(void)
{
	
	uint8_t Reflective_Num;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
	{
		//Delay_ms(20);
		Reflective_Num = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==1)
	{
		//Delay_ms(20);
		Reflective_Num = 0;
	}
	return Reflective_Num;
}
uint8_t ReflectiveNumname2(void)
{
	
	uint8_t Reflective_Num2;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0)
	{
		//Delay_ms(20);
		Reflective_Num2 = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==1)
	{
		//Delay_ms(20);
		Reflective_Num2 = 0;
	}
	return Reflective_Num2;
}
