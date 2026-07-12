// Write a program to generate staircase waveform using DAC0808

#include <reg51.h>

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 300; j++);
    }
}

void main(void)
{
    unsigned char value;

    while(1)
    {
        for(value = 0; value < 255; value++)
        {
            P1 = value;    
            delay();         
        }
    }
}