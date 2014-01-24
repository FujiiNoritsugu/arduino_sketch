#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#include <Servo.h>

AndroidAccessory acc("Fujii",
                    "ArduinoSample",
                    "Sample for ADK",
                    "1.0",
                    "http://www.fujii.com",
                    "0000000012345678");

Servo servo1, servo2, servo3, servo4, servo5;

void setup(){
  acc.powerOn();
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
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
  byte msg[2];
  if(acc.isConnected()){     
    int len = acc.read(msg, sizeof(msg), 1);
    if(len > 0){
      moveArm(msg);
      delay(1000);
      upPressure();
    }
  }
  delay(1000);
}

void upPressure(){
      pressure.pres1 = analogRead(0);
      pressure.pres2 = analogRead(1);
      pressure.pres3 = analogRead(2);
      pressure.pres4 = analogRead(3);
      acc.write(&pressure, sizeof(pressure));
}

void moveArm(byte msg []){
  int angle = 0;
      int finger = int(msg[0]);
      if(finger == 1){
        angle = 135;
      }else if(finger == 2){
        angle = 145;
      }else if(finger == 3){
        angle = 155;
      }else if(finger == 4){
        angle = 90;
      }
      
      if(angle != 0){
         servo1.write(angle);
         delay(500);
         servo2.write(angle);
         delay(500);
         servo3.write(angle);
         delay(500);
         servo4.write(angle);
         delay(500);
      }
      
      int piston = int(msg[1]);
      if(piston == 1){
        servo5.write(60);
        delay(500);
        servo5.write(120);
        delay(500);
      }
}

