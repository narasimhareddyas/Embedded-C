// Write a program to monitor temperature using LM35 and ADC0804

#include <reg51.h>

sbit ADC_WR   = P3^6;
sbit ADC_RD   = P3^7;
sbit ADC_INTR = P3^2;

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
    unsigned char temp_value;

    ADC_WR = 1;
    ADC_RD = 1;

    while(1)
    {
        ADC_WR = 0;
        delay();
        ADC_WR = 1;

        while(ADC_INTR == 1);

        ADC_RD = 0;
        temp_value = P1;
        ADC_RD = 1;

        P2 = temp_value;

        delay();
    }
}