// Write a program to vary analog voltage using switches

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
    unsigned char sw_value;

    while(1)
    {
        sw_value = P0;

        P1 = sw_value;

        delay();
    }
}