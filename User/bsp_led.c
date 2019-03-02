#include "bsp_led.h"




//配置PA1 - PA4
//打开外设总线时钟APB2
//设置PA1 - PA4推挽输出，频率50MHz
void Gpio_configuration(void)
{
	RCC_GPIOAClock_ENABLE;
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}

//改变LED灯的状态（改变GPIO口的电平状态）
//参数：GPIO外设；GPIO端口
void LED_OpenOrClose(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin) == 0)
		GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_SET);
	else
		GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_RESET);


}







//示例1：
//点亮led
void led_demo1(void)
{
	Gpio_configuration();
	GPIO_WriteBit(GPIOA , GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 , Bit_SET);

}

//示例2：
//led间隔500ms亮灭
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

//示例3：
//led间隔500ms亮灭
//函数实现
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



