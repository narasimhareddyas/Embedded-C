#include <reg51.h>

sbit PWM = P1^0;

void timer_delay()
{
    TMOD = 0x01;     

    TH0 = 0xFC;       
    TL0 = 0x18;       

    TR0 = 1;          

    while(TF0 == 0);  

    TR0 = 0;          
    TF0 = 0;          
}

void main()
{
    while(1)
    {
        PWM = 1;      
        timer_delay();

        PWM = 0;      
        timer_delay();
    }
}