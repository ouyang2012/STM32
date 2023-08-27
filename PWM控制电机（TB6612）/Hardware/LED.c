#include "stm32f10x.h"                  // Device header

void	LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_Write( GPIOE, ~0x0000);
}

void	LED1_ON(void)
{
	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
}

void	LED1_OFF(void)
{
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}
void	LED1_Turn(void)
{
	if((GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin_5)) == 0)
	{
		
		GPIO_SetBits(GPIOE,GPIO_Pin_5);
	}
	else
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
}
void	LED2_ON(void)
{
	GPIO_ResetBits(GPIOE,GPIO_Pin_6);
}

void	LED2_OFF(void)
{
	GPIO_SetBits(GPIOE,GPIO_Pin_6);
}
void	LED2_Tutn(void)
{
	if((GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin_6)) == 0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_6);
	}
	else
		GPIO_ResetBits(GPIOE,GPIO_Pin_6);
}

uint16_t LED_Set(uint16_t LED,uint16_t Mode)
{
	uint16_t i;
	switch(LED)
	{
		case 1 : i=GPIO_Pin_5; break;
		case 2 : i=GPIO_Pin_6; break;
	}
	if(Mode == 1)
	{
		GPIO_SetBits(GPIOE,i);
	}
	if(Mode == 0)
	{
		GPIO_ResetBits(GPIOE,i);
	}
	
	return 0;
}
