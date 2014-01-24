#include <Servo.h>

Servo servo1, servo2, servo3, servo4, servo5;

void setup(){
  pinMode(15, INPUT);
  pinMode(13, INPUT);
  pinMode(11, INPUT);
  pinMode(8, OUTPUT);
  
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(5);
  servo4.attach(7);
  servo5.attach(9);
  Serial.begin(9600);
}

struct Pressure {
  int pres1;
  int pres2;
  int pres3;
  int pres4; 
};

struct Pressure pressure;

struct Operation {
  int finger1;
  int finger2;
  int finger3;
  int finger4;
  int piston;
};

struct Operation operation;

void loop(){
      operation.finger1 = 90;
      operation.finger2 = 90;
      operation.finger3 = 90;
      operation.finger4 = 90;
      operation.piston = 1;

      moveArm();
      delay(100);
      upPressure();
      delay(1000);
      
      operation.finger1 = 180;
      operation.finger2 = 180;
      operation.finger3 = 180;
      operation.finger4 = 180;
      operation.piston = 0;
      moveArm();
}

void upPressure(){
      pressure.pres1 = analogRead(15);
      pressure.pres2 = analogRead(13);
      pressure.pres3 = analogRead(11);
      pressure.pres4 = analogRead(9);
}

void moveArm(){
      int fin1 = operation.finger1;
      if(fin1 != 0){
        servo1.write(fin1);
        delay(1000);
      }
      
      int fin2 = operation.finger2;
      if(fin2 != 0){
        servo2.write(fin2);
        delay(1000);
      }

      int fin3 = operation.finger3;
      if(fin3 != 0){
        servo3.write(fin3);
        delay(1000);
      }

      int fin4 = operation.finger4;
      if(fin4 != 0){
        servo4.write(fin4);
        delay(1000);
      }
      
      int piston = operation.piston;
      if(piston == 1){
        servo5.write(60);
        delay(500);
        servo5.write(120);
        delay(1000);
      }

}
