#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "interrupt.h"
#include "OLED.h"


int main(void)
{
	OLED_Init();
	Interrupt_Init();

	OLED_ShowString(1,1,"Count:");
	while (1)
	{
		OLED_ShowNum(1,7,GetCount(),5);
	}
}
