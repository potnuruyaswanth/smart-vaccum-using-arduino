#include <Servo.h>

// Pin Definitions
#define TRIG_PIN 9
#define ECHO_PIN 10

#define LEFT_MOTOR_FWD 3
#define LEFT_MOTOR_BWD 4
#define RIGHT_MOTOR_FWD 5
#define RIGHT_MOTOR_BWD 6

#define SERVO_PIN 11

Servo scanServo;

// Distance threshold (cm)
const int OBSTACLE_DISTANCE = 20;

// Function to measure distance
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

// Movement functions
void moveForward() {
  digitalWrite(LEFT_MOTOR_FWD, HIGH);
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  digitalWrite(LEFT_MOTOR_BWD, LOW);
  digitalWrite(RIGHT_MOTOR_BWD, LOW);
}

void stopMoving() {
  digitalWrite(LEFT_MOTOR_FWD, LOW);
  digitalWrite(RIGHT_MOTOR_FWD, LOW);
  digitalWrite(LEFT_MOTOR_BWD, LOW);
  digitalWrite(RIGHT_MOTOR_BWD, LOW);
}

void turnRight() {
  digitalWrite(LEFT_MOTOR_FWD, HIGH);
  digitalWrite(RIGHT_MOTOR_FWD, LOW);
  delay(400);
}

void turnLeft() {
  digitalWrite(LEFT_MOTOR_FWD, LOW);
  digitalWrite(RIGHT_MOTOR_FWD, HIGH);
  delay(400);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LEFT_MOTOR_FWD, OUTPUT);
  pinMode(LEFT_MOTOR_BWD, OUTPUT);
  pinMode(RIGHT_MOTOR_FWD, OUTPUT);
  pinMode(RIGHT_MOTOR_BWD, OUTPUT);

  scanServo.attach(SERVO_PIN);
  scanServo.write(90);

  Serial.begin(9600);
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > OBSTACLE_DISTANCE) {
    moveForward();
  } else {
    stopMoving();

    // Scan surroundings
    scanServo.write(30);
    delay(500);
    long leftDistance = getDistance();

    scanServo.write(150);
    delay(500);
    long rightDistance = getDistance();

    scanServo.write(90);

    if (leftDistance > rightDistance) {
      turnLeft();
    } else {
      turnRight();
    }
  }
}
