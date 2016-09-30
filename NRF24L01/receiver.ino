/*
I/O configuration for NRF24L01 and Arduino UNO
VCC 	- 3.3V
GND 	- GND
CE 	- 7
CSN 	- 8
SCK	- 13
MOSI	- 11
MiSO	- 12
*/

#include <SPI.h>
#include "RF24.h"

RF24 radio(7,8);
byte addresses[][6] = {"0"};

int data = 0;

void setup(){
  Serial.begin(115200);
  delay(1000);
  radio.begin();
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1,addresses[0]);
  radio.startListening();
}

void loop() {
  if(radio.available()){
    while(radio.available()){
      radio.read(&data, sizeof(data));
    }
    
    Serial.println(data);
    
  }


}
