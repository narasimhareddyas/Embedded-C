//Write a program to count external pulses using Timer1 in counter mode.

#include <reg51.h>

void main()
{
    TMOD = 0x50;   
    
    TH1 = 0x00;    
    TL1 = 0x00;    

    TR1 = 1;       

    while(1)
    {
        if(TF1)
        {
            TF1 = 0;   
            TR1 = 0;
            
            P1 = TL1;  
            
            TR1 = 1;   
        }
    }
}