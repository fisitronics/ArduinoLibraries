#include <SPI.h>
#include <DACMCP4821.h> 

//
//     ******** MCP4821 Pinout ********
//     ********************************
//     SDI Pin to MOSI Pin 11 Arduino UNO
//     SCK Pin to SCK Pin 13 Arduino UNO

/* Configure CS,SHUTDOWN and LDAC Pins */

DACMCP4821 dac(2,7,4);
int outputAnalog;
byte ganancia;
void setup(){
// Inicializo el DAC
dac.initDAC();
Serial.begin(9600);
}
void loop(){
  outputAnalog = 4095; 
  /* writeDAC returns the MSB byte for testing. You can choose in the 
     second parameter the Gain1x = 1 or Gain2x = 2 */
  byte msb = dac.writeDAC(outputAnalog,2);
  Serial.print("MSB: ");
  Serial.println(msb,HEX);
  delay(1000);
  
  outputAnalog = 3100; 
  msb = dac.writeDAC(outputAnalog,2);
  Serial.print("MSB: ");
  Serial.println(msb,HEX);
  delay(1000);
  
  outputAnalog = 2096; 
  msb = dac.writeDAC(outputAnalog,2);
  Serial.print("MSB: ");
  Serial.println(msb,HEX);
  delay(1000);
  
  outputAnalog = 1100; 
  msb = dac.writeDAC(outputAnalog,2);
  Serial.print("MSB: ");
  Serial.println(msb,HEX);
  delay(1000);
}
