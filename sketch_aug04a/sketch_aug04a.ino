#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(8);
}

void loop() {
  myServo.write(20);
  delay(1000);
  myServo.write(140);
  delay(1000);
}

