#ifndef LED_H
#define LED_H

#include "Component.h"

class Led : public Component{
private:
  int _state; // Led state (range 0 to 255 if PWM used)

public:
  Led(char* name, int pin) : Component(name, pin) { _state = 0; }
  
  void state(int value){ _state = value; }
  int state(){ return _state; }

  // Blink Led  with specific runtime and downtime (default 1s for both)
  void advancedBlink(){
    unsigned long currentMillis = millis();

    if((_state == 1) && (currentMillis - this->previousMillis() >= this->runtime()))
    {
      _state = 0; // Turn it off
      digitalWrite(this->pin(), _state);
      this->previousMillis(currentMillis);
    }
    else if ((_state == 0) && (currentMillis - this->previousMillis() >= this->downtime()))
    {
      _state = 1; // Turn it on
      digitalWrite(this->pin(), _state);
      this->previousMillis(currentMillis);
    } 
  }

  /*

    Implement more rountine methods here if desired
  
  */
};

#endif