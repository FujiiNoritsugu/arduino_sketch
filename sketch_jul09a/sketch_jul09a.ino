#define DIR_A 12
#define PWM_A 3

void setup(){
 pinMode(DIR_A, OUTPUT);
 pinMode(PWM_A, OUTPUT); 
}

void loop(){
 digitalWrite(DIR_A, HIGH);
 analogWrite(PWM_A, 200);
 delay(3000);
  digitalWrite(DIR_A, LOW);
 analogWrite(PWM_A, 200);
 delay(3000);
}
