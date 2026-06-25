//Write a program to implement UART echo (receive and transmit back).

#include<reg51.h>

void uart_init()
{
TMOD=0x20;
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

unsigned char uart_rx()
{
	while(RI==0);
RI=0;
	return SBUF;
}

void main()
{
unsigned char ch;
	uart_init();
while(1)
{
ch=uart_rx();
	uart_tx(ch);
}
}