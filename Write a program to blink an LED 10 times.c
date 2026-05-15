// Write a program to blink an LED 10 times

#include <reg51.h>

// Define LED connected to Port 2 Pin 0
sbit led = P2^0;

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
    int s;

    // Repeat 10 times
    for(s = 0; s < 10; s++)
    {
        led = 1;   // LED ON
        delay();

        led = 0;   // LED OFF
        delay();
    }

    while(1);  // Stop execution
}