// 40Hz -> 40/s -> 25ms / medicao

int red = 11;
int green = 10;
int hc_sr04_trigger = 7;
int hc_sr04_echo = 6;
int analogPin = 3;
float min = 0.2;
float max = 2.0;

void triggerUltrasonic(int pin){
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);
}

float measureDistance(int pin){
  pinMode(pin, INPUT);
  unsigned long duration = pulseIn(hc_sr04, HIGH); // microsseconds
  return ((duration / 1000000.0) * 340.29) / 2.0; // meters 
}

float map_distance(int value){
  return ((max - min)*value/1023.0) - min;
}

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop(){
  triggerUltrasonic(hc_sr04_trigger);
  float distance = measureDistance(hc_sr04_echo);
  float tolerance_distance = map_distance(analogRead(analogPin));

  Serial.print("Distancia do objeto = ");
  Serial.print(distance);
  Serial.println(" m");

  if(distance >= tolerance_distance){
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  } else {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }

  delay(25);
}