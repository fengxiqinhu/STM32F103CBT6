#include "bsp_led.h"




//����PA1 - PA4
//����������ʱ��APB2
//����PA1 - PA4���������Ƶ��50MHz
void Gpio_configuration(void)
{
	RCC_GPIOAClock_ENABLE;
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}

//�ı�LED�Ƶ�״̬���ı�GPIO�ڵĵ�ƽ״̬��
//������GPIO���裻GPIO�˿�
void LED_OpenOrClose(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin) == 0)
		GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_SET);
	else
		GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_RESET);


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
	SysTick_Configuration();
	while(1)
	{	
		GPIO_WriteBit(GPIOA , GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 , Bit_RESET);
		delay_us(500000);
		GPIO_WriteBit(GPIOA , GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 , Bit_SET);	
		delay_us(500000);
	}


}

//ʾ��3��
//led���500ms����
//����ʵ��
void led_demo3(void)
{
	Gpio_configuration();
	SysTick_Configuration();
	while(1)
	{	
		LED_OpenOrClose(GPIOA,  GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 );
		delay_us(500000);
		
	}


}



