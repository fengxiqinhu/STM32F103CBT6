#include "bsp_SysTick.h"
unsigned long TimingDelay;



void SysTick_Configuration(void)
{
	//�⺯��
	//ʹ��AHBʱ��72MHz,�������ж�
	//��������Ƶ������ΪSystemCoreClock / 1000000 = 72 �� 72 / 72MHz = 1/1000000s = 1us
	SysTick_Config(SystemCoreClock / 1000000);
	//�ر�ʱ��
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}



//΢��
void delay_us(int time)
{
	TimingDelay =time;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;//ʹ��
	while(TimingDelay != 0);
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;//ʧ��
}




