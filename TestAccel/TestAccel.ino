
void setup(){
  Serial.begin(9600);
  pinMode(5,OUTPUT);
}
int preValue = 0;
boolean first = true;
void loop(){
  int value = analogRead(A0);
  
  if(abs(value - preValue) > 200){
    if(first){
      first = false;
    }else{
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(5, LOW);
    }
    //preValue = value;
  }
  preValue = value;
  //Serial.println(value);
  delay(300);
}
