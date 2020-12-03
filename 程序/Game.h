#ifndef __GAME_H__
#define __GAME_H__

#include "stc12c5a60s2.h"
#include "oled.h"
#include "Io.h"
#include "Delay.h"


void Game1();
void Key();
void Result();
void Display();
void Mark();

void Game2();
void OLED_Refresh_Gram(void);
void OLED_DrawPoint(uchar x,uchar y,uchar t);
void OLED_DrawLine(uchar x1,uchar y1,uchar x2,uchar y2);
void Farme();//�߿�
void Time();//����ʱ
void Make_Food();//ʳ��
void Snake_Init();//��ʼ����
void Snake_Move();
void Display_Snake();//��ʾ��
void Key_Direct();
void Die();
void Clear();

void Game3();
void Board_Init();
void Display_Board();
void Key_Board();
void B_Move();

#endif