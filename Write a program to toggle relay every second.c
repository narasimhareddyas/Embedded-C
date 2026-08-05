//Write a program to toggle relay every second.

#include<reg51.h>
sbit relay= P2^0;
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
	relay= 0;
		led= 0;
	delay();
	relay= 1;
		led= 1;
	delay();
}
}