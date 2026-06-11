// Write a program to receive data through UART and display on Port1

#include <reg51.h>

void uart_init()
{
    TMOD = 0x20;     

    TH1 = 0xFD;      

    SCON = 0x50;     

    TR1 = 1;         
}

void main()
{
    unsigned char rx_data;

    uart_init();

    while(1)
    {
        while(RI == 0); 

        rx_data = SBUF;   

        RI = 0;           

        P1 = rx_data;    
    }
}