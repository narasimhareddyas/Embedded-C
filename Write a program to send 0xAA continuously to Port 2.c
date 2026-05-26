//Write a program to send 0xAA continuously to Port 2.

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
P2=0xAA;
delay();
P2=0x00;
delay();
}
}