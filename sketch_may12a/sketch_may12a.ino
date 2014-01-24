#include <Goldelox_Const4D.h>
#include <Goldelox_Const4DSerial.h>
#include <Goldelox_Serial_4DLib.h>
#include <Goldelox_Types4D.h>

#define DisplaySerial Serial         // define display serial port

Goldelox_Serial_4DLib Display(&DisplaySerial);      // declare this serial port

void setup(void)
{
  //Reset the display 
  pinMode(2, OUTPUT); // define D2 as an output pin (Reset on the 4D Arduino Adaptor Shield)
  digitalWrite(2, HIGH); // Reset
  delay(100);
  digitalWrite(2, LOW); // Clear Reset
  
  delay(3000);  // Allow time for the display to initialize before communicating
  
  Display.TimeLimit4D = 5000 ; // 5 second timeout on all commands
  DisplaySerial.begin(9600) ;  // initialize serial port and set Baud Rate to 9,600
  Display.gfx_Cls() ;       // clear display
  
  Display.putstr("Hello World\n\n") ;        // send "Hello World" string to display
  Display.putstr("Serial Display test\n\n\n") ;      //send second string to display
  Display.txt_Attributes(BOLD + INVERSE + ITALIC + UNDERLINED) ;     // change and set new text format
  Display.txt_Xgap(3) ;
  Display.txt_Ygap(3) ;
  Display.txt_BGcolour(BLUE) ;
  Display.txt_FGcolour(WHITE) ;
  Display.txt_MoveCursor(5, 0) ;          // use this cursor position
  Display.putstr("uOLED-160-G1 SPE + Arduino\n") ;         //send third string to display
}

void loop(void)
{
  // do nothing here
}

