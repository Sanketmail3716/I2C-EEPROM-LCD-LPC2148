//datasheet page no. 216

#include<lpc214x.h>
#include"PLLCLK.h"
#include"lcdheader.h"
#include"delay.h"

#define scl 2
#define sda 3

#define sw1 14
#define sw2 15
#define led1 17
#define led2 18

void i2c_init(void);
void i2c_start(void);
void i2c_write(char);
unsigned char i2c_read(void);
void i2c_stop(void);
int main()
{	unsigned char a,b;
	IODIR0&=~((1<<sw1)|(1<<sw2));
	IODIR0|=((1<<led1)|(1<<led2));
	i2c_init();
	PLLCLK();
	lcd_init();
	IOSET0=(1<<led1);
	IOSET0=(1<<led2);
	cmd(0x80);
	lcddata('z');
	while(1)
	{
		if(!(IOPIN0&(1<<sw1)))
		{
			cmd(0x86);
			lcddata('w');
			i2c_start();
			i2c_write(0xA0);
			i2c_write(0x09);
			i2c_write('A');
			i2c_write('4');
			i2c_stop();
		}
		if(!(IOPIN0&(1<<sw2)))
		{
			cmd(0xc6);
			lcddata('r');
			i2c_start();
			i2c_write(0xA0);
			i2c_write(0x09);
			i2c_start();
			i2c_write(0xA1);
			a=i2c_read();
			b=i2c_read();
			i2c_stop();
		}
		if(a=='A')
      { 
				IOCLR0=(1<<led1); 
        delay(20);
        IOSET0=(1<<led2);
				cmd(0xC0);
			  lcddata(a);
        a=0;
				
      }  
       else if(b=='4')
      {
        IOCLR0=(1<<led2); 
        delay(20);
        IOSET0=(1<<led1);
					cmd(0xC8);
			lcddata(b);
        b=0;
      }
	}
}

void i2c_init()
{
	PINSEL0 = PINSEL0 | 0x00000050; /* Configure P0.2 and P0.3 as SCL0 and SDA0 respectively */
	I2C0CONSET = 0x40; /* Enable I2C  */
	I2C0SCLL = 0x32; /* I2C data rate 300Khz and 50% duty cycle */
	I2C0SCLH = 0x32; /* I2C data rate 300Khz and 50% duty cycle */
}
void i2c_start()
{
	I2C0CONSET=0x20;
	while((I2C0CONSET&0x08)==0);
	I2C0CONCLR=0x28;
}
void i2c_write(char data)
{
	I2C0DAT = data; /* Load data to be written into the data register */
	I2C0CONSET = 0x40; /* Enable I2C */
	while( (I2C0CONSET & 0x08) == 0 ); /* Wait till SI = 1 */
	I2C0CONCLR = 0x08;  /* Clear SI bit */

}
unsigned char i2c_read()
{
	I2C0CONSET = 0x44; /* Enable I2C with Acknowledge */
	while( (I2C0CONSET & 0x08) == 0 ); /* Wait till SI = 1 */
	I2C0CONCLR = 0x0C; /* Clear SI and Acknowledge bits */
	return I2C0DAT; /* Return received data */
}
void i2c_stop()
{
	I2C0CONSET = 0x50; /* Set Stop bit for Stop condition */
}
