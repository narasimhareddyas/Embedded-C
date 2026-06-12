// Write a program to generate a 1 kHz square wave using Timer0

#include <reg51.h>

sbit wave = P1^0;

void timer0_delay()
{
    TMOD = 0x01;    

    TH0 = 0xFE;    
    TL0 = 0x33;     

    TR0 = 1;

    while(TF0 == 0); 

    TR0 = 0;        
    TF0 = 0;        
}

void main()
{
    while(1)
    {
        wave = 0;       
        timer0_delay(); 

        wave = 1;       
        timer0_delay(); 
    }
}