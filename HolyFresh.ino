#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(9); 
  myservo.write(0); 
}

int sprayInterval = 1000; // interval between sprays
unsigned long previousMillis = 0;
const int sprayDuration = 500;

void loop() {
  unsigned long currentMillis = millis();
  
  // spray every 1 second
  if (currentMillis - previousMillis >= sprayInterval) {
    previousMillis = currentMillis;
    spray();
  }

void spray() 
{
  myservo.write(90); // move servo to press the aerosol button
  delay(sprayDuration);
  myservo.write(0); // move servo to starting position
  delay(500); 
}