// Write a program to control relay using a switch

#include <reg51.h>

// Switch and Relay
sbit SW    = P1^0;
sbit RELAY = P2^0;

// Delay Function
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
        if(SW == 0)      
        {
            RELAY = 1;   
        }
        else             
        {
            RELAY = 0;
        }

        delay();
    }
}