int angle1, angle2, angle3, angle4;
int MAX = 0xffff;
int temp1=MAX, temp2=MAX, temp3=MAX, temp4=MAX;
boolean firstData;
void setup(){
  Serial.begin(9600);
  pinMode(11,INPUT);
}

void loop(){
  angle1 = analogRead(A5);
  angle2 = analogRead(A4);
  angle3 = analogRead(A3);
  angle4 = analogRead(A2);
  //Serial.print(angle1);
  //Serial.print(",");
  //Serial.print(angle2);
  //Serial.print(",");
  //Serial.print(angle3);
  //Serial.print(",");
  //Serial.print(angle4);
  //Serial.println();
 
  firstData = true;
  String param = "";
  int value = -1; 
  
  if(checkValue(temp1,angle1)){
    if(temp1 != MAX){
      value = 1;
      Serial.println(1);
    }
  }
  temp1 = angle1;

  if(checkValue(temp2,angle2)){
    if(temp2 != MAX){
      value = 2;
      Serial.println(2);
    }
  }
  temp2 = angle2;

  if(checkValue(temp3,angle3)){
    if(temp3 != MAX){
      value = 3;
      Serial.println(3);
    }
  }
  temp3 = angle3;

  if(checkValue(temp4,angle4)){
    if(temp4 != MAX){
      value = 4;
      Serial.println(4);
    }
  }
  temp4 = angle4;
   
   //if(value != -1){
   //  param = makeParam("angle", value, param);
   //}
   
  if(digitalRead(11) == HIGH){
     //param = makeParam("piston", 1, param);
     Serial.println(5);
  }

  if(!firstData){
    //sendRequest(param);
  }
  delay(1000);
}

String makeParam(String paramName, int paramValue, String param){
 if(firstData){
   param = param + "?";
   firstData = false;
 }else{
   param = param + "&";
 }
 return param + paramName + "=" + String(paramValue);
}

boolean checkValue(int temp, int angle){
  if( (temp - angle) > 15){
    return true;
  }else{
    return false;
  }
}

int calcAngle(int data, int index){
  int max, min;
  if(index == 1){
     max = 280;
     min = 250;
    }
    else if(index == 2){
     max = 287;
     min = 230;
    }
    else if(index == 3){
     max = 300;
     min = 270;
    }
    else if(index == 4){
     max = 265;
     min = 200;
    }
    if(data < min) data = min;
    if(data > max) data = max;
    int angle = map(data, max, min, 90, 180);
    return angle;
}

void  sendRequest(String param){
  String request = "GET /home" + param + " HTTP/1.1";
  Serial.println(request);
  Serial.println("Host: cloudhole491.appspot.com");
  Serial.println();
}
