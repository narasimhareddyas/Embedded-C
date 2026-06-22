//Write a program to transmit a string through UART.

#include<reg51.h>
void uart_init()
{
TMOD= 0x20;
TH1=0xFD;
SCON= 0x50;
TR1= 1;
}

void uart_tx(unsigned char ch)
{
SBUF= ch;
while(TI==0);
TI=0;
}

void uart_string(char *string)
{
while(*string!= '\0')
{
uart_tx(*string);
string++;
}
}

void main()
{
uart_init();
while(1)
{
uart_string("Hello");
uart_tx('\r');
uart_tx('\n');
}
}