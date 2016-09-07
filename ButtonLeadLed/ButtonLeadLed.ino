#include "../lib/Button.h"
#include "../lib/Led.h"

// Configure each component with a name and a pin number
Led Red("t_red", 11);
Button<Led> Btn("t_button", 2);

void setup() 
{
  Btn.debounceTolerance(300);
  // set the task pins as outputs:
  pinMode(Red.pin(), OUTPUT);
  pinMode(Btn.pin(), INPUT);     
}

void loop()
{
  Btn.buttonLeadLed(Red);
}
