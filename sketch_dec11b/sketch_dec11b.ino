int angle1, angle2, angle3, angle4;
int temp1=-1, temp2=-1, temp3=-1, temp4=-1;
boolean firstData;
void setup(){
  Serial.begin(9600);
  pinMode(11,INPUT);
}

void loop(){
  angle1 = calcAngle(analogRead(A5),1);
  angle2 = calcAngle(analogRead(A4),2);
  angle3 = calcAngle(analogRead(A3),3);
  angle4 = calcAngle(analogRead(A2),4);
//String test = String(analogRead(A5))+","+String(analogRead(A4))+","+String(analogRead(A3))+","+String(analogRead(A2));
//Serial.println(test);
  firstData = true;
  String param = "";
  
  if(checkValue(temp1,angle1)){
    if(temp1 != -1){
      param = makeParam("angle1", angle1, param);
    }
    temp1 = angle1;
  }

  if(checkValue(temp2,angle2)){
    if(temp2 != -1){
      param = makeParam("angle2", angle2, param);
    }
    temp2 = angle2;
  }

  if(checkValue(temp3,angle3)){
    if(temp3 != -1){
      param = makeParam("angle3", angle3, param);
    }
    temp3 = angle3;
  }

  if(checkValue(temp4,angle4)){
    if(temp4 != -1){
      param = makeParam("angle4", angle4, param);
    }
    temp4 = angle4;
  }

  if(digitalRead(11) == HIGH){
     param = makeParam("piston", 1, param);    
  }

  if(!firstData){
    sendRequest(param);
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
  if(abs(temp - angle) > 15){
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
