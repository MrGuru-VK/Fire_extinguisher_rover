#include <Servo.h>

Servo myServo;

// Flame sensor pins
const int leftSensor   = 2;
const int centerSensor = 3;
const int rightSensor  = 4;

// Pump pin
const int pumpPin = 7;

// Servo pin
const int servoPin = 6;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(pumpPin, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(45);   // Default center position

  Serial.begin(9600);
}

void loop() {

  int left   = digitalRead(leftSensor);
  int center = digitalRead(centerSensor);
  int right  = digitalRead(rightSensor);

  Serial.print("L: "); Serial.print(left);
  Serial.print(" C: "); Serial.print(center);
  Serial.print(" R: "); Serial.println(right);

  // Flame detected (LOW = flame)
  if (center == 1) {
    myServo.write(45);
    digitalWrite(pumpPin, HIGH);
  }
  else if (left == LOW) {
    myServo.write(0);
    digitalWrite(pumpPin, HIGH);
  }
  else if (right == LOW) {
    myServo.write(90);
    digitalWrite(pumpPin, HIGH);
  }
  else {
    digitalWrite(pumpPin, LOW);  // No flame
  }

  delay(1000);
}
