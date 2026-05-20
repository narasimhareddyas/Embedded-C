// Write a program to control two LEDs using two switches

#include <reg51.h>

// Define LEDs
sbit led1 = P2^0;
sbit led2 = P2^1;

// Define switches
sbit sw1 = P1^0;
sbit sw2 = P1^1;

void main()
{
    while(1)
    {
        // Control LED1 using Switch1
        if(sw1 == 1)
        {
            led1 = 0;   // LED1 ON
        }
        else
        {
            led1 = 1;   // LED1 OFF
        }

        // Control LED2 using Switch2
        if(sw2 == 1)
        {
            led2 = 0;   // LED2 ON
        }
        else
        {
            led2 = 1;   // LED2 OFF
        }
    }
}