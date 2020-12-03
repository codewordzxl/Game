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
void Farme();//边框
void Time();//倒计时
void Make_Food();//食物
void Snake_Init();//初始化蛇
void Snake_Move();
void Display_Snake();//显示蛇
void Key_Direct();
void Die();
void Clear();

void Game3();
void Board_Init();
void Display_Board();
void Key_Board();
void B_Move();

#endif