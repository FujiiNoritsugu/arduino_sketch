#include <OLED.h>

// Rx pin, Tx pin, reset pin
OLED oled(0, 1, 4);

void setup() {
  // 
  oled.init();

  // 
  oled.setBackgroundColour(OLED_BLACK);
}

void loop() {
  // 
  oled.clearScreen();

  // 
  oled.drawStringAsText(0, 0, OLED_SMALL_SIZE_FONT, "Make: ", OLED_RED);

  // Cyan
  unsigned int color = oled.get16bitColourFromRGB(0, 174, 239);
  oled.drawStringAsText(6, 0, OLED_SMALL_SIZE_FONT, "PROJECTS", color);

  // 
  char timeString[17];
  sprintf(timeString, "time: %10d", millis());
  oled.drawStringAsText(0, 1, OLED_SMALL_SIZE_FONT, timeString, OLED_WHITE);

  // Magenta
  color = oled.get16bitColourFromRGB(236, 0, 140);
  oled.setPenSize(OLED_SOLID);
  oled.drawCircle(64, 64, 16, color);

  // Yellow
  color = oled.get16bitColourFromRGB(255, 212, 0);
  oled.setPenSize(OLED_WIRE_FRAME);
  oled.drawRectangle(20, 20, 50, 50, color);

  delay(1000);
}
