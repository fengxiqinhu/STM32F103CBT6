///////////////////////////////////////////////////////////////////////////
//	
//	功能：gpio外设代码示例
//
/***************************************************************************/

#ifndef __BSP_INTERRUPT_H__
#define __BSP_INTERRUPT_H__
#include <stm32f10x.h>
#include "RCC_OR_CMD.h"
#include "bsp_SysTick.h"

#include "bsp_led.h"

void Interrupt_demo1_Configuration(void);
void NVIC_Configuration(void);
void EXTI_Configuration(void);
#endif

