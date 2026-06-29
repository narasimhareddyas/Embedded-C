// Write a program to display your name on LCD

#include <reg51.h>

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

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

    lcd_cmd(0x80);       

    lcd_string("KING");

    while(1);
}