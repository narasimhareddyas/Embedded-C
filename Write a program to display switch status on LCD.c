// Write a program to display switch status on LCD

#include <reg51.h>

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

sbit SW = P3^0;

void delay(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char ch);
void lcd_init(void);
void lcd_string(char *str);

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
}

void lcd_data(unsigned char ch)
{
    P1 = ch;

    RS = 1;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
}

void lcd_init(void)
{
    lcd_cmd(0x38);    
    lcd_cmd(0x0C);    
    lcd_cmd(0x06);   
    lcd_cmd(0x01);    
    delay();
}

void lcd_string(char *str)
{
    while(*str != '\0')
    {
        lcd_data(*str);
        str++;
    }
}

void main(void)
{
    lcd_init();

    while(1)
    {
        lcd_cmd(0x01);   
        lcd_cmd(0x80);      

        if(SW == 0)
        {
            lcd_string("SWITCH ON");
        }
        else
        {
            lcd_string("SWITCH OFF");
        }

        delay();
    }
}