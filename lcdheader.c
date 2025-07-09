#include<lpc21xx.h>
#include"lcdheader.h"
#include"delay.h"
void lcd_init()
{
	IODIR1=0x00FE0000;
	cmd(0x02);
	cmd(0x28);
	cmd(0x0E);
	cmd(0x06);
	cmd(0x01);
}
void cmd(unsigned char a)
{
	
	IOPIN1=((IOPIN1&0xFF010000)|(a<<16));
	IOCLR1=(1<<rs);//rs=0;
	IOCLR1=(1<<rw);//rw=0;
	IOSET1=(1<<en);//en=1;
	delay(10);
	IOCLR1=(1<<en);//en=0;
	IOPIN1=((IOPIN1&0xFF010000)|(a<<20));
	IOCLR1=(1<<rs);//rs=0;
	IOCLR1=(1<<rw);//rw=0;
	IOSET1=(1<<en);//en=1;
	delay(10);
	IOCLR1=(1<<en);//en=0;
}
void lcddata(unsigned char b)
{
	IOPIN1=((IOPIN1&0xFF010000)|(b<<16));
	IOSET1=(1<<rs);//rs=1;
	IOCLR1=(1<<rw);//rw=0;
	IOSET1=(1<<en);//en=1;
	delay(10);
	IOCLR1=(1<<en);//en=0;
	IOPIN1=((IOPIN1&0xFF010000)|(b<<20));
	IOSET1=(1<<rs);//rs=1;
	IOCLR1=(1<<rw);//rw=0;
	IOSET1=(1<<en);//en=1;
	delay(10);
	IOCLR1=(1<<en);//en=0;
}
void str(char *s)
{
	while(*s)
	{
		lcddata(*s++);
	}
}	
