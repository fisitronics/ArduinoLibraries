#include <Wire.h>
int address = 0x28;
byte MSB;
byte LSB;
int MSByte = 0;
int LSByte = 0;
int data = 0;
float valor;
void setup(){
Wire.begin();
Serial.begin(9600);
}
void loop(){
Wire.beginTransmission(address);
Wire.write(0x88); // read channel 0, Input range 0-Vref
Wire.endTransmission();
Wire.requestFrom(address,2);
    MSB = Wire.read();
    LSB = Wire.read();
    MSByte = MSB << 4; // Shift to the left 4 bits for MSByte
    LSByte = LSB >> 4; // Shift to the right 4 bits for LSByte
    data = MSByte | LSByte;
    valor = (4.096/4096)*data;
    Serial.print("MSByte: ");
    Serial.println(MSByte,HEX);
    Serial.print("LSByte: ");
    Serial.println(LSByte,HEX);
    Serial.print("Data: ");
    Serial.println(data,HEX);
    Serial.print("Tension: ");
    Serial.println(valor);
    delay(1000);
}
