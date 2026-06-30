// Write a program to display a counter on LCD

#include <reg51.h>

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void delay(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char ch);
void lcd_init(void);

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 300; j++);
    }
}

void lcd_cmd(unsigned char cmd)
{
    P1 = cmd;

    RS = 0;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
    delay();
}

void lcd_data(unsigned char ch)
{
    P1 = ch;

    RS = 1;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
    delay();
}

void lcd_init(void)
{
    lcd_cmd(0x38);  
    lcd_cmd(0x0C);   
    lcd_cmd(0x06);   
    lcd_cmd(0x01);   
    delay();
}

void main(void)
{
    unsigned char count;

    lcd_init();

    while(1)
    {
        for(count = 0; count <= 9; count++)
        {
            lcd_cmd(0x80);           

            lcd_data(count + '0');  

            delay();
        }
    }
}