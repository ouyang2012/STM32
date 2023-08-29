#ifndef	__INTERRUPT_H
#define __INTERRUPT_H
void Interrupt_Init(void);
uint16_t GetCount(void);
void EXTI15_10_IRQHandler(void);
#endif
