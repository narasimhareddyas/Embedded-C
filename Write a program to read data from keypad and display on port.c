// Write a program to read data from keypad and display on Port2

#include <reg51.h>

void main()
{
    while(1)
    {
        P1 = 0xF0;          

        if(P1 != 0xF0)      
        {
            P2 = P1;        
        }
    }
}