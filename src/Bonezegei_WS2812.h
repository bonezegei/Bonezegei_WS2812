/*
  This Library is written for WS2812
  Author: Bonezegei (Jofel Batutay)
  Date : October 2023
  RGB LED Controller
*/

#include "esp32-hal.h"
#include <Arduino.h>

#ifndef _BONEZEGEI_WS2812_H_
#define _BONEZEGEI_WS2812_H_

class Bonezegei_WS2812 {
public:
  //1 LED
  Bonezegei_WS2812(int pin);
  //Multiple LED in single strip
  Bonezegei_WS2812(int pin, int led_count);
  //Multiple LED in Matrix
  Bonezegei_WS2812(int pin, int row, int col);

  //Initialize
  int begin();

  void setPixel(uint32_t color);

  void setPixel(int index, uint32_t color);

  void clear();

  //fill all LED 
  void fill(uint32_t color);

  rmt_obj_t* rmt_send = NULL;

  rmt_data_t* led_data;
  
  int _pin;
  int _row;
  int _col;
  int _led_count;
  int _led_rmt;
};

#endif
