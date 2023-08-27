#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

void Motor_SetSpeed(void)
{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);//左轮正转
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	
		GPIO_SetBits(GPIOA, GPIO_Pin_3);//右轮胎正转
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		GPIO_Configuration(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
	  TIM2_PWM_Init(100, 10, 10);
}

void Motor_SetSpeed2(void)
{
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		GPIO_Configuration(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
	  TIM2_PWM_Init(100, 10, 15);
}
