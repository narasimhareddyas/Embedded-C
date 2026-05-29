//Write a program to set bit P1.0.

#include<reg51.h>
sbit led = P1^0;

void main()
{
while(1)
{
led = 1;
}
}