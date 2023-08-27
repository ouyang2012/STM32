#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "Motor.h"


int main(void)
{
	OLED_Init();
	Motor_Init();
	OLED_ShowString(1,1,"Speed:");

	while(1)
	{
		Motor_SetSpeed();
	}
}
