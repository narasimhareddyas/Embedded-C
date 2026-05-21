// Write a program to detect long press and short press of a switch

#include <reg51.h>

// Define switch and LEDs
sbit btn  = P2^0;
sbit led1 = P2^1;   // Long press indicator
sbit led2 = P2^2;   // Short press indicator

void main()
{
    int count;
    while(1)
    {
        count = 0;

        // Check if button is pressed
        if(btn == 0)
        {
            // Count how long the button is pressed
            while(btn == 0)
            {
                count++;

                // Display count value on Port 1
                P1 = count;
            }
            // Long press condition
            if(count > 5000)
            {
                led1 = 0;   // LED1 ON
                led2 = 1;   // LED2 OFF
            }

            // Short press condition
            else
            {
                led1 = 1;   // LED1 OFF
                led2 = 0;   // LED2 ON
            }
        }
    }
}