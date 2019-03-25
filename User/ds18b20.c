#include "ds18b20.h"
#include "bsp_SysTick.h"

u8 ID[4];

int Temp = 0;//当前温度





//------------------GPIO配置----------------------------
void DS18_GPIO_Configuration(GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能B端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	 
 	GPIO_InitStructure.GPIO_Mode = mode; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //初始化PB0,PB1	
 	GPIO_SetBits(GPIOA,GPIO_Pin_12);	
}

void DS18_Reset(void)
{
	DQ_TX;
	DQ_L;//主机发送复位脉冲
	delay_us(960);
	DQ_H;
}





//----------------复位脉冲，初始化-----------------------
int DS18_Init(void)
{
	DS18_Reset();
	DQ_RX;//接收响应脉冲
	delay_us(70);
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0)
	{
		delay_us(420);//等待480us，判断脉冲
		return 1;
	}
	return 0;
	

}
//read rom




//------------------------写 1-------------------
void write_1(void)
{
	delay_us(2);
	DQ_L;
	delay_us(13);
	DQ_H;
	delay_us(60);
}
//--------------------------写 0-------------------------
void write_0(void)
{
	delay_us(2);
	DQ_L;
	delay_us(60);
	DQ_H;
}
//----------------------写一个字节----------------------
void write_byte(u8 word)
{
	int i = 0;
	DQ_TX;
	DQ_H;
	for(i = 0 ; i < 8 ; i++)
	{
		if((word & 0x01) == 1)
			write_1();
		else
			write_0();
		word >>= 1;
	}
}


//-----------------------读一个位--------------------------
int read_bit(void)
{
	
	DQ_TX;
	DQ_H;
	DQ_L;
	delay_us(2);
	DQ_RX;
	delay_us(10);
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0)
	{
		delay_us(50);
		return 0;
	}
	else
	{
		delay_us(50);
		return 1;
	}

}
//-------------------------读一个字节-----------------------
u8 read_byte(void)
{
	u8 word = 0;
	int i = 0;
	for(i = 0 ; i < 8 ; i++)
	{
		word = (read_bit() << 7) | (word >> 1);
	}
	return word;
}

//----------------读取单节点设备id---------------
void read_rom(void)
{
	int i;
	DS18_Init();
	write_byte(0xbe);
	for(i = 0 ; i < 4 ; i++)
	{
		ID[i] = read_byte();
	}
}
//---------------------1~n设备匹配----------------------
void match_rom(void)
{
	int i;
	DS18_Init();
	for(i = 0 ; i < 4 ; i ++)
	{
		write_byte(ID[i]);
	}
	//返回是否匹配成功
}

//----------------------获取温度-------------------------
void Get_T(void)
{
	u8 LSB , MSB;
//T_NOW[0]：正负
//T_NOW[1]：整数部分
//T_NOW[2]：小数部分
	u8 T_NOW[3] = {0};
	DS18_Init();
	Skip_ROM;
	CONVERT_T;
	while(!read_bit());		//等待温度转换完成
	READ_SCRATCHPAD;
	LSB = read_byte();
	MSB = read_byte();
	//判断正负
	if((( MSB >> 3 ) & 0x01 ) == 1 )
		T_NOW[0] = 0;
	else
		T_NOW[0] = 2;
	//整数部分
	T_NOW[1] = (((MSB << 5) >> 1 ) | (LSB >> 4));
	//小数部分
	T_NOW[2] = ((LSB << 4) >> 4 ) * T_ERR;
	//温度
	Temp = (T_NOW[0] - 1) * ( T_NOW[1] + T_NOW[2] );
}

////rom指令
//SEARCH ROM[F0h];//扫描ROM编码
//Read ROM[33h];//读取4位ROM编码
//Match ROM[55h];

////功能指令
//Write Scratchpad

















