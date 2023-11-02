#include "esp32-hal.h"
/*
  This Library is written for WS2812
  Author: Bonezegei (Jofel Batutay)
  Date : October 2023
  RGB LED Controller
*/
#include "Bonezegei_WS2812.h"


Bonezegei_WS2812::Bonezegei_WS2812(int pin) {
  _pin = pin;
  _led_count = 1;
}

Bonezegei_WS2812::Bonezegei_WS2812(int pin, int led_count) {
  _pin = pin;
  _led_count = led_count;
}

Bonezegei_WS2812::Bonezegei_WS2812(int pin, int row, int col) {
  _pin = pin;
  _led_count = row * col;
  _row = row;
  _col = col;
}

int Bonezegei_WS2812::begin() {
  pinMode(_pin, OUTPUT);
  if ((rmt_send = rmtInit(_pin, RMT_TX_MODE, RMT_MEM_64)) == NULL) {
    rmt_send = NULL;
    return 0;
  }
  rmtSetTick(rmt_send, 100);

  _led_rmt = _led_count * 24;

  if ((!led_data) && !(led_data = (rmt_data_t *)malloc(_led_rmt * sizeof(rmt_data_t)))) {
    return -1;
  }

  fill(0x010000);
  delay(100);
  fill(0x0100);
  delay(100);
  fill(0x01);
  delay(100);
  fill(0x0);
  delay(100);
  return 1;
}

void Bonezegei_WS2812::setPixel(uint32_t color) {
  int i = 0;
  uint32_t c = ((color & 0xff0000) >> 8) | ((color & 0xff00) << 8) | (color & 0xff);  //color correction
  for (int a = 0; a < 24; a++) {
    if ((c & (1 << (23 - a)))) {
      led_data[i].level0 = 1;
      led_data[i].duration0 = 8;
      led_data[i].level1 = 0;
      led_data[i].duration1 = 4;
    } else {
      led_data[i].level0 = 1;
      led_data[i].duration0 = 4;
      led_data[i].level1 = 0;
      led_data[i].duration1 = 8;
    }
    i++;
  }
  rmtWrite(rmt_send, led_data, _led_rmt);
}

void Bonezegei_WS2812::setPixel(int index, uint32_t color) {
  int i = 24 * index;
  uint32_t c = ((color & 0xff0000) >> 8) | ((color & 0xff00) << 8) | (color & 0xff);  //color correction
  for (int a = 0; a < 24; a++) {
    if ((c & (1 << (23 - a)))) {
      led_data[i].level0 = 1;
      led_data[i].duration0 = 8;
      led_data[i].level1 = 0;
      led_data[i].duration1 = 4;
    } else {
      led_data[i].level0 = 1;
      led_data[i].duration0 = 4;
      led_data[i].level1 = 0;
      led_data[i].duration1 = 8;
    }
    i++;
  }
  rmtWrite(rmt_send, led_data, _led_rmt);
}

void Bonezegei_WS2812::_setPixel(int index, uint32_t color) {
  int i = 24 * index;
  uint32_t c = ((color & 0xff0000) >> 8) | ((color & 0xff00) << 8) | (color & 0xff);  //color correction
  for (int a = 0; a < 24; a++) {
    if ((c & (1 << (23 - a)))) {
      led_data[i].level0 = 1;
      led_data[i].duration0 = 8;
      led_data[i].level1 = 0;
      led_data[i].duration1 = 4;
    } else {
      led_data[i].level0 = 1;
      led_data[i].duration0 = 4;
      led_data[i].level1 = 0;
      led_data[i].duration1 = 8;
    }
    i++;
  }
}

//set pixel in WS2812 Matrix
void Bonezegei_WS2812::setPixel(int x, int y, uint32_t color) {
  _setPixel((int)((x * _col) + y), color);
}

void Bonezegei_WS2812::display() {
  rmtWrite(rmt_send, led_data, _led_rmt);
  digitalWrite(_pin, LOW);
  delay(5);
}

void Bonezegei_WS2812::clear() {
  for (int a = 0; a < _led_rmt; a++) {
    led_data[a].level0 = 1;     // T0H
    led_data[a].duration0 = 4;  // 0.4us
    led_data[a].level1 = 0;     // T0L
    led_data[a].duration1 = 8;  // 0.8us
  }
  rmtWrite(rmt_send, led_data, _led_rmt);
}

void Bonezegei_WS2812::fill(uint32_t color) {
  for (int a = 0; a < _led_count; a++) {
    _setPixel(a, color);
  }
  rmtWrite(rmt_send, led_data, _led_rmt);
  digitalWrite(_pin, LOW);
  delayMicroseconds(100);
  //delay(50);
}
