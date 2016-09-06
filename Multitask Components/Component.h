#include <Arduino.h>

class Component
{
  private:
    String _name;
    int _pin;
    long _runtime;
    long _downtime;
    unsigned long _previousMillis;

  public:
    Component(char* name, int pin){
      _name = name;
      _pin = pin;
      _runtime = 1000;
      _downtime = 1000;
      _previousMillis = 0;
    }

    // Component Interface
    String name(){ return _name; }
    int pin(){ return _pin; }
    virtual void routine() = 0;
    void runtime(int value){ _runtime = value; } // Run during value seconds (default 1s)
    void downtime(int value){ _downtime = value; } // Don't run during value seconds (default 1s)

  protected:
    void previousMillis(unsigned long value){ _previousMillis = value; }
    unsigned long previousMillis(){ return _previousMillis; }
    long runtime(){ return _runtime; }
    long downtime(){ return _downtime; }
};