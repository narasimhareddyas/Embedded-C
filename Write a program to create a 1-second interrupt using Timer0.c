//Write a program to create a 1-second interrupt using Timer0.

#include <reg51.h>

sbit led = P2^0;         

unsigned int count = 0;   

void timer0_ISR(void) interrupt 1
{
    TH0 = 0x4C;           
    TL0 = 0x00;

    count++;

    if(count >= 20)      
    {
        led = !led;       
        count = 0;
    }
}

void main()
{
    TMOD = 0x01;          

    TH0 = 0x4C;          
    TL0 = 0x00;

    IE = 0x82;            

    TR0 = 1;             

    while(1)
    {
        
    }
}