#include "bsp_SysTick.h"
unsigned long TimingDelay;



void SysTick_Configuration(void)
{
	//库函数
	//使用AHB时钟72MHz,并进入中断
	//参数：分频；设置为SystemCoreClock / 1000000 = 72 ， 72 / 72MHz = 1/1000000s = 1us
	SysTick_Config(SystemCoreClock / 1000000);
	//关闭时钟
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}



//微秒
void delay_us(int time)
{
	TimingDelay =time;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;//使能
	while(TimingDelay != 0);
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;//失能
}




