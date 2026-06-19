//Write a program to count the number of external interrupts.

#include<reg51.h>
unsigned char count= 0;
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