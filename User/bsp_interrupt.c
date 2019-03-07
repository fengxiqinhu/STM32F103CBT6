#include "bsp_interrupt.h"

//中断示例1配置
void Interrupt_demo1_Configuration(void)
{
	NVIC_Configuration();
	EXTI_Configuration();
	Gpio_configuration();
}


void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//设置中断优先级模式为第一组
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//配置EXTI0线
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


//配置EXTI外部中断线
//使能GPIOA时钟与GPIOA复用时钟
//EXTI0连接PA0,配置下降沿中断
//PA0配上拉输入
void EXTI_Configuration(void)
{
	RCC_AFIOClock_ENABLE;
	RCC_GPIOAClock_ENABLE;
	
	EXTI_InitTypeDef EXTI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;//外部中断线 0 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿中断
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//设置 EXTI 线路为中断请求 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

//中断服务
//demo1：使用按键连接PA0，复用EXTI0触发中断，控制灯的亮灭
void EXTI0_IRQHandler(void)
{
	//检测中断发生与否
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		LED_OpenOrClose(GPIOA,  GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 );
		//清除中断标志位
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}



