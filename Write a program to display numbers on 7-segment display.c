//Write a program to display numbers on 7-segment display.

#include<reg51.h>

sbit dp= P2^0;
void delay()
{
int i,j;
for(i=0;i<500;i++)
{
for(j=0;j<500;j++);
}
}

void main()
{
while(1)
{
	dp=1;
P1=0x40;
delay();
	P1=0x79;
delay();
	P1=0x24;
delay();
	P1=0x30;
delay();
	P1=0x19;
delay();
	P1=0x12;
delay();
	P1=0x2;
delay();
	P1=0x78;
delay();
	P1=0x0;
delay();
	P1=0x10;
delay();

}
}