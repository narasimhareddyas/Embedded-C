//Write a program to transmit numbers from 0 to 9 through UART.

#include<reg51.h>
void delay()
{
	int i,j;
	for(i=0;i<500;i++)
	{
		for(j=0;j<500;j++);
	}
}
void uart_init()
{
TMOD= 0x20;
TH1=0xFD;
SCON=0x50;
TR1=1;
}

void uart_tx(unsigned char ch)
{
	SBUF=ch;
	while(TI==0);
		TI=0;
}
void main()
{
unsigned char i;
uart_init();
	
	while(1)
	{
		for(i='0';i<='9';i++)
		{
			uart_tx(i);
			delay();
		}
	}
}