///////////////////////////////////////////////////////////////////////////
//	
//	功能：Open103C按键实现
//
/***************************************************************************/



#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__
#include <stm32f10x.h>
#include "RCC_OR_CMD.h"

#include "bsp_led.h"


void key_Configuration(void);
int key(void);
void key_demo1(void);
#endif

