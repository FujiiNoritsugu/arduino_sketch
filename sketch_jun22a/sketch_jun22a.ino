#include <Servo.h>

Servo myServo;
Servo myServo2;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(8);
  myServo2.attach(9);
  Serial1.begin(115200);
}

void loop() {
  int angle = getAngle();
  if(angle >= 0){
    Serial1.print(angle);
    myServo.write(angle);
    myServo2.write(angle);
  }
  delay(1000);
    int value = analogRead(0);
    Serial1.write("value");
    Serial1.print(value);
}

int getAngle(){
  int result = -1;
  if(Serial1.available() > 0){
     while(1){
      int temp = Serial1.read();
      if(temp >= 48 && temp < 58){
        if(result == -1){result = 0;}
        temp = temp - 48;
        result = result * 10;
        result = result + temp;
      }else{
        if(result >= 0){
          return result;
        }
        break;
      }
     }
   }
   return result;
}

