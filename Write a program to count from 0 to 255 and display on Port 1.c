//Write a program to count from 0 to 255 and display on Port 1.

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
	unsigned char num;
	
for(num=0;num<566;num++)
{
P1=num;
delay();
}
}
}
