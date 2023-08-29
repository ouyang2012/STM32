#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "Motor.h"
#include "Reflective.h"
#include "Serial.h"
uint8_t RxData;
int main(void)
{
	OLED_Init();
	Motor_Init();
	OLED_ShowString(1, 1, "RxData:");
	Reflective_Init();
	Serial_Init();
	LED_Init();
	while(1)
	{
		if (Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			if(RxData == 0x05)
			{
				Motor_SetSpeed(5);
			}
			if(RxData == 0x01)
			{
				Motor_SetSpeed(1);
			}
			if(RxData == 0x02)
			{
				Motor_SetSpeed(4);
			}
			if(RxData == 0x03)
			{
				Motor_SetSpeed(3);
			}
			if(RxData == 0x04)
			{
				Motor_SetSpeed(2);
			}
			//Serial_SendByte(RxData);
			OLED_ShowHexNum(1, 8, RxData, 2);
		}
	}
}
