// Write a program to read data from EEPROM (24C02 I2C)

#include <reg51.h>

sbit SDA = P2^0;
sbit SCL = P2^1;

void delay(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(unsigned char ch);
unsigned char i2c_read(void);
unsigned char eeprom_read(unsigned char addr);

void delay(void)
{
    unsigned int i;

    for(i = 0; i < 100; i++);
}

void i2c_start(void)
{
    SDA = 1;
    SCL = 1;
    delay();

    SDA = 0;
    delay();

    SCL = 0;
}

void i2c_stop(void)
{
    SDA = 0;
    SCL = 1;
    delay();

    SDA = 1;
    delay();
}

void i2c_write(unsigned char ch)
{
    unsigned char i;

    for(i = 0; i < 8; i++)
    {
        if(ch & 0x80)
            SDA = 1;
        else
            SDA = 0;

        SCL = 1;
        delay();
        SCL = 0;
        delay();

        ch <<= 1;
    }

    SDA = 1;
    SCL = 1;
    delay();
    SCL = 0;
}

unsigned char i2c_read(void)
{
    unsigned char i;
    unsigned char value = 0;

    SDA = 1;  

    for(i = 0; i < 8; i++)
    {
        value <<= 1;

        SCL = 1;
        delay();

        if(SDA)
            value |= 0x01;

        SCL = 0;
        delay();
    }

    SDA = 1;
    SCL = 1;
    delay();
    SCL = 0;

    return value;
}

unsigned char eeprom_read(unsigned char addr)
{
    unsigned char value;

    i2c_start();

    i2c_write(0xA0);      

    i2c_write(addr);     

    i2c_start();          

    i2c_write(0xA1);     

    value = i2c_read(); 

    i2c_stop();

    return value;
}

void main(void)
{
    unsigned char value;

    while(1)
    {
        value = eeprom_read(0x00); 

        P1 = value;                  

        delay();
    }
}