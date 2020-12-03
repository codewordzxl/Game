#ifndef __OLED_H_
#define __OLED_H_

#include"STC12C5A60S2.h"

// ------------------------------------------------------------
// IO��ģ��I2Cͨ��
// SCL��P1^3
// SDA��P1^2
// ------------------------------------------------------------
sbit SCL=P3^7; //����ʱ��
sbit SDA=P1^5; //��������

#define high 1
#define low 0

#define X_WIDTH 	128
#define Y_WIDTH 	64


void delay(unsigned int z);

void IIC_Start();
void IIC_Stop();
void Write_IIC_Byte(unsigned char IIC_Byte);
void OLED_WrDat(unsigned char IIC_Data);
void OLED_WrCmd(unsigned char IIC_Command);
void OLED_Set_Pos(unsigned char x, unsigned char y);

void OLED_Init(void);
void OLED_CLS(void);
void OLED_P8x16_Mie(unsigned char x, y);
void OLED_P8x16Str(unsigned char x, y,unsigned char ch[]);
void OLED_P16x16Ch(unsigned char x, y, N);
//void OLED_Fill(unsigned char bmp_dat);
//void OLED_P6x8Str(unsigned char x, y,unsigned char ch[])

void Draw_BMP(unsigned char x0, y0,x1, y1,unsigned char BMP[]);

void Pate1();//ҳ��1
void Pate2();//ҳ��2
void Pate3();//ҳ��3





#endif