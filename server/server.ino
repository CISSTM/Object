#include <SPI.h>
#include <RH_RF69.h>

#define RF69_FREQ 868.0

#define RFM69_INT     3
#define RFM69_CS      4
#define RFM69_RST     2

RH_RF69 rf69(RFM69_CS, RFM69_INT);

int16_t packetnum = 0;

void setup() 
{
  Serial.begin(9600);
    
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, LOW);

  digitalWrite(RFM69_RST, HIGH);
  delay(10);
  digitalWrite(RFM69_RST, LOW);
  delay(10);

  pinMode(LED_BUILTIN, OUTPUT);
  
  if (!rf69.init()) {
    Serial.println("RFM69 radio init failed");
    while (1);
  }
  Serial.println("RFM69 radio init OK!");

  if (!rf69.setFrequency(RF69_FREQ)) {
    Serial.println("setFrequency failed");
  }

  rf69.setTxPower(20, true);
}



void loop() {
  delay(100);

  char radiopacket[20] = "Find me.";
  itoa(packetnum++, radiopacket+13, 10);
  Serial.print("Sending "); Serial.println(radiopacket);
  
  rf69.send((uint8_t *)radiopacket, strlen(radiopacket));
  rf69.waitPacketSent();
}
