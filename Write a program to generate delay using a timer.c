// Write a program to generate delay using Timer0

#include <reg51.h>

// Define LED
sbit led = P2^0;

// Timer delay function
void timer()
{
    TMOD = 0x01;   // Timer0 mode1 (16-bit timer)

    TH0 = 0xFF;    // Load higher byte
    TL0 = 0x66;    // Load lower byte

    TR0 = 1;       // Start Timer0

    while(TF0 == 0); // Wait until timer overflow

    TR0 = 0;       // Stop timer
    TF0 = 0;       // Clear overflow flag
}

void main()
{
    while(1)
    {
        led = 0;   // LED ON
        timer();

        led = 1;   // LED OFF
        timer();
    }
}