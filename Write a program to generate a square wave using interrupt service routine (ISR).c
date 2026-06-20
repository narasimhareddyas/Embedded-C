//Write a program to generate a square wave using interrupt service routine (ISR).

#include <reg51.h>

sbit wave = P1^0;     


void timer0_ISR(void) interrupt 1
{
    TH0 = 0xFC;        
    TL0 = 0x18;       

    wave = !wave;    
}

void main()
{
    TMOD = 0x01;       

    TH0 = 0xFC;        
    TL0 = 0x18;

    ET0 = 1;         
    EA  = 1;           

    TR0 = 1;          

    while(1)
    {
        
    }
}