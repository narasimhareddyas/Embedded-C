//Write a program to turn ON LED if sensor value exceeds threshold.

#include<reg51.h>

sbit led= P2^0;

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
	unsigned char threshold=5;
unsigned char sensor;
while(1)
{
sensor= P1;
if(sensor>=threshold)
{
led=0;
delay();
}
else
{
	led=1;
	delay();
}
}
}
