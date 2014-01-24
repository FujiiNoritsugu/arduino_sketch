void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int i = 300;
  Serial.write("write");
  Serial.write(i);
  Serial.write("print");
  Serial.print(i);
  delay(1000);
}
