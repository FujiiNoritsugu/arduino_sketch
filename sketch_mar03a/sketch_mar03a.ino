void setup(){
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(9, OUTPUT);
}

void loop(){
  if(digitalRead(4) == HIGH){
    Serial.println("ON");
    digitalWrite(9,HIGH);
    delay(500);
  }else{
    Serial.println("OFF");
  }
  delay(1000);
}
