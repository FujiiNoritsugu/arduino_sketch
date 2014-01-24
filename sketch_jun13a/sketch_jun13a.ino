#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly: 
    if (mySerial.available())
    Serial.write(Serial.read());

}
