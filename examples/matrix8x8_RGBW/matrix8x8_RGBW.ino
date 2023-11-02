/*
  Matrix 8x8 RGBW LED Demo WS2812 LED 
  Author: Bonezegei (Jofel Batutay)
  Date: November 2023 
  Uses 24 bit Hex color format
  Note : The Colors used on this demo was not set to maximum since it will be too bright during testing
*/

#include <Bonezegei_WS2812.h>

//Declare matrix
//param1 pin
//param2 Row
//param3 Column
Bonezegei_WS2812 rgb(14, 8, 8);

void setup() {
  Serial.begin(115200);
  rgb.begin();

  rgb.fill(0x0);
  delay(5);

  for(int a=0; a<8; a++){
    rgb.setPixel(0, a, 0x0F0000); //param1 = X    param2 = Y   param3 = Color
    rgb.setPixel(1, a, 0x0F0000);
  }
  rgb.display();

  for(int a=0; a<8; a++){
    rgb.setPixel(2, a, 0x0F00);
    rgb.setPixel(3, a, 0x0F00);
  }
  rgb.display();

  for(int a=0; a<8; a++){
    rgb.setPixel(4, a, 0x0F);
    rgb.setPixel(5, a, 0x0F);
  }
  rgb.display();

  for(int a=0; a<8; a++){
    rgb.setPixel(6, a, 0x0F0F0F);
    rgb.setPixel(7, a, 0x0F0F0F);
  }
  rgb.display();
}

void loop() {
}
