#include "bsp_key.h"



//������PA0 ����������
void key_Configuration(void)
{
	RCC_GPIOAClock_ENABLE;
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


//������⣬���PA0�����ѹ
//���أ���⵽��������1
int key(void)
{
		while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));
		delay_us(10000);//��һ�㰴��ʱ��Ϊ20����
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
			return 0;
		while(!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));
		return 1;

}

//ʾ��
void key_demo1(void)
{
	SysTick_Configuration();
	Gpio_configuration();
	key_Configuration();
	while(1)
	{
		if(1 == key())
	//	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)	
			LED_OpenOrClose(GPIOA , GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4);
	}



}


