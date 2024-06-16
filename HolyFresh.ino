#include <Servo.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>
Servo myservo;
  const int trigPin = 12;
  const int echoPin = 11;
  AF_DCMotor motor1(1); 
  AF_DCMotor motor2(2); 
  AF_DCMotor motor3(3); 
  AF_DCMotor motor4(4);


void setup() {
myservo.attach(10); 

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
  // spray every 1 second
  if ((currentMillis - previousMillis >= sprayInterval*10) && distance >= 20 || distance == 0) {
    previousMillis = currentMillis;
    spray();
  }

    while (distance <= 20)
    {
      moveLeft();
    }


    if (Serial.available() > 0 && distance >= 20 || distance == 0) {
    char command = Serial.read();
 


    switch(command) {
      case 'F': // Move forward
        moveLeft();
        break;
      case 'D':
      Serial.println(distance);
      break;
      case 'B': // Move backward
        moveBackward();
                break;

      case 'L': // Move left
        moveLeft();
                break;

      case 'R': // Move right
        moveRight();
                break;

      case 'S': // Spin
        spin();
                break;

      case 'G': // Refresh/Spray
        spray();
                break;

      default:
        stop();
        
    }
  }
}


void spray() 
{
  myservo.write(90); // move servo to press the aerosol button
  delay(sprayDuration);
  myservo.write(0); // move servo to starting position
  delay(1000); 
}


void moveForward() {
  motor1.run(FORWARD);
}

void moveBackward() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
 
void moveLeft() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
 
void moveRight() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
 
void spin() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
 
void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
