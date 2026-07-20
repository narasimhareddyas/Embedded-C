// Write a program to control motor direction using two switches

#include <reg51.h>

sbit IN1 = P2^0;
sbit IN2 = P2^1;
sbit EN  = P2^2;

sbit SW1 = P1^0;
sbit SW2 = P1^1;

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
        if(SW1 == 0)    
        {
            IN1 = 1;
            IN2 = 0;
        }
        else if(SW2 == 0) 
        {
            IN1 = 0;
            IN2 = 1;
        }
        else
        {
            IN1 = 0;
            IN2 = 0;
        }

        delay();
    }
}