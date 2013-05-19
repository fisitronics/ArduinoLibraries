#if defined(ARDUINO) && ARDUINO >=100
#include <Arduino.h>
#else
#include <Wprogram.h>
#endif
#include <TC74.h>
#include <Wire.h>

TC74::TC74(int address){
   _address = address;                   
}

void TC74::initTC74(){
  Wire.begin();
}

int TC74::readTemp(){
  readBytes = 1;
  Wire.beginTransmission(_address);
  int enviarDato = 0;
  Wire.write(enviarDato); // Command Byte read Temperature
  Wire.endTransmission();
  Wire.requestFrom(_address,readBytes); // request 1 byte Temperature
  while(Wire.available()==0);
  temp = Wire.read();
  return temp;
}

int TC74::readTemp(boolean shdn){
  if(shdn == true){
     readBytes = 1;
     Wire.beginTransmission(_address);
     int enviarDato = 0;
     Wire.write(enviarDato); // Command Byte read Temperature
     Wire.write(enviarDato);
     Wire.endTransmission();
     Wire.requestFrom(_address,readBytes); // request 1 byte Temperature
     while(Wire.available()==0);
     temp = Wire.read();
     return temp;
  }
  else{
     readBytes = 1;
     Wire.beginTransmission(_address);
     int enviarDato = 0x01;
     int standby = 0x80;
     Wire.write(enviarDato); // Command Byte read Temperature
     Wire.write(standby);
     Wire.endTransmission();
     Wire.requestFrom(_address,readBytes); // request 1 byte Temperature
     while(Wire.available()==0);
     temp = Wire.read();
     return temp;
  }
}
