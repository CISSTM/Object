/*
Wirering:
APC220 > Arduino
gnd > gnd
vcc > 5V
en > Not connected
RXD > D3
TXD > D2
AUX > Not connected
SET > Not connected
*/


#include <SoftwareSerial.h>
int number = 0;

SoftwareSerial mySerial(10 , 11); 

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  (number++);
  Serial.print("APC220 test ");
  Serial.println(number);
  mySerial.print("APC220 test ");
  mySerial.println(number);
  delay(100);
}
