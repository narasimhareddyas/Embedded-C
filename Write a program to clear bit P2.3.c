//Write a program to clear bit P2.3.

#include<reg51.h>
sbit led = P2^3;

void main()
{
while(1)
{
led = 0;
}
}