// Write a program to rotate stepper motor by 90 degrees

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
    unsigned char i;

    for(i = 0; i < 50; i++)
    {
        P2 = 0x09;
        delay();

        P2 = 0x0C;
        delay();

        P2 = 0x06;
        delay();

        P2 = 0x03;
        delay();
    }

    P2 = 0x00;

    while(1);
}