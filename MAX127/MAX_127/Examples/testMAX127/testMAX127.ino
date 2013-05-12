/* Board I2C / TWI pins 
   Uno, Ethernet: A4 (SDA), A5 (SCL) 
   Mega2560:      20 (SDA), 21 (SCL) 
   Leonardo:      2 (SDA), 3 (SCL) 
   Due:           20 (SDA), 21 (SCL), SDA1, SCL1 
 */
#include <MAX127.h>
#include <Wire.h>
/* Address: 0x28
   A2,A1,A0: tied to GND */
   
byte address = 0x28;
int data = 0;
int channel = 2;
float tension;

MAX127 dac(address);

void setup(){ 
 Serial.begin(9600);
}
void loop(){
 data = dac.readDAS(channel);
 tension = (4.096/4096)*data;
 Serial.print("Tension: ");
 Serial.println(tension);
 delay(1000);
}
