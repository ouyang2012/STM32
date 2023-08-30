#ifndef __PWM_H
#define __PWM_H

void GPIO_Configuration(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void TIM2_PWM_Init(uint16_t period, uint16_t pulse1, uint16_t pulse2); 

#endif
