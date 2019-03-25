#include "ds18b20.h"
#include "bsp_SysTick.h"

u8 ID[4];

int Temp = 0;//��ǰ�¶�





//------------------GPIO����----------------------------
void DS18_GPIO_Configuration(GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��B�˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	 
 	GPIO_InitStructure.GPIO_Mode = mode; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //��ʼ��PB0,PB1	
 	GPIO_SetBits(GPIOA,GPIO_Pin_12);	
}

void DS18_Reset(void)
{
	DQ_TX;
	DQ_L;//�������͸�λ����
	delay_us(960);
	DQ_H;
}





//----------------��λ���壬��ʼ��-----------------------
int DS18_Init(void)
{
	DS18_Reset();
	DQ_RX;//������Ӧ����
	delay_us(70);
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0)
	{
		delay_us(420);//�ȴ�480us���ж�����
		return 1;
	}
	return 0;
	

}
//read rom




//------------------------д 1-------------------
void write_1(void)
{
	delay_us(2);
	DQ_L;
	delay_us(13);
	DQ_H;
	delay_us(60);
}
//--------------------------д 0-------------------------
void write_0(void)
{
	delay_us(2);
	DQ_L;
	delay_us(60);
	DQ_H;
}
//----------------------дһ���ֽ�----------------------
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


//-----------------------��һ��λ--------------------------
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
//-------------------------��һ���ֽ�-----------------------
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

//----------------��ȡ���ڵ��豸id---------------
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
//---------------------1~n�豸ƥ��----------------------
void match_rom(void)
{
	int i;
	DS18_Init();
	for(i = 0 ; i < 4 ; i ++)
	{
		write_byte(ID[i]);
	}
	//�����Ƿ�ƥ��ɹ�
}

//----------------------��ȡ�¶�-------------------------
void Get_T(void)
{
	u8 LSB , MSB;
//T_NOW[0]������
//T_NOW[1]����������
//T_NOW[2]��С������
	u8 T_NOW[3] = {0};
	DS18_Init();
	Skip_ROM;
	CONVERT_T;
	while(!read_bit());		//�ȴ��¶�ת�����
	READ_SCRATCHPAD;
	LSB = read_byte();
	MSB = read_byte();
	//�ж�����
	if((( MSB >> 3 ) & 0x01 ) == 1 )
		T_NOW[0] = 0;
	else
		T_NOW[0] = 2;
	//��������
	T_NOW[1] = (((MSB << 5) >> 1 ) | (LSB >> 4));
	//С������
	T_NOW[2] = ((LSB << 4) >> 4 ) * T_ERR;
	//�¶�
	Temp = (T_NOW[0] - 1) * ( T_NOW[1] + T_NOW[2] );
}

////romָ��
//SEARCH ROM[F0h];//ɨ��ROM����
//Read ROM[33h];//��ȡ4λROM����
//Match ROM[55h];

////����ָ��
//Write Scratchpad

















