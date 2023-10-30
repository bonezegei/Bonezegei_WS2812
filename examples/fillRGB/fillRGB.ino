/*
  Author: Jofel Batutay
  Date: October 2023
  //Fill the LED with the Primary colors Red Green and Blue
*/

#include <Bonezegei_WS2812.h>

//param1 pin
//param2 number of LED
Bonezegei_WS2812 rgb(14, 64);

void setup() {
  Serial.begin(115200);
  rgb.begin();
}

void loop() {
  rgb.fill(0x0f0000); //RED
  delay(1000);
  rgb.fill(0x0f00);   // GREEN
  delay(1000);
  rgb.fill(0x0f);     // BLUE
  delay(1000);
  rgb.fill(0x0);
  delay(1000);
}
