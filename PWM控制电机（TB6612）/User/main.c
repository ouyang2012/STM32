#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "Motor.h"
#include "Reflective.h"

int main(void)
{
	OLED_Init();
	Motor_Init();
	OLED_ShowString(1,1,"Speed:");
	Reflective_Init();
	while(1)
	{
		uint8_t Num;
		uint8_t Num2;
		Num = ReflectiveNumname();
		Num2 = ReflectiveNumname2();
		if(Num == 1 && Num2 == 1)
		{
				Motor_SetSpeed(1);
		}
		if(Num == 0 && Num2 == 1)
		{
				Motor_SetSpeed(4);
		}
		if(Num == 1 && Num2 == 0)
		{
				Motor_SetSpeed(3);
		}
		if(Num == 1 && Num2 == 0)
		{
				Motor_SetSpeed(3);
		}

	}
}
