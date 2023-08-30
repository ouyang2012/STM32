#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "Motor.h"
#include "Reflective.h"
#include "Serial.h"
uint8_t RxData;
uint8_t Car_Mode =0x01;
int main(void)
{
	OLED_Init();
	Motor_Init();
	OLED_ShowString(1, 1, "RxData:");
	OLED_ShowString(2, 1, "Car_Mode:");
	Reflective_Init();
	Serial_Init();
	LED_Init();
	while(1)
	{
		uint8_t Num;
		uint8_t Num2;
		Num = ReflectiveNumname();
		Num2 = ReflectiveNumname2();
		if (Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			if(RxData == 0x06)//手动模式
			{
					Motor_SetSpeed(5);
					Car_Mode = 0x01;
			}
			else if(RxData == 0x07)//循迹模式
			{
					Motor_SetSpeed(5);
					Car_Mode = 0x02;
			}
			else
			{
					Car_Mode = Car_Mode;
			}
			/*手动模式*/
			if(Car_Mode == 0x01)
			{
				switch(RxData)
				{
					case	0x01	:	Motor_SetSpeed(1); break;//前进
					case	0x02	:	Motor_SetSpeed(2); break;//后退
					case	0x03	:	Motor_SetSpeed(3); break;//右转
					case	0x04	:	Motor_SetSpeed(4); break;//左转
					case	0x05	:	Motor_SetSpeed(5); break;//停止
				}
			}
			/*循迹模式*/
			if(Num == 1 && Num2 == 1&& Car_Mode == 0x02)
			{
				Motor_SetSpeed(1);

			}
			if(Num == 0 && Num2 == 1&& Car_Mode == 0x02)
			{
				Motor_SetSpeed(4);
			}
			if(Num == 1 && Num2 == 0&& Car_Mode == 0x02)
			{
			
				Motor_SetSpeed(3);
			}
			if(Num == 0 && Num2 == 0&& Car_Mode == 0x02)
			{
				Motor_SetSpeed(5);
			}		
			//Serial_SendByte(RxData);
			OLED_ShowHexNum(1, 8, RxData, 2);
			OLED_ShowHexNum(2, 10, Car_Mode, 2);
		}
	}
}
