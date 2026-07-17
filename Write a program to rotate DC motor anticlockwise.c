// Write a program to rotate DC motor anticlockwise

#include <reg51.h>

sbit IN1 = P2^0;
sbit IN2 = P2^1;
sbit EN  = P2^2;

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
    EN = 1;         

    while(1)
    {
        IN1 = 0;    
        IN2 = 1;

        delay();
    }
}