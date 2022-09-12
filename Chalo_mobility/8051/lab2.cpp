#include <reg51.h>

sbit OUT = P1^1;
sbit SW0 = P2^0;
sbit SW1 = P2^1; 
sbit SW2 = P2^2; 
sbit SW3 = P2^3;
void tim_on_delay(int, int);
void tim_off_delay(int, int);

void main()
{
	P2 = 0X00;
	while(1)
		{
		if(SW0 == 1) // generate PWM of 2 kHz with 30% duty
		{
		OUT = 1;
		tim_on_delay(0XFE, 0X33); OUT = 0;
		tim_off_delay(0XFB, 0XCD);
		}
		else if(SW1 == 1) // generate PWM of 1 kHz with 70% duty
		{
		OUT = 1;
		tim_on_delay(0XF7, 0X9A); OUT = 0;
		tim_off_delay(0xFC, 0X66);
		}
		else if(SW2 == 1) // generate PWM of 500 Hz with 30% duty
		{
		OUT = 1;
		tim_on_delay(0XF8, 0XCD); OUT = 0;
		tim_off_delay(0XEF, 0X33);
		}
		else if(SW3 == 1)
		{
		OUT = 1;
		tim_on_delay(0XF5, 0X33); OUT = 0;
		tim_off_delay(0XFE, 0XCD);
		}
	}
}
void tim_on_delay(int th,int tl)
{
TMOD = 0x10; // timer1 in 16-bit mode TH1 = th;
TL1 = tl;
TR1 = 1; // Starting the timer while(TF1 == 0);
While(TF1 ==0);
TF1 =0;
TR1 =0;
}
void tim_off_delay(int th,int tl)
{
TMOD = 0x10; // timer1 in 16-bit mode TH1 = th;
TL1 = tl;
TR1 = 1; // Starting the timer while(TF1 == 0);
while(TF1 ==0);
TF1=0;
TR1=0;
}