// Write a program to display ADC value on LCD

#include <reg51.h>

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

sbit ADC_WR   = P3^6;
sbit ADC_RD   = P3^7;
sbit ADC_INTR = P3^2;

void delay(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char ch);
void lcd_init(void);
void lcd_string(char *str);
void lcd_number(unsigned char num);

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
        for(j = 0; j < 300; j++);
}

void lcd_cmd(unsigned char cmd)
{
    P0 = cmd;

    RS = 0;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
}

void lcd_data(unsigned char ch)
{
    P0 = ch;

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
    while(*str)
    {
        lcd_data(*str++);
    }
}

void lcd_number(unsigned char num)
{
    lcd_data((num/100) + '0');
    lcd_data(((num%100)/10) + '0');
    lcd_data((num%10) + '0');
}

void main(void)
{
    unsigned char adc_value;

    lcd_init();

    ADC_WR = 1;
    ADC_RD = 1;

    while(1)
    {
        ADC_WR = 0;
        delay();
        ADC_WR = 1;

        while(ADC_INTR == 1);

        ADC_RD = 0;
        adc_value = P1;
        ADC_RD = 1;

        lcd_cmd(0x01);      
        lcd_cmd(0x80);      

        lcd_string("ADC Value:");

        lcd_cmd(0xC0);

        lcd_number(adc_value);

        delay();
    }
}