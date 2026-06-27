//Write a program to send "HELLO" continuously through UART.

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

void uart_string(char *str)
{
while(*str)
{
	uart_tx(*str);
	str++;
}
}

void main()
{
uart_init();

while(1)
{
uart_string("HELLO\r\n");
}
}