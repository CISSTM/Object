#include <Wire.h> 
#include "RTClib.h"
#include <SoftwareSerial.h>

    /*
    Wirering antenna:
    APC220 > Arduino
    gnd > gnd
    vcc > 5V
    en > Not connected
    RXD > D3
    TXD > D2
    AUX > Not connected
    SET > Not connected
    */

RTC_DS1307 rtc;

SoftwareSerial mySerial(10, 11);
unsigned long time;
void setup() {
    pinMode(A3, OUTPUT);
    digitalWrite(A3, HIGH);
    pinMode(A2, OUTPUT);
    digitalWrite(A2, LOW);

    Serial.begin(9600);
    mySerial.begin(9600);

    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        while (1);
    }

    if (!rtc.isrunning()) {
        Serial.println("RTC is NOT running!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop() {

    DateTime now = rtc.now();
  
   /* Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    mySerial.print(now.hour(), DEC);
    mySerial.print(':');
    mySerial.print(now.minute(), DEC);
    mySerial.print(':');
    mySerial.print(now.second(), DEC);
    mySerial.println(); */
    
    time = micros();
    Serial.println(time);
    mySerial.println(time);
}
