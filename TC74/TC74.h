#ifndef TC74_h
   #define TC74_h

#if defined(ARDUINO) && ARDUINO >= 100
   #include <Arduino.h>
#else
   #include <Wprogram.h>
#endif

#include <Wire.h>

class TC74{
public:
   TC74(int address);
   int readTemp();
   void initTC74();
   int readTemp(boolean shdn);
private:
   int _address; 
   int temp; 
   int readBytes;  
   boolean shdn; 
};
#endif
