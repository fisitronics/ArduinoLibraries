#include <TC74.h>
#include <Wire.h>

/* ******* Arduino and TC74 Pinout ******* 
   ***************************************
   1. Use 10k pullup resistor for SDA and SCLK to +5 Vdc
   2. SDA pin to A4 Arduino UNO pin 
   3. SCLK Pin to A5 Arduino UNO Pin */
   
int address = 75; // TC74-A3 datasheet
int temperatura;
int i;
boolean shdn;
TC74 tc74(address);
void setup(){
  tc74.initTC74();
  Serial.begin(9600);
}
void loop(){
Serial.println("********** Read Temperature **********");
Serial.println("***********************************");
for(i=0;i<7;i++){
  Serial.print("Temperatura: ");
  temperatura = tc74.readTemp(true); // Continuous temperature
  Serial.print(temperatura);
  Serial.println(" Grados C");
  delay(1000);
}
Serial.println("********** Modo Shutdown **********");
Serial.println("***********************************");
for(i=0;i<7;i++){
  Serial.print("Temperatura: ");
  temperatura = tc74.readTemp(false); // Shutdown mode
  Serial.print(temperatura);
  Serial.println(" Grados C");
  delay(1000);
  }
}
