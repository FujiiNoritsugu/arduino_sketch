#include <Servo.h>

Servo servo;
Servo servo2;
Servo servo3;

void setup(){ 
  //pinMode(9, OUTPUT);
  //pinMode(7, OUTPUT);
  //pinMode(5, OUTPUT);
  //pinMode(3, OUTPUT);
  //pinMode(1, OUTPUT);
  servo.attach(3);
  servo2.attach(5);
  servo3.attach(9);
}

void loop(){
  //Serial.println("loop start");
  //servo.write(90);
  moveArm();
  delay(1000);
}

void moveArm(){
//Serial.println("moveArm start");
servo3.write(30);
        //analogWrite(1, 0);
        //analogWrite(3, 180);
        //analogWrite(5, 180);
        //analogWrite(7, 180);
        //analogWrite(8, 90);
        delay(1000);
//servo.write(90);
servo3.write(60);
        delay(1000);
servo3.write(70);
        //analogWrite(1, 90);
//Serial.println("moveArm end");
}
