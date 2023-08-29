#include "stm32f10x.h"


/**
  * @定义  输出两路不同占空比的PWM波
  * @参数  period: 这个参数表示 PWM 信号的周期。周期决定了 PWM 信号的频率。你需要根据实际需求选择适当的周期值。
  * @参数  pulse1: 这个参数表示 PWM 信号的脉冲值，用于设置第一个 PWM 信号的占空比。脉冲值决定了 PWM 信号的占空比。
	* @参数  pulse2: 类似于 pulse1，但这个参数用于设置第二个 PWM 信号的占空比。
  * @返回值 无
  */
void TIM2_PWM_Init(uint16_t period, uint16_t pulse1, uint16_t pulse2) {
    // 初始化定时器2
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    // 定时器配置
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_Prescaler = 36 - 1; // 设置预分频器，得到1MHz的时钟
    TIM_TimeBaseInitStruct.TIM_Period = period - 1; // 设置周期，决定PWM信号的频率
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
    
    // PWM模式配置 - 通道1
    TIM_OCInitTypeDef TIM_OCInitStruct1;
    TIM_OCInitStruct1.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct1.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct1.TIM_Pulse = pulse1; // 设置脉冲值，决定PWM信号的占空比
    TIM_OCInitStruct1.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM2, &TIM_OCInitStruct1);
    
    // PWM模式配置 - 通道2
    TIM_OCInitTypeDef TIM_OCInitStruct2;
    TIM_OCInitStruct2.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct2.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct2.TIM_Pulse = pulse2; // 设置脉冲值，决定PWM信号的占空比
    TIM_OCInitStruct2.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC2Init(TIM2, &TIM_OCInitStruct2);
    
    // 启动定时器
    TIM_Cmd(TIM2, ENABLE);
}

/**
  * @定义  指定GPIO口不同占空比的PWM波
  * @参数  GPIO_TypeDef *GPIOx: 这是一个指向 GPIO_TypeDef 结构体的指针。
  * @参数  GPIO_TypeDef : 通过这个参数，你可以传递一个指向具体 GPIO 端口（如 GPIOA、GPIOB 等）的指针。
	* @参数  uint16_t GPIO_Pin: 这是一个代表 GPIO 引脚的变量。在 STM32 中，每个 GPIO 端口有多个引脚，用数字标识。
					 例如，对于 GPIOA 端口，GPIO_Pin_0 表示 GPIOA 的第 0 号引脚。
  * @返回值 无
  */
void GPIO_Configuration(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    // 配置指定的GPIO为复用输出模式
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin; // 要配置的GPIO引脚
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出模式
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &GPIO_InitStruct);
}

//int main(void) {
//    // 初始化系统时钟等
//    
//    // 配置GPIO为复用输出模式
//    GPIO_Configuration(GPIOA, GPIO_Pin_0); // 选择GPIOA Pin 0作为输出
//    GPIO_Configuration(GPIOB, GPIO_Pin_0); // 选择GPIOB Pin 0作为输出
//    
//    // 初始化PWM
//    TIM2_PWM_Init(1000, 500, 250); // 1000作为周期，500和250作为脉冲值，即50%和25%占空比
//    
//    while (1) {
//        // 主循环
//    }
//}
