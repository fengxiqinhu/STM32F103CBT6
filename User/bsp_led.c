#include "bsp_led.h"




//����PA1 - PA4
//����������ʱ��APB2
//����PA1 - PA4���������Ƶ��50MHz
void Gpio_configuration(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}


//ʾ��1��
//����led
void led_demo1(void)
{
	Gpio_configuration();
	GPIO_WriteBit(GPIOA , GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 , Bit_SET);

}

//ʾ��2��
//led���500ms����
void led_demo2(void)
{
	Gpio_configuration();
	SysTick_Init();
	while(1)
	{	
		GPIO_WriteBit(GPIOA , GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 , Bit_RESET);
		delay_us(500000);
		GPIO_WriteBit(GPIOA , GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 , Bit_SET);	
		delay_us(500000);
	}


}






