// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

#define array_size 6
#define DEBUG

RH_ASK radio(2000, 11, 12);   // Speed of 2000 bits per second, Use pin 11 for reception, Use pin 12 for transmission

uint8_t dataRX = 0;

const int outputPin = 3;

void setup(){
  #ifdef DEBUG
    Serial.begin(115200);      // Debugging only
    Serial.println(F("Serial Monitor Started"));
    Serial.println(F("433MHz RX Module"));
    if (!radio.init()){
      Serial.println("init failed");
    }
  #endif
  
  pinMode(outputPin, OUTPUT);
}

void loop(){
  // Create a 32 byte char buffer
  uint8_t receive_buffer[1];
  uint8_t buflen = sizeof(receive_buffer);
 
  // If data is available, print it
  if (radio.recv(receive_buffer, &buflen)) {
    dataRX = receive_buffer[0];
      Serial.print(F("Message: "));
      Serial.println((char*)receive_buffer);
      Serial.print(F("Data RX Value: "));
      Serial.println(dataRX);
  }

  if (dataRX == 117){
    outputPin = HIGH;
  } else {
    outputPin = false;
  }
}
