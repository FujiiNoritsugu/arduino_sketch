void setup(){
}

void loop(){
  String request = "GET /home?angle1=1 HTTP/1.1";
  Serial.println(request);
  Serial.println("Host: cloudhole491.appspot.com");
  Serial.println();
  delay(1000);
}
