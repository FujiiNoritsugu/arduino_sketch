#include <Servo.h>

Servo myServo;
Serial1 mySerial;

void setup() {
  myServo.attach(8);
  mySerial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
   incomingByte = Serial.read();
   Serial.print("I received: ");
   Serial.println(incomingByte, DEC);
  }
  myServo.write(20);
  delay(1000);
  myServo.write(140);
  delay(1000);

}
