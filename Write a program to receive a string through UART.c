//Write a program to receive a string through UART.

#include<reg51.h>
void uart_init()
{
TMOD=0x20;
TH1=0xFD;
SCON=0x50;
TR1=1;
}

unsigned char uart_rx()
{
while(RI==0);
RI=0;
return SBUF;
}

void main()
{
unsigned char str[20];
unsigned char i=0;
uart_init();
while(1)
{
i=0;
do
{
str[i]=uart_rx();
i++;
}
while(str[i-1]!='\r');
str[i]='\0';
P1=i;
}
}
