# HolyFresh - Omnidirectional Scent Dispenser

 **Table of Contents**

 [About](#about)
- [Hardware](#hardware)
- [Software](#software)
- [Features](#features)
- [Issues I've Encountered](#issues-ive-encountered)
- [Future Ideas](#future-ideas)

## About

The Omnidirectional Scent Dispenser (OSD) is a project designed to improve air quality in indoor spaces through automated dispersion of fragrances. Using Arduino UNO R3 microcontroller and omni-directional wheels, the OSD can move seamlessly in different directions, providing an even and pleasant distribution of different aromas.

![Alt text](https://i.imgur.com/H6vGC0A.jpeg)

## Hardware

• Arduino board (e.g., Arduino Uno R3)

• Motor driver shield (e.g., L298D)

• 4xDC motors (attached to the wheels)

• Ultrasonic sensor (e.g., HC-SR04)

• Bluetooth module (e.g., HC-05 or HC-06)

• 4x1.5A Battery pack to power the Arduino and motors

• Breadboard and jumper wires

**Image of the circuit diagram:**

![Alt text](https://raw.githubusercontent.com/genshinBLANK/HolyFresh/main/circuit_diagram.png)



## Software

This Arduino project uses mecanum wheels for omnidirectional movement, controlled via Bluetooth commands. The robot includes a servo motor to activate an aerosol spray at set intervals or upon command. Additionally, an ultrasonic sensor is used to detect obstacles and adjust the robot's movement accordingly. The software coordinates motor actions and sensor inputs to achieve precise and versatile navigation.

If you want to use just the movement of the mecanum wheels or just the servo dispenser code, I've uploaded them as separate files. 

Software needed to run the program:
• Arduino IDE
• Adafruit Motor Shield Library V1.2
• Servo Library (Included in the Arduino IDE)
• Serial Communications Library (Included in the Arduino IDE)

To use the Bluetooth commands, a Bluetooth Terminal app is needed like [Serial Bluetooth Terminal](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal), in which the user needs to configure the M1-7 with the correct letter to execute the command.

## Features

• **Omni-directional movement**

![Mecanum-wheel-working-principle](https://github.com/genshinBLANK/HolyFresh/assets/93366890/3d056ff7-9738-4735-99a1-b23c29e3e7a7)

• Forward


https://github.com/genshinBLANK/HolyFresh/assets/93366890/062c4825-acd2-4489-a12f-33a1d97fd70c



• Backward


https://github.com/genshinBLANK/HolyFresh/assets/93366890/64659fc9-cb50-4b32-8e65-356cca5c5b29



• Left


https://github.com/genshinBLANK/HolyFresh/assets/93366890/14e1ee11-b438-44c2-9552-4211da9be73e



• Right


https://github.com/genshinBLANK/HolyFresh/assets/93366890/77f9583d-6b5d-4b10-b325-0d45529931d5



• Spin


https://github.com/genshinBLANK/HolyFresh/assets/93366890/d7c479c3-3af0-4954-bac4-3b374cd783db



• Spray


https://github.com/genshinBLANK/HolyFresh/assets/93366890/14f352ce-bf43-4f31-a1e8-8cd627e41712





## Issues I've Encountered

• **Motor Direction Confusion**: One significant issue was configuring the motor directions correctly for omnidirectional movement. The initial setup had the motors running in incorrect directions, causing the robot to move unpredictably. It required careful adjustment and testing to ensure that each motor was correctly aligned with the intended movement commands, not to mention the issues related to actually screwing on the actual wheels to the DC Motors and chassis. (P.S. just because you can screw them down to their fullest, doesn't mean you will get better results, the looser the wheels the faster they move!)

• **Ultrasonic Sensor Connection**: Another challenge was getting the part where if the robot is closer than 20cm to move backward to work. It caused all kinds of unexplainable issues like causing one of the DC motors to stop functioning or randomly disconnecting the Bluetooth module.

• **Bluetooth Communication**: Ensuring stable and reliable Bluetooth communication was also a challenge. Occasionally, commands sent from the Bluetooth app were either delayed or not received correctly by the Arduino, leading to unresponsive or erratic behavior.

## Future Ideas

• **Actually fix the Ultrasonic Sensor**

• **Fully automate the entire movement process**

• **Make a proper Bluetooth Controller app through which it can be controlled**

• **Implement more variables regarding the spray dispenser part and make it detect when the air needs to scented**

