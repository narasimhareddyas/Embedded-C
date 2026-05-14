// Write a program to turn ON an LED for 5 seconds and then OFF

#include <reg51.h>

// Define LED connected to Port 2 Pin 0
sbit led = P2^0;

// Delay function
void delay()
{
    int i, j;

    for(i = 0; i < 1000; i++)
    {
        for(j = 0; j < 1000; j++);
    }
}

void main()
{
    int k;

    led = 1;   // LED ON

    // Approximate 5-second delay
    for(k = 0; k < 5; k++)
    {
        delay();
    }

    led = 0;   // LED OFF

    while(1);  // Stop execution
}