#ifndef DACMCP4821_h
#define DACMCP4821_h

#include "Arduino.h"
#include "SPI.h"

class DACMCP4821
{
   public:
     DACMCP4821(int CS, int SHUTDOWN, int LDAC);
     void initDAC();
     byte writeDAC (int digitalData,byte ganancia);
   private:      
     byte MSByte;
     byte LSByte;
     int data;
};

#endif
