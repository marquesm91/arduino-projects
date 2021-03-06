#include "../lib/Led.h"

// Configure each component with a name and a pin number
Led taskRed("t_red", 11);
Led taskYellow("t_yellow", 10);
Led taskGreen("t_green", 9);

void setup() 
{
  Serial.begin(9600);
  taskRed.runtime(3000); 
  taskRed.downtime(1000);

  taskYellow.runtime(2000);
  taskYellow.downtime(2000);

  taskGreen.runtime(1000);
  taskGreen.downtime(3000);

  // set the task pins as outputs:
  pinMode(taskRed.pin(), OUTPUT);
  pinMode(taskYellow.pin(), OUTPUT);
  pinMode(taskGreen.pin(), OUTPUT);      
}

void loop()
{
  taskRed.advancedBlink();
  taskYellow.advancedBlink();
  taskGreen.advancedBlink();

  // Meanwhile we could receive data via serial
  if (Serial.available() > 0) {

    int incomingByte = Serial.read(); // Read the incoming byte:

    // Say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte); // ASCII table printed
  }

}
