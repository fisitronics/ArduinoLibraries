/* MAX127.h library for Microchip DAC
   by Aitor Sierra
   Version: 1.0*/
   
/* The WProgram.h file, which provides declarations for the Arduino API,
   has been renamed to Arduino.h. To create a library that will work in
   both Arduino 0022 and Arduino 1.0, we can use an #ifdef that checks
   for the ARDUINO constant, which was 22 and is now 100. */

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Wire.h>

class MAX127
{
   public:
     MAX127(uint8_t address);
     int readDAS(byte channel);
   private:
     byte MSB;
     byte LSB;     
     int MSByte;
     int LSByte;
     uint8_t _address;
     uint8_t numBytes;
     byte controlByte;
     int data;
};

