//Write a program to check whether a specific bit is HIGH or LOW.

#include<reg51.h>
sbit input= P1^0;
sbit led1= P2^0;
sbit led2= P2^1;

void main()
{
while(1)
{
	if(input==0)
	{
		led1= 0;
		led2=1;
	}
	else
	{
		led1= 1;
		led2= 0;
	}
}
}