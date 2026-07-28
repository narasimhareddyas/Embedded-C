// Write a program to switch ON a relay

#include <reg51.h>

sbit RELAY = P2^0;

void main(void)
{
    while(1)
    {
        RELAY = 1;     
    }
}