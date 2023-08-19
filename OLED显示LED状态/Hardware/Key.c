#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void	Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef	GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);

}

int Key_Number(void)
{
	uint8_t	Key_Num;
	if((GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1))==0)
	{
		Delay_ms(20);
		while((GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1))==0);
		Delay_ms(20);
		Key_Num=1;
	}
	return	Key_Num;
}
