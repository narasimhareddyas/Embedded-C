// Write a program to control DC motor speed using PWM

#include <reg51.h>

sbit IN1 = P2^0;
sbit IN2 = P2^1;
sbit EN  = P2^2;

void delay(unsigned int d)
{
    unsigned int i, j;

    for(i = 0; i < d; i++)
    {
        for(j = 0; j < 100; j++);
    }
}

void main(void)
{
    unsigned char duty;

    IN1 = 1;
    IN2 = 0;

    while(1)
    {
        for(duty = 0; duty <= 100; duty += 10)
        {
            EN = 1;                 
            delay(duty);

            EN = 0;                   
            delay(100 - duty);
        }

        for(duty = 100; duty > 0; duty -= 10)
        {
            EN = 1;
            delay(duty);

            EN = 0;
            delay(100 - duty);
        }
    }
}