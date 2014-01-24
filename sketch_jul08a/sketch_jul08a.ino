#include <Servo.h>

Servo myServo;
Servo myServo2;
Servo myServo3;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(8);
  myServo2.attach(9);
  myServo3.attach(10);
}

void loop() {
  myServo3.writeMicroseconds(2000);
  delay(1000);
  myServo3.writeMicroseconds(1000);
}

