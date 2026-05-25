//Write a program to send 0x55 continuously to Port 1.

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
P1=0x55;
delay();
P1=0x00;
delay();
}
}