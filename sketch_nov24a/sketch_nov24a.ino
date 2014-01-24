void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println("GET /home?action_type=3 HTTP/1.1");
  Serial.println("Host: cloudhole491.appspot.com");
  Serial.println();
  delay(10000);
}

