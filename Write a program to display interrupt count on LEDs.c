//Write a program to display interrupt count on LEDs.

#include<reg51.h>
sbit inter= P2^0;
unsigned char count;

void ext0_ISR(void) interrupt 0
{
    count++;        

    P1 = count;     
}

void main()
{
    P1 = 0x00;      

    IT0 = 1;        

    EX0 = 1;       

    EA = 1;       

    while(1)
    {
        
    }
}