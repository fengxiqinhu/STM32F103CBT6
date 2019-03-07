#include "bsp_interrupt.h"

//�ж�ʾ��1����
void Interrupt_demo1_Configuration(void)
{
	NVIC_Configuration();
	EXTI_Configuration();
	Gpio_configuration();
}


void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//�����ж����ȼ�ģʽΪ��һ��
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//����EXTI0��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


//����EXTI�ⲿ�ж���
//ʹ��GPIOAʱ����GPIOA����ʱ��
//EXTI0����PA0,�����½����ж�
//PA0����������
void EXTI_Configuration(void)
{
	RCC_AFIOClock_ENABLE;
	RCC_GPIOAClock_ENABLE;
	
	EXTI_InitTypeDef EXTI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;//�ⲿ�ж��� 0 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½����ж�
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//���� EXTI ��·Ϊ�ж����� 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

//�жϷ���
//demo1��ʹ�ð�������PA0������EXTI0�����жϣ����ƵƵ�����
void EXTI0_IRQHandler(void)
{
	//����жϷ������
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		LED_OpenOrClose(GPIOA,  GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 );
		//����жϱ�־λ
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}



