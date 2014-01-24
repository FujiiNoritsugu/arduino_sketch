void setup(){
    Serial.begin(9600);
}

void loop(){
  int val1 = analogRead(0);
  int val2 = analogRead(1);
  int val3 = analogRead(2);
  Serial.println(val1);
  Serial.println(val2);
  Serial.println(val3);
  delay(100);
}
