#include "../lib/Led.h"
#include "../lib/Button.h"

// Configure each component with a name and a pin number
Led Red("t_red", 11);
Button Btn("t_button", 2);

void setup() {}

void loop()
{
  Btn.buttonLeadLed(Red);
}
