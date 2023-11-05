/*
  Matrix 8x8 Rainbow Demo WS2812 LED 
  Author: Bonezegei (Jofel Batutay)
  Date: November 2023 
  Uses 24 bit Hex color format
  Note : The Colors used on this demo was not set to maximum since it will be too bright during testing
*/

#include <Bonezegei_WS2812.h>

Bonezegei_WS2812 rgb(14, 8, 8);
int c = 0;
void setup() {
  Serial.begin(115200);
  rgb.begin();


  rgb.fill(0x0);
  delay(5);

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(0, a, 0x0F0000);
  }
  rgb.display();

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(1, a, 0x0F0400);
  }
  rgb.display();

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(2, a, 0x040F00);
  }
  rgb.display();

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(3, a, 0x000F00);
  }
  rgb.display();

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(4, a, 0x000F04);
  }
  rgb.display();

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(5, a, 0x00040F);
  }
  rgb.display();

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(6, a, 0x0F000F);
  }
  rgb.display();

  for (int a = 0; a < 8; a++) {
    rgb.setPixel(7, a, 0x0F0F0F);
  }
  rgb.display();
}

void loop() {
}
