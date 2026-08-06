//Write a program to generate buzzer sound.

#include<reg51.h>
sbit buzzer= P2^0;
sbit led= P1^0;
void delay()
{
	int i,j;
	for(i=0;i<500;i++)
	{
		for(j=0;j<500;j++);
	}
}
void main(void)
{
	while(1)
	{
		buzzer=0;
			led= 0;
		delay();
		buzzer=1;
		led= 1;
		delay();
	}
}
	