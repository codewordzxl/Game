#include "Delay.h"


void Delay1ms(unsigned int y)
{
	unsigned char a,b,c;
	for( ; y>0; y--)
	{
		for(c=1;c>0;c--)
        for(b=142;b>0;b--)
        for(a=2;a>0;a--);
	}
}