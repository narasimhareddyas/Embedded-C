// Write a program to read input from Port1 and send to Port2

#include <reg51.h>

void main()
{
    while(1)
    {
        P2 = P1;   // Read data from Port1 and send to Port2
    }
}