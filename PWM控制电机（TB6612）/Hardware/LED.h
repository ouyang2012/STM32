#ifndef	__LED_H
#define	__LED_H

void	LED_Init(void);

void	LED1_ON(void);
void	LED1_OFF(void);
void	LED1_Turn(void);
void	LED2_ON(void);
void	LED2_OFF(void);
void	LED2_Turn(void);
uint16_t LED_Set(uint16_t LED,uint16_t Mode);

#endif
