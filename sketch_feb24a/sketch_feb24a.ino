void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  if(Serial1.available() > 0){
     while(1){
      int temp = Serial1.read();
      if(temp > 0){
        Serial.write(temp);
      }else{
        break;
      }
     }
  }
  Serial1.write("Test from Arduino");
  delay(1000);
}   

