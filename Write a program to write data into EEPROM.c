// Write a program to write data into EEPROM (24C02 I2C)

#include <reg51.h>

sbit SDA = P2^0;
sbit SCL = P2^1;

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

void i2c_write(unsigned char dat)
{
    unsigned char i;

    for(i = 0; i < 8; i++)
    {
        SDA = (dat & 0x80) ? 1 : 0;

        SCL = 1;
        delay();
        SCL = 0;

        dat <<= 1;
    }

    // ACK Bit
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
    while(1)
    {
        eeprom_write(0x00, 0x55);   

        while(1);                   
    }
}