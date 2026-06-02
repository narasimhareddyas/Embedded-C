//Write a program to display binary count on LEDs.

#include<reg51.h>

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
	unsigned char count;
while(1)
{
	for(count=0;count<255;count++)
	{
P1=count;
delay();
	}

}
}