// Write a program to toggle all bits of Port 1

#include <reg51.h>

// Delay function
void delay()
{
    int i, j;

    // Generate delay using nested loops
    for(i = 0; i < 500; i++)
    {
        for(j = 0; j < 500; j++);
    }
}

void main()
{
    while(1)
    {
        P1 = 0xFF;   // Set all bits of Port1 HIGH
                     // All LEDs ON

        delay();     // Wait for some time

        P1 = 0x00;   // Set all bits of Port1 LOW
                     // All LEDs OFF

        delay();     // Wait for some time
    }
}