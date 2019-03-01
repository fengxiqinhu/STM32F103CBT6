///////////////////////////////////////////////////////////////////////////
//	
//	名称		：系统时钟SysTick,嘀嗒计数器
//	开发板	：Open103C
//
/***************************************************************************/



#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__
#include <stm32f10x.h>

void SysTick_Init(void);

void delay_us(int time);
#endif


