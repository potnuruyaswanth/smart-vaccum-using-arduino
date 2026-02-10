# Smart Vacuum Cleaning Prototype 🤖🧹

An autonomous vacuum cleaner prototype built using Arduino, ultrasonic sensors, and servo motors for real-time obstacle detection and navigation.

## Features
- Real-time obstacle detection using ultrasonic sensor
- Autonomous navigation and direction control
- Servo-based environment scanning
- Motor control logic for movement

## Tech Stack
- Arduino UNO
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- DC Motors + Motor Driver
- Arduino IDE (Embedded C)

## How It Works
1. Ultrasonic sensor measures distance ahead
2. If obstacle detected, servo scans left and right
3. Arduino decides best direction
4. Motors adjust movement accordingly

## Getting Started
1. Clone the repository
2. Open `arduino/smart_vacuum.ino` in Arduino IDE
3. Connect hardware as per diagram
4. Upload code to Arduino

## Future Improvements
- Add IR sensors for edge detection
- Implement mapping algorithm
- Integrate IoT control via WiFi

## Author
Your Name
