#include "stm32f10x.h"
#include "Delay.h"
uint16_t Count;
void Interrupt_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitTypeDef	GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource13);
	
	EXTI_InitTypeDef	EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line		=EXTI_Line13;
	EXTI_InitStruct.EXTI_LineCmd	=ENABLE;
	EXTI_InitStruct.EXTI_Mode		=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger 	=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef	NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel						=EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			=1;
	NVIC_Init(&NVIC_InitStruct);
}

uint16_t GetCount(void)
{
	return	Count;
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line13)==SET)
	{
		Delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==1)
		{
			Count++;
		}
		EXTI_ClearITPendingBit(EXTI_Line13);
		
	}

}
