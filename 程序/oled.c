#include"oled.h"
#include"oledfont.h"


/*********************OLED驱动程序用的延时程序************************************/
void delay(unsigned int z)
{
	unsigned int x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

/**********************************************
//IIC Start
**********************************************/
void IIC_Start()
{
   SCL = high;		
   SDA = high;
   SDA = low;
   SCL = low;
}

/**********************************************
//IIC Stop
**********************************************/
void IIC_Stop()
{
   SCL = low;
   SDA = low;
   SCL = high;
   SDA = high;
}

/**********************************************
// 通过I2C总线写一个字节
**********************************************/
void Write_IIC_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(IIC_Byte & 0x80)
			SDA=high;
		else
			SDA=low;
		SCL=high;
		SCL=low;
		IIC_Byte<<=1;
	}
	SDA=1;
	SCL=1;
	SCL=0;
}

/*********************OLED写数据************************************/ 
void OLED_WrDat(unsigned char IIC_Data)
{
	IIC_Start();
	Write_IIC_Byte(0x78);
	Write_IIC_Byte(0x40);			//write data
	Write_IIC_Byte(IIC_Data);
	IIC_Stop();
}
/*********************OLED写命令************************************/
void OLED_WrCmd(unsigned char IIC_Command)
{
	IIC_Start();
	Write_IIC_Byte(0x78);            //Slave address,SA0=0
	Write_IIC_Byte(0x00);			//write command
	Write_IIC_Byte(IIC_Command);
	IIC_Stop();
}
/*********************OLED 设置坐标************************************/
void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 
	OLED_WrCmd(0xb0+y);
	OLED_WrCmd(((x&0xf0)>>4)|0x10);
	OLED_WrCmd((x&0x0f)|0x01);
} 

/*********************OLED复位************************************/
void OLED_CLS(void)
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		OLED_WrCmd(0xb0+y);
		//OLED_WrCmd(0x01);
		OLED_WrCmd(0x00);
		OLED_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		OLED_WrDat(0);
	}
}
/*********************OLED初始化************************************/
void OLED_Init(void)
{
	delay(500);
	OLED_WrCmd(0xae);
	OLED_WrCmd(0x00);
	OLED_WrCmd(0x10);
	OLED_WrCmd(0x41);
	OLED_WrCmd(0xb0);
	OLED_WrCmd(0x81);
	OLED_WrCmd(0xff);
	OLED_WrCmd(0xa1);
	OLED_WrCmd(0xa6);

	OLED_WrCmd(0xa8);
	OLED_WrCmd(0x3f);	   
	OLED_WrCmd(0xd3);
	OLED_WrCmd(0x00);
	OLED_WrCmd(0xc8);
	OLED_WrCmd(0xd5);
	OLED_WrCmd(0x80);
	OLED_WrCmd(0xd8);
	OLED_WrCmd(0x05);

	OLED_WrCmd(0xd9);
	OLED_WrCmd(0xf1);
	OLED_WrCmd(0xda);
	OLED_WrCmd(0x12);
	OLED_WrCmd(0xdb);
	OLED_WrCmd(0x30);
	OLED_WrCmd(0x8d);
	OLED_WrCmd(0x14);
	OLED_WrCmd(0xaf);
	OLED_CLS();
} 
void OLED_P8x16_Mie(unsigned char x, y)
{
	unsigned char i=0;
	if(x>120){x=0;y++;}
	OLED_Set_Pos(x,y);
	for(i=0;i<8;i++)
	OLED_WrDat(Mie[i]);
	OLED_Set_Pos(x,y+1);
	for(i=0;i<8;i++)
	OLED_WrDat(Mie[i+8]);
}

/*******************功能描述：显示8*16一组标准ASCII字符串	 显示的坐标（x,y），y为页范围0～7****************/
void OLED_P8x16Str(unsigned char x, y,unsigned char ch[])
{
	unsigned char c=0,i=0,j=0;
	while (ch[j]!='\0')
	{
		c =ch[j]-32;
		if(x>120){x=0;y+=2;}
		OLED_Set_Pos(x,y);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[c*16+i]);
		OLED_Set_Pos(x,y+1);
		for(i=0;i<8;i++)
		OLED_WrDat(F8X16[c*16+i+8]);
		x+=8;
		j++;
	}
}

/*********************OLED全屏************************************/
//void OLED_Fill(unsigned char bmp_dat) 
//{
//	unsigned char y,x;
//	for(y=0;y<8;y++)
//	{
//		OLED_WrCmd(0xb0+y);
//		OLED_WrCmd(0x01);
//		OLED_WrCmd(0x10);
//		for(x=0;x<X_WIDTH;x++)
//		OLED_WrDat(bmp_dat);
//	}
//}


/*****************功能描述：显示16*16点阵  显示的坐标（x,y），y为页范围0～7****************************/
void OLED_P16x16Ch(unsigned char x, y, N)
{
	unsigned char wm=0;
	unsigned int adder=32*N;
	OLED_Set_Pos(x , y);
	for(wm = 0;wm < 16;wm++)
	{
		OLED_WrDat(F16x16[adder]);
		adder += 1;
	}
	OLED_Set_Pos(x,y + 1);
	for(wm = 0;wm < 16;wm++)
	{
		OLED_WrDat(F16x16[adder]);
		adder += 1;
	} 	  	
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               


















 
                                                                                                                                                                                                                                                                                                                                                                                                                       
/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void Draw_BMP(unsigned char x0, y0,x1, y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;

  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {      
	    	OLED_WrDat(BMP[j++]);
	    }
	}
}

void Pate1()
{
	OLED_CLS();
   	OLED_P16x16Ch(0,1,12);
	OLED_P16x16Ch(16,1,13);
	OLED_P16x16Ch(31,1,14);
	OLED_P16x16Ch(47,1,15);
	OLED_P16x16Ch(63,1,16);
	OLED_P16x16Ch(79,1,17);

	OLED_P16x16Ch(16,3,5);
	OLED_P16x16Ch(31,3,6);
	OLED_P16x16Ch(47,3,7);

	OLED_P16x16Ch(16,5,33);
	OLED_P16x16Ch(31,5,34);
	OLED_P16x16Ch(47,5,35);

	
}

void Pate2()
{
	OLED_CLS();

	OLED_P16x16Ch(16,1,0);
	OLED_P16x16Ch(31,1,1);
	OLED_P16x16Ch(47,1,2);
	OLED_P16x16Ch(63,1,3);
	OLED_P16x16Ch(79,1,4);

	OLED_P16x16Ch(0,3,12);
	OLED_P16x16Ch(16,3,18);
	OLED_P16x16Ch(31,3,19);
	OLED_P16x16Ch(47,3,20);

	OLED_P16x16Ch(16,5,33);
	OLED_P16x16Ch(31,5,34);
	OLED_P16x16Ch(47,5,35);
}

void Pate3()
{
	OLED_CLS();

	OLED_P16x16Ch(16,1,0);
	OLED_P16x16Ch(31,1,1);
	OLED_P16x16Ch(47,1,2);
	OLED_P16x16Ch(63,1,3);
	OLED_P16x16Ch(79,1,4);

	OLED_P16x16Ch(16,3,5);
	OLED_P16x16Ch(31,3,6);
	OLED_P16x16Ch(47,3,7);


	OLED_P16x16Ch(0,5,12);
	OLED_P16x16Ch(16,5,36);
	OLED_P16x16Ch(31,5,37);
	OLED_P16x16Ch(47,5,38);
}



