//Write a program to toggle LED using a switch.

#include<reg51.h>
sbit led = P2^1;
sbit sw = P2^0;
void main()
{
while(1)
{
if(sw==1)
{
led =0;
}
if(sw==0)
{
led =1;
}
}
}
