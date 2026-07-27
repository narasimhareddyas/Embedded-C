// Write a program to control speed of stepper motor

#include <reg51.h>

void delay(unsigned int t)
{
    unsigned int i, j;

    for(i = 0; i < t; i++)
    {
        for(j = 0; j < 300; j++);
    }
}

void main(void)
{
    unsigned int speed = 100;  

    while(1)
    {
        P2 = 0x09;
        delay(speed);

        P2 = 0x0C;
        delay(speed);

        P2 = 0x06;
        delay(speed);

        P2 = 0x03;
        delay(speed);
    }
}