#include"delay.h"

void delay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<60000;j++);
}
