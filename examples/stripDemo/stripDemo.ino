/*
  Strip RGB LED Demo WS2812 LED 
  Author: Bonezegei (Jofel Batutay)
  Date: October 2023 
  Uses 24 bit Hex color format
  Note : The Colors used on this demo was not set to maximum since it will be too bright during testing
*/

#include <Bonezegei_WS2812.h>

#define LED_COUNT 64
Bonezegei_WS2812 rgb(14, LED_COUNT);

void setup() {
  Serial.begin(115200);
  rgb.begin();
}

void loop() {
  rgb.fill(0x0f0000);  //RED
  delay(1000);
  rgb.fill(0x0f00);  //GREEN
  delay(1000);
  rgb.fill(0x0f);  //BLUE
  delay(1000);
  rgb.fill(0x0);
  delay(1000);

  for (int a = 0; a < LED_COUNT; a++) {
    rgb.setPixel(a, 0x0f0000);
    delay(10);
  }

  for (int a = 0; a < LED_COUNT; a++) {
    rgb.setPixel(a, 0x0f00);
    delay(10);
  }

  for (int a = 0; a < LED_COUNT; a++) {
    rgb.setPixel(a, 0x0f);
    delay(10);
  }

  for (int a = 0; a < LED_COUNT; a++) {
    rgb.setPixel(a, a << 16);
    delay(20);
  }

  for (int a = 0; a < LED_COUNT; a++) {
    rgb.setPixel(a, a << 8);
    delay(20);
  }

  for (int a = 0; a < LED_COUNT; a++) {
    rgb.setPixel(a, a);
    delay(20);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill(a);  //BLUE
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill(a);  //BLUE
    delay(10);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill(a << 8);
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill(a << 8);
    delay(10);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill(a);
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill(a);
    delay(10);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill(a << 16);
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill(a << 16);
    delay(10);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill((a << 16) | (a << 8));
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill((a << 16) | (a << 8));
    delay(10);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill((a << 8) | a);
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill((a << 8) | a);
    delay(10);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill((a << 16) | a);
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill((a << 16) | a);
    delay(10);
  }

  //fade
  for (int a = 0; a < 96; a++) {
    rgb.fill((a << 8) | (a << 16) | a);
    delay(10);
  }
  for (int a = 96; a > 0; a--) {
    rgb.fill((a << 8) | (a << 16) | a);
    delay(10);
  }
}
