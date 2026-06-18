//Write a program to turn ON an LED when an external interrupt occurs.

#include<reg51.h>
sbit led= P2^0;

void ext0_ISR(void) interrupt 0
{
    led = 0;       
}

void main()
{
    led = 1;       
    IT0 = 1;      

    EX0 = 1;       

    EA = 1;        

    while(1)
    {
        
    }
}