#include <TC74.h>
#include <Wire.h>

/* ******* Arduino and TC74 Pinout ******* 
   ***************************************
   1. Use 10k pullup resistor for SDA and SCLK to +5 Vdc
   2. SDA pin to A4 Arduino UNO pin 
   3. SCLK Pin to A5 Arduino UNO Pin */
   
int address = 75; // TC74-A3 datasheet
int temperatura;
TC74 tc74(address);
void setup(){
  tc74.initTC74();
  Serial.begin(9600);
}
void loop(){
Serial.print("Temperatura: ");
temperatura = tc74.readTemp();
Serial.print(temperatura);
Serial.println(" Grados C");
delay(1000);
}
