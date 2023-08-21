#include "stm32f10x.h"   // 包含STM32F10x系列的设备头文件
#include "OLED.h"        // 包含OLED显示库的头文件
#include "Timer.h"       // 包含定时器库的头文件

// 定义时间结构体，包含年、月、日、时、分、秒
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} Time;

Time currentTime = {2023, 8, 21, 10, 8, 59};  // 初始时间

// 更新时间函数
void updateTime() {
    if (currentTime.second >= 60) {  // 如果秒数达到60
        currentTime.second = 0;  // 重置秒数
        currentTime.minute++;   // 分钟递增
        if (currentTime.minute >= 60) {  // 如果分钟达到60
            currentTime.minute = 0;  // 重置分钟
            currentTime.hour++;     // 小时递增
            if (currentTime.hour >= 24) {  // 如果小时达到24
                currentTime.hour = 0;  // 重置小时
                currentTime.day++;    // 日递增
                if (currentTime.day > 30) {  // 假设每月30天
                    currentTime.day = 1;   // 重置日
                    currentTime.month++;  // 月份递增
                    if (currentTime.month > 12) {  // 如果月份达到12
                        currentTime.month = 1;   // 重置月份
                        currentTime.year++;    // 年份递增
                    }
                }
            }
        }
    }
}

// 定时器2中断处理函数
void TIM2_IRQHandler(void) {
    if ((TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)) {
        currentTime.second++;  // 秒数递增
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);  // 清除定时器中断标志
    }
}

int main(void) {
    OLED_Init();   // 初始化OLED显示
    Timer_Init();  // 初始化定时器

    while (1) {
        updateTime();  // 更新时间

        // 在OLED屏幕上显示日期部分
        OLED_ShowNum(1, 1, currentTime.year, 4);  // 显示年份，占4位
        OLED_ShowString(1, 5, ":");  // 显示冒号
        OLED_ShowNum(1, 6, currentTime.month, 2);  // 显示月份，占2位
        OLED_ShowString(1, 8, ":");  // 显示冒号
        OLED_ShowNum(1, 9, currentTime.day, 2);  // 显示日期，占2位

        // 在OLED屏幕上显示时间部分
        OLED_ShowNum(2, 1, currentTime.hour, 2);  // 显示小时，占2位
        OLED_ShowString(2, 3, ":");  // 显示冒号
        OLED_ShowNum(2, 4, currentTime.minute, 2);  // 显示分钟，占2位
        OLED_ShowString(2, 6, ":");  // 显示冒号
        OLED_ShowNum(2, 7, currentTime.second, 2);  // 显示秒钟，占2位
    }
}
