/*
  This Library is written for WS2812
  Author: Bonezegei (Jofel Batutay)
  Date : October 2023
  RGB LED Controller
*/
#include "esp32-hal.h"

#ifndef _BONEZEGEI_WS2812_H_
#define _BONEZEGEI_WS2812_H_
class Bonezegei_WS2812 {
public:
  Bonezegei_WS2812();

  rmt_data_t *led_data;
  int _pin;
  int led_count;
}

#endif
