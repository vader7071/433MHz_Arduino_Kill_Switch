// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>
#include <SPI.h>              // Not actually used but needed to compile
#include <ezButton.h>

#define DEBUG

RH_ASK radio(2000, 11, 12);   // Speed of 2000 bits per second, Use pin 11 for reception, Use pin 12 for transmission
ezButton button(2);

int dataTX = 0;
int btnState = 0;

const char *up = "u";

void setup(){
  #ifdef DEBUG
    Serial.begin(115200);	    // Debugging only
    Serial.println(F("Serial Monitor Started"));
    Serial.println(F("433MHz TX Module"));
    if (!radio.init()){
      Serial.println("init failed");
    }
  #endif
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  button.loop();
  btnState = button.getState();
  LED_BUILTIN = btnState;
  
  if(btnState > 0){
    #ifdef DEBUG
      Serial.println(F("Button is pressed"));
    #endif
    radio.send((uint8_t *)up, strlen(up));
  }
}
