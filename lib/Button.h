#ifndef BUTTON_H
#define BUTTON_H

#include "Component.h"

template <class T>
class Button : public Component{
private:
	int _state;
	int _lastState;
	unsigned long _toleranceTime; // Tolerance to resolve Debounce 
	const int MIN_TOL = 100; // Minimum tolerance

public:
	Button(char* name, int pin) : Component(name, pin) { 
		_state = 0; 
		_lastState = _state;
		_toleranceTime = MIN_TOL;
	}
	
	void debounceTolerance(unsigned long value){ 
		if (value <= MIN_TOL) _toleranceTime = MIN_TOL;
		else _toleranceTime = value; // value in milliseconds
	}
	
	void buttonLeadLed(T &Component){	
	  _state = digitalRead(this->pin()); // if pressed _state = 1

	  if (_state != _lastState){
			
			if ((millis() - this->previousMillis()) > _toleranceTime) {
				
				if ((_state == 1) && (Component.state() == LOW))
				{
				 	Component.state(HIGH);
				  digitalWrite(Component.pin(), Component.state()); // Turn LED on
				  this->previousMillis(millis());
				}
				else if ((_state == 1) && (Component.state() == HIGH))
				{
				 	Component.state(LOW);
				  digitalWrite(Component.pin(), Component.state()); // Turn LED off
				  this->previousMillis(millis());
				}
			}
			_lastState = _state;
		}
	}

	/*

    Implement more rountine methods here if desired
  
  */

};

#endif