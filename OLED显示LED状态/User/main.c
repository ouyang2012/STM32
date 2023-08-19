#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	LED_Init();
	Key_Init();
	OLED_ShowString(1,1,"LED:");
	while (1)
	{
		LED_ON();
		OLED_ShowString(1,5,"ON");
		Delay_ms(500);
		OLED_ShowString(1,5,"   ");
		LED_OFF();
		OLED_ShowString(1,5,"OFF");
		Delay_ms(500);
		OLED_ShowString(1,5,"   ");
	}
}
