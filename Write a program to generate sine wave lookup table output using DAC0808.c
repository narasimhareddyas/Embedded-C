// Write a program to generate sine wave lookup table output using DAC0808

#include <reg51.h>

unsigned char sine_table[32] =
{
    128,153,177,198,218,234,245,252,
    255,252,245,234,218,198,177,153,
    128,103,79,58,38,22,11,4,
    0,4,11,22,38,58,79,103
};

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 50; i++)
    {
        for(j = 0; j < 100; j++);
    }
}

void main(void)
{
    unsigned char i;

    while(1)
    {
        for(i = 0; i < 32; i++)
        {
            P1 = sine_table[i];  
            delay();              
        }
    }
}