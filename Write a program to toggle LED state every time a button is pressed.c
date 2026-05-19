// Write a program to toggle LED state every time a button is pressed

#include <reg51.h>

// Define LED and button
sbit led = P2^1;
sbit bt  = P2^0;

// Delay function
void delay()
{
    int i, j;

    for(i = 0; i < 500; i++)
    {
        for(j = 0; j < 500; j++);
    }
}

void main()
{
    led = 1;   // Initially LED OFF

    while(1)
    {
        // Check if button is pressed
        if(bt == 0)
        {
            led = !led;   // Toggle LED

            delay();      // Debounce delay

            // Wait until button released
            while(bt == 0);
        }
    }
}