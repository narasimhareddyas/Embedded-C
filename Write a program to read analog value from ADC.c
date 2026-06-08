//Write a program to read analog value from ADC.

#include<reg51.h>

sbit INTR= P3^2;

unsigned char adc_value;

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
	WR=1;
	RD=1;
while(1)
{
  WR=0;
	delay();
	WR=1;
	
	while(INTR==1);
	RD=0;
	adc_value=P1;
	RD=1;
	
	P2=adc_value;
	delay();
}
}
