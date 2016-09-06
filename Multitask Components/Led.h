#include "Component.h"

class Led : public Component{
private:
  int _state; // Led state (range 0 to 255 if PWM used)

public:
  Led(char* name, int pin) : Component(name, pin) { _state = 0; }
  
  void routine(){
  	this->advanced_blink();

    /*
        Add more rountine methods here if desired
    */
  }

protected:
  // Blink Led  with specific runtime and downtime (default 1s for both)
  void advanced_blink(){
    unsigned long currentMillis = millis();

    if((_state == 1) && (currentMillis - this->previousMillis() >= this->runtime()))
    {
      _state = 0; // Turn it off
      
      // Remember the last runtime and write new state on pin
      this->previousMillis(currentMillis);
      digitalWrite(this->pin(), _state);
    }
    else if ((_state == 0) && (currentMillis - this->previousMillis() >= this->downtime()))
    {
      _state = 1; // Turn it on

      // Remember the last downtime and write new state on pin
      this->previousMillis(currentMillis);
      digitalWrite(this->pin(), _state);
    } 
  }

  /*
        Implement more rountine methods here if desired
  */
};