//Write a program to turn ON LED when a switch is pressed.

#include <reg51.h>

// Define LED and switch
sbit led = P2^1;
sbit sw  = P2^0;

void main()
{
    while(1)
    {
        // If switch is pressed
        if(sw == 0)
        {
            led = 0;   // LED ON
        }
        else
        {
            led = 1;   // LED OFF
        }
    }
}