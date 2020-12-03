#include "stc12c5a60s2.h"
#include "oled.h"
#include "Io.h"
#include "Delay.h"
#include "Game.h"

uchar Pate_flag=0;

uint flag=0;

uchar Count_Down=0;
extern Time_Down;

extern x1;
extern y1;
extern x2;
extern y2;

uchar DisSnake_flag=1;

uchar Rev_flag=0;
void System_Init()
{
   	FM=0;

   	Led1=0;
   	Led2=0;

 	OLED_Init();
	OLED_CLS();

	IT1=1;//设置外部中断为下降沿触发
	PX1=1;//设置外部中断1为高优先级
	EX1=1;//开启外部中断1
	EA=1; //开启总中断

}


void main()
{
	System_Init();
	Pate1();
	while(1)
	{

		if(Player1_U==0||Player2_U==0)
		{
		  	Delay1ms(100);
			if(Player1_U==0||Player2_U==0)
			{
				if(Pate_flag==2)
				{
				  	Pate_flag=1;
					Pate2();
				}

				else if(Pate_flag==1)
				{
				  	Pate_flag=0;
					Pate1();
				}
				
			}
			while(Player1_U==0||Player2_U==0);
		}

		if(Player1_D==0||Player2_D==0)
		{
		  	Delay1ms(100);
			if(Player1_D==0||Player2_D==0)
			{
				if(Pate_flag==0)
				{
				  	Pate_flag=1;
					Pate2();
				}

				else if(Pate_flag==1)
				{
				  	Pate_flag=2;
					Pate3();
				}
			}
			while(Player1_D==0||Player2_D==0);
		}

		if(flag)
		{
		  	switch(Pate_flag)
			{
				case 0:
					Game1();
					OLED_CLS();
					Pate1();
					flag=0;
					break;
				case 1:
					Game2();
					OLED_CLS();
					Pate2();
					flag=0;
					break;
				case 2:
					Game3();
					OLED_CLS();
					Pate3();
					flag=0;
					break;
				default:break;
			}
		}

	}
}

void Timer0Interrupt(void) interrupt 1
{
    TH0 = 0x0D8;
    TL0 = 0x0F0;//10ms

	if(Pate_flag==1)
	{
		Count_Down++;
		if(Count_Down>=100)
		{
			Count_Down=0;
			Time_Down--;	
		}
	
		Rev_flag++;
		if(Rev_flag>10)
		{
			Snake_Move();
			Rev_flag=0;
		}
	}

	if(Pate_flag==2)
	{
		Rev_flag++;
		if(Rev_flag>10)
		{
		 	B_Move();
		}
	}
	

}

void  confiem() interrupt 2
{
	flag=~flag;
}