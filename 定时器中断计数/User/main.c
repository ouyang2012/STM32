#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "interrupt.h"
#include "OLED.h"
#include "Timer.h"

uint16_t Num;

int main(void)
{
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1,1,"Count:");
	while (1)
	{

		OLED_ShowNum(1,7,Num,5);
	}
}
