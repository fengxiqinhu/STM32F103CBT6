///////////////////////////////////////////////////////////////////////////
//	
//	���ܣ�
//		1.RCC����ʱ��ʹ����ʧ��
//		2.����ʹ����ʧ��
//
/***************************************************************************/

#ifndef __RCC_OR_CMD_H__
#define __RCC_OR_CMD_H__
#include <stm32f10x.h>


#define RCC_GPIOAClock_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE)
#define RCC_GPIOAClock_DISABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , DISABLE)

#define RCC_GPIOBClock_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE)
#define RCC_GPIOBClock_DISABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , DISABLE)

#define RCC_AFIOClock_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE)
#define RCC_AFIOBClock_DISABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , DISABLE)
#endif








