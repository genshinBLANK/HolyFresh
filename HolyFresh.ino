#include <Servo.h>


Servo myservo;
  const int trigPin = 12;
  const int echoPin = 11;

void setup() {
myservo.attach(9); 

myservo.write(0); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Initialize serial communication
}

int sprayInterval = 1000; // interval between sprays
unsigned long previousMillis = 0;
const int sprayDuration = 1000;

void loop() {
  unsigned long currentMillis = millis();
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
int duration = pulseIn(echoPin, HIGH);
double distance = duration*0.035/2;
Serial.println(distance);
  // spray every 1 second
  if ((currentMillis - previousMillis >= sprayInterval*10) && distance >= 20 || distance == 0) {
    previousMillis = currentMillis;
    spray();
  }
}

void spray() 
{
  myservo.write(90); // move servo to press the aerosol button
  delay(sprayDuration);
  myservo.write(0); // move servo to starting position
  delay(500); 
}
