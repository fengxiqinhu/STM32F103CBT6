#include "main.h"
int t0 = 32;
int t1 = 22;
extern int Temp;
int main(void)
{
	init();

//	OLED_ShowChar(0,6,'f');
	//设置温度
	OLED_ShowCHinese(0,0,7);
	OLED_ShowCHinese(16,0,8);
	OLED_ShowCHinese(32,0,9);
	OLED_ShowCHinese(48,0,10);
	OLED_ShowChar(64,0,':');
	OLED_ShowNum(80,0,t0,2,16);
	OLED_ShowCHinese(100,0,17);
	//当前温度
	OLED_ShowCHinese(0,3,12);
	OLED_ShowCHinese(16,3,13);
	OLED_ShowCHinese(32,3,9);
	OLED_ShowCHinese(48,3,10);
	OLED_ShowChar(64,3,':');
	OLED_ShowNum(80,3,Temp,2,16);
	OLED_ShowCHinese(100,3,17);
	//保温设置中/保温中
	OLED_ShowChar(0,6,'>');
	OLED_ShowChar(8,6,'>');
	OLED_ShowCHinese(16,6,16);
	OLED_ShowCHinese(32,6,9);
	OLED_ShowCHinese(48,6,7);
	OLED_ShowCHinese(64,6,8);
	OLED_ShowCHinese(80,6,18);
	OLED_ShowChar(96,6,'<');
	OLED_ShowChar(102,6,'<');
	//Interrupt_demo1_Configuration();
	while(1)
	{
		OLED_ShowNum(80,3,Temp,2,16);
		delay_us(900000);
	}
//	OLED_ShowNum(30,4,i,5,16);
//	OLED_ShowChar(37,4,'.');
}








