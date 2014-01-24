void setup(){
  Serial.begin(9600);
}

void loop(){
 int value = analogRead(A3);
 Serial.println(value);
 delay(1000); 
}
