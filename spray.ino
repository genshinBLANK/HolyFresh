#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(10); // servo on pin 10
  myservo.write(0); // start off at 0 degrees
  Serial.begin(9600); // initialize serial communication
}

int sprayInterval = 1000; // interval between sprays
unsigned long previousMillis = 0;
const int sprayDuration = 1000; // duration of the spray being held down

void loop() {
  unsigned long currentMillis = millis(); // assign the time of being ON to currentMillis
  if (currentMillis - previousMillis >= sprayInterval*10) {
    previousMillis = currentMillis; // reset the counter
    spray();
  }
}

void spray() 
{
  myservo.write(90); // move servo to press the aerosol button
  delay(sprayDuration); // delay for the duration of the sprayDuration
  myservo.write(0); // move servo to starting position
  delay(1000); 
}

