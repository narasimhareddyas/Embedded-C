// Write a program to blink LED with 500 ms delay

#include <reg51.h>

// Define LED
sbit led = P2^0;

// Delay function
void delay()
{
    int i, j;

    // Nested loops for approximate 500 ms delay
    for(i = 0; i < 250; i++)
    {
        for(j = 0; j < 200; j++);
    }
}

void main()
{
    while(1)
    {
        led = 0;   // LED ON
        delay();

        led = 1;   // LED OFF
        delay();
    }
}