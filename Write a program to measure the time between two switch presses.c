//Write a program to measure the time between two switch presses.

#include <reg51.h>

sbit SW1 = P3^2;    
sbit SW2 = P3^3;   

unsigned int time;

void main()
{
    TMOD = 0x01;    

    while(1)
    {
        while(SW1 == 1);  

        TH0 = 0x00;        
        TL0 = 0x00;

        TR0 = 1;       

        while(SW2 == 1);   

        TR0 = 0;           

        time = (TH0 << 8) | TL0;   

        P1 = TH0;        
        P2 = TL0;          

        while(1);        
    }
}