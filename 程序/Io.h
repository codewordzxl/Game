#ifndef __IO_H__
#define __IO_H__

#include "stc12c5a60s2.h"


typedef unsigned char uchar;
typedef unsigned int uint;


//·äÃùÆ÷
sbit FM=P4^0;

//°´¼ü
sbit Player1_U=P2^0;
sbit Player1_L=P2^1;
sbit Player1_D=P2^2;
sbit Player1_R=P2^3;

sbit Player2_U=P2^4;
sbit Player2_L=P2^5;
sbit Player2_D=P2^6;
sbit Player2_R=P2^7;

//LED
sbit Led1=P4^3;
sbit Led2=P4^2;

#endif