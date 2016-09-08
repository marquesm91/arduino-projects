#ifndef LED_H
#define LED_H

#include "Component.h"

class Led : public Component{
private:
  int _state; // Led state (range 0 to 255 if PWM used)

public:
  Led(char* name = "teste", int pin = 13) : Component(name, pin) { 
    _state = 0;
    pinMode(pin, OUTPUT);
  }
  
  void state(int value){ _state = value; }
  int state(){ return _state; }

  // Blink Led  with specific runtime and downtime (default 1s for both)
  void advancedBlink(){

    if((_state == 1) && (millis() - this->previousMillis() >= this->runtime()))
    {
      _state = 0; // Turn it off
      digitalWrite(this->pin(), _state);
      this->previousMillis(millis());
    }
    else if ((_state == 0) && (millis() - this->previousMillis() >= this->downtime()))
    {
      _state = 1; // Turn it on
      digitalWrite(this->pin(), _state);
      this->previousMillis(millis());
    } 
  }

  /*

    Implement more rountine methods here if desired
  
  */
};

#endif