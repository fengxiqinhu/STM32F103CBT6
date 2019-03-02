///////////////////////////////////////////////////////////////////////////
//	
//	名称		：gpio外设代码示例
//	开发板	：Open103C
//	引脚	：----------------------------------------------------------
//					PA1
//					PA2
//					PA3
//					PA4
//					----------------------------------------------------------
/***************************************************************************/

#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__
#include <stm32f10x.h>
#include "RCC_OR_CMD.h"
#include "bsp_SysTick.h"

void Gpio_configuration(void);
void LED_OpenOrClose(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void led_demo1(void);
void led_demo2(void);
void led_demo3(void);
#endif

