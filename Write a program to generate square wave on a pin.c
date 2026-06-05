//Write a program to generate square wave on a pin.

#include<reg51.h>
sbit osc= P1^0;
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
osc=0;
delay();
osc=1;
delay();
}
}