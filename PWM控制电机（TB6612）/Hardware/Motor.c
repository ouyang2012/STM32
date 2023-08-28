#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

void Motor_Mode1(void)
{
			GPIO_SetBits(GPIOA, GPIO_Pin_5);//左轮正转
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
			GPIO_SetBits(GPIOA, GPIO_Pin_3);//右轮正转
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
			GPIO_Configuration(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
			TIM2_PWM_Init(100, 10, 10);
}
void Motor_SetSpeed(uint8_t Start)
{
	if(Start==1)//前进
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_5);//左轮正转
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
			GPIO_SetBits(GPIOA, GPIO_Pin_3);//右轮正转
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
			GPIO_Configuration(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
			TIM2_PWM_Init(100, 10, 10);
		}
	if(Start==2)//后退
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_4);//左轮反转
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			GPIO_SetBits(GPIOA, GPIO_Pin_2);//右轮反转
			GPIO_ResetBits(GPIOA, GPIO_Pin_3);
			GPIO_Configuration(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
			TIM2_PWM_Init(100, 10, 10);		
		}
	if(Start==3)//右转
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_5);//左轮正转
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
			GPIO_SetBits(GPIOA, GPIO_Pin_2);//右轮反转
			GPIO_ResetBits(GPIOA, GPIO_Pin_3);
			GPIO_Configuration(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
			TIM2_PWM_Init(100, 10, 10);
		}
	if(Start==4)//左转
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_4);//左轮反转
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			GPIO_SetBits(GPIOA, GPIO_Pin_3);//右轮正转
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
			GPIO_Configuration(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
			TIM2_PWM_Init(100, 10, 10);
		}
	if(Start==5)//停止
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);//左轮停止
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);//右轮停止
			GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		}
}

//void Motor_SetSpeed2(uint8_t Start2)
//{
//    switch (Start2) {
//        case 1: // 前进
//            GPIO_SetBits(GPIOA, GPIO_Pin_5);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_4);
//            GPIO_SetBits(GPIOA, GPIO_Pin_3);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_2);
//            GPIO_Configuration(GPIOA, GPIO_Pin_0 | GPIO_Pin_1);
//            TIM2_PWM_Init(100, 10, 10);
//            break;

//        case 2: // 后退
//            GPIO_SetBits(GPIOA, GPIO_Pin_4);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_5);
//            GPIO_SetBits(GPIOA, GPIO_Pin_2);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_3);
//            GPIO_Configuration(GPIOA, GPIO_Pin_0 | GPIO_Pin_1);
//            TIM2_PWM_Init(100, 10, 10);
//            break;

//        case 3: // 右转
//            GPIO_SetBits(GPIOA, GPIO_Pin_5);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_4);
//            GPIO_SetBits(GPIOA, GPIO_Pin_2);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_3);
//            GPIO_Configuration(GPIOA, GPIO_Pin_0 | GPIO_Pin_1);
//            TIM2_PWM_Init(100, 10, 10);
//            break;

//        case 4: // 左转
//            GPIO_SetBits(GPIOA, GPIO_Pin_4);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_5);
//            GPIO_SetBits(GPIOA, GPIO_Pin_3);
//            GPIO_ResetBits(GPIOA, GPIO_Pin_2);
//            GPIO_Configuration(GPIOA, GPIO_Pin_0 | GPIO_Pin_1);
//            TIM2_PWM_Init(100, 10, 10);
//            break;

//        case 5: // 停止
//            GPIO_ResetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);
//            break;
//    }
//}
