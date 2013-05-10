#include "SPI.h"
#include "Arduino.h"
#include "DACMCP4821.h"

// Shutdown: pin 7
// CS:       pin 2
// LDAC:     pin 4

DACMCP4821::DACMCP4821(int CS, int SDHN, int LDAC)
{
  pinMode(CS,OUTPUT);
  pinMode(SDHN,OUTPUT);
  pinMode(LDAC,OUTPUT);
}

void DACMCP4821::initDAC(){
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  digitalWrite(7,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
}

byte DACMCP4821::writeDAC (int digitalData,byte ganancia){
 if (ganancia == 1){           
		data  = digitalData | 0x3000;
		MSByte = (data & 0xff00) >> 8;
		LSByte = data & 0xff;
		PORTD = PORTD & 0xfb; // PIN2_CS = 0
        SPI.transfer (MSByte);
        SPI.transfer (LSByte);
        PORTD = PORTD | 0x04;  // PIN2_CS = 1
        return MSByte;
        }
     if (ganancia == 2){
        data = digitalData | 0x1000;
        MSByte = (data & 0xff00) >> 8;
		LSByte =  data & 0xff;
		PORTD = PORTD & 0xfb; // PIN2_CS = 0
        SPI.transfer (MSByte);
        SPI.transfer (LSByte);
        PORTD = PORTD | 0x04;  // PIN2_CS = 1
        return MSByte;
        }	
        }     
