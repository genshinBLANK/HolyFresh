#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>
Servo myservo;
  const int trigPin = 12; // trig pin of the hc-sr04
  const int echoPin = 11; // echo pin of the hc-sr04
  AF_DCMotor motor1(1); 
  AF_DCMotor motor2(2); 
  AF_DCMotor motor3(3);  
  AF_DCMotor motor4(4);


void setup() {
  pinMode(trigPin, OUTPUT); // define trigPin as output
  pinMode(echoPin, INPUT); // define echoPin as input
  myservo.attach(9); // servo on pin 10
  myservo.write(180); // start off at 0 degrees
  Serial.begin(9600); // initialize serial communication
}


int sprayInterval = 180000; // interval between sprays (30mins.)
unsigned long previousMillis = 0;
const int sprayDuration = 1000; // duration of the spray being held down

void loop() {
  // uncomment this when you have a working hc-sr04
  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // int duration = pulseIn(echoPin, HIGH); // get distance from echoPin
  // double distance = duration*0.035/2; // calculate the distance in centimeters  
  
  // theoretically this should work, but it's causing issues for my project
  // if(distance <= 20){
  //   moveBackward();
  //   delay(3000);
  //   stop();
  // }

    unsigned long currentMillis = millis(); // assign the time of being ON to currentMillis
  if (currentMillis - previousMillis >= sprayInterval) // sprays according to the sprayInterval
  {
    previousMillis = currentMillis; // reset the counter
    spray();
  }

  if (Serial.available() > 0 && distance >= 20 || distance == 0) {
    char command = Serial.read(); // read char cmd from bluetooth app
    switch(command) {
      case 'F': // move forward
        moveForward();
        break;
      case 'D': // print distance
        Serial.println(distance);
        break;
      case 'B': // move backward
        moveBackward();
        break;
      case 'L': // move left
        moveLeft();
        break;
      case 'R': // move right
        moveRight();
        break;
      case 'S': // spin
        spin();
        break;
      case 'A': // spray
        spray();
        break;
      case 'G':
        stop();
    }
  }
}

// pls forgive me for messing up the direction of the 
// motors, I didn't have the patience to fix it <3
// as long as it works, it works.

void moveBackward() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
 
void moveForward() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
 
void moveRight() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void moveLeft() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
 
void spin() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
 
void stop() // stop all movement
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void spray() 
{
  myservo.write(90); // move servo to press the aerosol button
  delay(sprayDuration); // delay for the duration of the sprayDuration
  myservo.write(180); // move servo to starting position
  delay(1000); 
}
