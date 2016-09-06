#include <Arduino.h>

class Component
{
  private:
    String _name;
    int _pin;
    int _state;
    long _runtime;
    long _downtime;
    unsigned long _previousMillis;
  public:
    Component(char* name, int pin){
      _name = name;
      _pin = pin;
      _state = 0;
      _runtime = 1000;
      _downtime = 1000;
      _previousMillis = 0;
    }

    String name(){ return _name; }
    int pin(){ return _pin; }
    int state(){ return _state; }

    void runtime(int value){ _runtime = value; }
    void downtime(int value){ _downtime = value; }

    void run(){
      unsigned long currentMillis = millis();

      if((_state == 1) && (currentMillis - _previousMillis >= _runtime))
      {
        _state = 0; // Turn it off
        
        // Remember the last runtime and write new state on pin
        _previousMillis = currentMillis;
        digitalWrite(_pin, _state);
      }
      else if ((_state == 0) && (currentMillis - _previousMillis >= _downtime))
      {
        _state = 1; // Turn it on
        
        // Remember the last downtime and write new state on pin
        _previousMillis = currentMillis; 
        digitalWrite(_pin, _state);
      }     
    }
};