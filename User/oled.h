//////////////////////////////////////////////////////////////////////////////////	 
//  文 件 名   : oled.h
//  作    者   : 邴哲松
//  生成日期   : 2017.5.9
//  功能描述   : STM32 OLED 4接口SPI演示例程
//  接线说明:   ----------------------------------------------------------------
//              GND  电源地
//              VCC  3.3v电源
//              D0   接PB5（SCLK）
//              D1   接PB6（SDIN）
//              RES  接PB7 (RST)
//              DC   接PB8 (命令/数据标志位)
//              CS   接PB9 (OLED 片选信号)              
//              ----------------------------------------------------------------
//******************************************************************************/
#ifndef __OLED_H
#define __OLED_H			  	 
#include "stdlib.h"	    	

#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    

//-----------------OLED端口定义----------------  					   
#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_5)//CLK(D0)
#define OLED_SCLK_Set() GPIO_SetBits(GPIOB,GPIO_Pin_5)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_6)//DIN(D1)
#define OLED_SDIN_Set() GPIO_SetBits(GPIOB,GPIO_Pin_6)

#define OLED_RST_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_7)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOB,GPIO_Pin_7)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_8)//DC
#define OLED_DC_Set() GPIO_SetBits(GPIOB,GPIO_Pin_8)
 		     
#define OLED_CS_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_9)//CS
#define OLED_CS_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_9)



#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED控制用函数
void OLED_WR_Byte(unsigned int dat,unsigned int cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(unsigned int x,unsigned int y,unsigned int t);
void OLED_Fill(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int dot);
void OLED_ShowChar(unsigned int x,unsigned int y,unsigned int chr);
void OLED_ShowNum(unsigned int x,unsigned int y,unsigned int num,unsigned int len,unsigned int size);
void OLED_ShowString(unsigned int x,unsigned int y, unsigned char *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(unsigned int x,unsigned int y,unsigned int no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);


#endif  
	 



