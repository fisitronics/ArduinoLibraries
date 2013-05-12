/* MAX127.ccp library for Microchip DAC
   by Aitor Sierra
   Version: 1.0*/

//  TWBR   prescaler   Frequency
// 
//  12       1       400   kHz  (the maximum supported frequency)
//  32       1       200   kHz
//  72       1       100   kHz  (default)
// 152       1        50   kHz
//  78       4        25   kHz
// 158       4        12.5 kHz

// To set the prescaler to 4 you need to set the bit TWPS0 in TWSR, so for example to have a clock of 12.5 kHz:
//TWBR = 158;  
//TWSR |= _BV (TWPS0);


#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <MAX127.h>
#include <Wire.h>

// 7 bit address

MAX127::MAX127(byte address){
  _address = address;
  Wire.begin();
  Serial.begin(9600);
}

int MAX127::readDAS(byte channel){
numBytes = 2; // number of Bytes to read
switch(channel){
  case 0:
    controlByte = 0x88;
    break;
  case 1:
    controlByte = 0x98;
    break;
  case 2:
    controlByte = 0xA8;
    break;
}

Wire.beginTransmission(_address);
Wire.write(controlByte);
Wire.endTransmission();
Wire.requestFrom(_address,numBytes);
MSB = Wire.read();
LSB = Wire.read();
MSByte = MSB << 4; // Shift to the left 4 bits for MSByte
LSByte = LSB >> 4; // Shift to the right 4 bits for LSByte
data = MSByte | LSByte;
Serial.print("MSByte: ");
Serial.println(MSByte,HEX);
Serial.print("LSByte: ");
Serial.println(LSByte,HEX);
Serial.print("Data: ");
Serial.println(data,HEX);
return data;
}
