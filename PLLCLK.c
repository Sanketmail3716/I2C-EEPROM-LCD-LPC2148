#include"PLLCLK.h"

void PLLCLK()
{
PLL0CON = 0X01; //PLL Enable
PLL0CFG = 0X24; //M=5,P=2
PLL0FEED = 0XAA;
PLL0FEED = 0X55;

while(!(PLL0STAT &(1<<10))); // Wait to PLL lock to desired freqency

PLL0CON = 0X03; //PLL Enable and connect
PLL0FEED = 0XAA;
PLL0FEED = 0X55;

VPBDIV = 0X02; // PCLK == 1/2CCLK
//APBDIV = 0X01; //PCLK == CCLK

}
