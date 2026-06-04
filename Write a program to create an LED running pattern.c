//Write a program to create an LED running pattern.

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
while(1)
{
	unsigned int n;
	for(n=0;n<8;n++)
	{
P1=(1<<n);
delay();
}
}
}