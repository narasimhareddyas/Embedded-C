//Write a program to toggle bit P1.7.

#include<reg51.h>
sbit led=P1^7;
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
led=1;
delay();
led=0;
delay();
}
}