///////////////////////////////////////////////////////////////////////////
//	
//	功能：gpio外设代码示例
//
/***************************************************************************/

#ifndef __DS18B20_H__
#define __DS18B20_H__
#include <stm32f10x.h>
#define IN GPIO_Mode_IPU   //GPIO_Mode_IN_FLOATING 浮空;		GPIO_Mode_IPD  下拉;		GPIO_Mode_IPU 上拉
#define OUT GPIO_Mode_Out_PP //推挽输出

#define DQ_RX DS18_GPIO_Configuration(IN)
#define DQ_TX DS18_GPIO_Configuration(OUT)


#define DQ_L GPIO_ResetBits(GPIOA,GPIO_Pin_12)
#define DQ_H GPIO_SetBits(GPIOA,GPIO_Pin_12)
//-------------------单节点设备匹配----------------
#define Skip_ROM write_byte(0xcc) 
//------------------发动一次温度转换-----------------
#define CONVERT_T write_byte(0x44) 
/*--------------------------------------------
	第一个字节被写入 TH 寄存器(暂存器的字节 2)
	第二个字节被写入 TL 寄存器(暂存器的字节 3)
	第三个字节写入配置寄存器(暂存器的字节 4)
	最后两个字节写入用户字节 3 和 4(暂存器的字节 6 和 7)
*/
#define WRITE_SCRATCHPAD write_byte(0x4e) 
/*---------------------------------------------------
	读取暂存器中的内容
	寄存器0~9 
*/
#define READ_SCRATCHPAD write_byte(0xbe)
/*-----------------------分辨率（精度）-------------------*/
//9:		0.5°C
//10:		0.25°C
//11:		0.125°C
//12:		0.0625°C
#define T_ERR 0.0625

/* --------------------------函数--------------------------- */
void DS18_GPIO_Configuration(GPIOMode_TypeDef mode);
void Get_T(void);
#endif

