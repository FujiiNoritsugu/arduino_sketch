#include "Goldelox_Serial_4DLib.h"
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(2, 3); // RX, TX
//#define DisplaySerial mySerial
#define DisplaySerial Serial

Goldelox_Serial_4DLib Display(&DisplaySerial);

void setup(){
  //mySerial.begin(9600);
  Serial.begin(9600);
  Display.gfx_Cls();
}

void loop(){                                                     
  Display.txt_FGcolour(WHITE);
  Display.putstr("Hello uLed");
  Display.gfx_Rectangle(0,10,50,70,RED);
}

