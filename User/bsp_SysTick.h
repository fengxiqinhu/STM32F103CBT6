///////////////////////////////////////////////////////////////////////////
//	
//	名称：系统时钟SysTick,嘀嗒计数器
//
/***************************************************************************/



#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__
#include <stm32f10x.h>

void SysTick_Configuration(void);

void delay_us(int time);
#endif


