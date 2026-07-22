// Write a program to rotate stepper motor anticlockwise

#include <reg51.h>

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 200; i++)
    {
        for(j = 0; j < 300; j++);
    }
}

void main(void)
{
    while(1)
    {
        P2 = 0x03;     
        delay();

        P2 = 0x06;     
        delay();

        P2 = 0x0C;
        delay();

        P2 = 0x09;    
        delay();
    }
}