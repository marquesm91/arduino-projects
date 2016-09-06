#include "Component.h"

// configure each component with a name and a pin number
Component taskRed("t_red", 11);
Component taskYellow("t_yellow", 10);
Component taskGreen("t_green", 9);

void setup() 
{
  Serial.begin(9600);

  taskRed.runtime(3000); // task set to run during 3 seconds
  taskRed.downtime(3000); // task set to don't run during 3 seconds

  taskYellow.runtime(2000);
  taskYellow.downtime(2000);

  taskGreen.runtime(1000);
  taskGreen.downtime(1000);

  // set the task pins as outputs:
  pinMode(taskRed.pin(), OUTPUT);
  pinMode(taskYellow.pin(), OUTPUT);
  pinMode(taskGreen.pin(), OUTPUT);      
}

void loop()
{
  taskRed.run();
  taskYellow.run();
  taskGreen.run();

  // Meanwhile we could receive data via serial
  if (Serial.available() > 0) {

    int incomingByte = Serial.read(); // Read the incoming byte:

    // Say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }

}