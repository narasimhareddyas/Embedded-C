// Write a program to switch OFF a relay after 10 seconds

#include <reg51.h>

sbit RELAY = P2^0;

void delay_1s(void)
{
    unsigned int i, j;

    for(i = 0; i < 1000; i++)
    {
        for(j = 0; j < 120; j++);
    }
}

void main(void)
{
    unsigned char count;

    RELAY = 1;

    for(count = 0; count < 10; count++)
    {
        delay_1s();
    }

    RELAY = 0;

    while(1);
}