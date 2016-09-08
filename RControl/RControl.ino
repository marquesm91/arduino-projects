#include <IRremote.h>
#include "../lib/SamsungRemote.h"

SamsungRemote sr("sremote", 3); // IR emissor attached in pin 3

void setup() {
  Serial.begin(9600);
}

void loop() { 

  if (Serial.available() > 0) {

    int incomingByte = Serial.read();
    
    switch (incomingByte){
      case 'p': sr.powerButton(); break;
      case 'w': sr.volUpButton(); break;
      case 's': sr.volDownButton(); break;
      case 'i': sr.upButton(); break;
      case 'j': sr.leftButton(); break;
      case 'k': sr.downButton(); break;
      case 'l': sr.rightButton(); break;
      case ' ': sr.centerButton(); break;
      case 'q': sr.hdmiButton(); break;
      case 'e': sr.sourceButton(); break;
      case 'm': sr.muteButton(); break;
    }

  }
}