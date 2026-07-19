// Write a program to stop motor using a switch

#include <reg51.h>

sbit IN1 = P2^0;
sbit IN2 = P2^1;
sbit EN  = P2^2;

sbit SW = P1^0;

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 500; i++)
    {
        for(j = 0; j < 300; j++);
    }
}

void main(void)
{
    while(1)
    {
        if(SW == 0)     
        {
            EN  = 0;
            IN1 = 0;
            IN2 = 0;
        }
        else            
        {
            EN  = 1;
            IN1 = 1;
            IN2 = 0;
        }

        delay();
    }
}