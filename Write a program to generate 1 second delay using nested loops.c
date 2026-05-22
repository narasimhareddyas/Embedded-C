// Write a program to generate 1 second delay using nested loops

#include <reg51.h>

// Define LED connected to Port 2 Pin 0
sbit led = P2^0;

// Delay function
void delay()
{
    int i, j;

    // Nested loops for approximate 1 second delay
    for(i = 0; i < 500; i++)
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