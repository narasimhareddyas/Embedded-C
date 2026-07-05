// Write a program to store a counter value in EEPROM (24C02 I2C)

#include <reg51.h>

sbit SDA = P2^0;
sbit SCL = P2^1;

void delay(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(unsigned char ch);
void eeprom_write(unsigned char addr, unsigned char value);

void delay(void)
{
    unsigned int i;

    for(i = 0; i < 500; i++);
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

void eeprom_write(unsigned char addr, unsigned char value)
{
    i2c_start();

    i2c_write(0xA0);  

    i2c_write(addr);      

    i2c_write(value);     

    i2c_stop();

    delay();             
}

void main(void)
{
    unsigned char count;

    while(1)
    {
        for(count = 0; count <= 255; count++)
        {
            eeprom_write(0x00, count);  

            P1 = count;                

            delay();
        }
    }
}