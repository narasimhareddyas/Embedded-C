// Write a program to blink two LEDs alternately

#include <reg51.h>

// Define LEDs
sbit led1 = P2^0;
sbit led2 = P2^1;

// Delay function
void delay()
{
    int i, j;

    for(i = 0; i < 500; i++)
    {
        for(j = 0; j < 500; j++);
    }
}

// Main function
void main()
{
    while(1)
    {
        led1 = 0;   // LED1 ON
        led2 = 1;   // LED2 OFF
        delay();

        led1 = 1;   // LED1 OFF
        led2 = 0;   // LED2 ON
        delay();
    }
}