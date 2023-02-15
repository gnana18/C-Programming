/*
 * File:   max.c
 * Author: AZETECH
 *
 * Created on 15 February, 2023, 4:03 PM
 */


#include <xc.h>
#define _XTAL_FREQ 16000000
void spi_init();
void spiWrite(unsigned char cmd);
void MAX7219_write(char reg1, char data1);
void Max7219Print(unsigned long Number, unsigned short NumberOfDigits);

void spi_init()
{
        
        SSPCON = 0x20;
        SSPSTAT = 0x00;
}
void spiWrite(unsigned char cmd)
{   
	SSPBUF = cmd;
	while(!SSPIF);	
	SSPIF=0;
	__delay_ms(1000);
	
    
}
void MAX7219_write(char reg1, char data1)
{
 RA5 = 0;

  spiWrite(reg1);
  spiWrite(data1);

   RA5 = 1;
}
void Max7219Print(unsigned long Number, unsigned short NumberOfDigits)
{
  long j;
  for(j=1;Number>0||j-NumberOfDigits<=0;Number/=10,j++)
  {
     RA5=0;
    spiWrite(j);
    spiWrite(Number%10);
     RA5=1;
  }
}

unsigned char i;
void main(void)
{
  spi_init();
  MAX7219_write(0X0C,0X01);
  MAX7219_write(0X0F,0X00);
  MAX7219_write(0X0A,0X0F);
  MAX7219_write(0X09,0XFF);
  MAX7219_write(0X0F,0X01);
  MAX7219_write(0X0F,0X00);
while(1)
  {
    for(i=0;i<99;i++)
    {
       Max7219Print(i,7);
      __delay_ms(100);
    }
  }
}