// Write a program to control LED brightness based on ADC value

#include <reg51.h>

sbit ADC_WR   = P3^6;
sbit ADC_RD   = P3^7;
sbit ADC_INTR = P3^2;

sbit LED = P2^0;

void delay(unsigned int d)
{
    unsigned int i, j;

    for(i = 0; i < d; i++)
        for(j = 0; j < 50; j++);
}

void main(void)
{
    unsigned char adc_value;

    ADC_WR = 1;
    ADC_RD = 1;

    while(1)
    {
        ADC_WR = 0;
        delay(1);
        ADC_WR = 1;

        while(ADC_INTR == 1);

        ADC_RD = 0;
        adc_value = P1;
        ADC_RD = 1;

        LED = 0;                
        delay(adc_value);

        LED = 1;                
        delay(255 - adc_value);
    }
}