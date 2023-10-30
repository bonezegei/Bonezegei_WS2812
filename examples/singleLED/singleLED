/*
  Single WS2812 LED 
  Author: Bonezegei (Jofel Batutay)
  Date: October 2023 
  Uses 24 bit Hex color format
*/

#include <Bonezegei_WS2812.h>

//param WS2812 pin
Bonezegei_WS2812 rgb(14);

void setup() {
  Serial.begin(115200);
  rgb.begin();
}

void loop() {
  rgb.setPixel(0x0f0000);
  delay(1000);
  rgb.setPixel(0x0f00);
  delay(1000);
  rgb.setPixel(0x0f);
  delay(1000);
  rgb.setPixel(0x0);
  delay(1000);
}
