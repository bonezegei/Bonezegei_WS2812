#include "esp32-hal.h"
//#include "esp32-hal-rgb-led.h"


#include "esp32-hal-rgb-led.h"

rmt_data_t matrix_data[2020];
static rmt_obj_t* rmt_send = NULL;
static bool initialized = false;


void setPixel(int index, uint8_t red_val, uint8_t green_val, uint8_t blue_val) {

  uint8_t color[3] = { green_val, red_val, blue_val };
  int i = index * 24;
  for (int col = 0; col < 3; col++) {
    for (int bit = 0; bit < 8; bit++) {
      if ((color[col] & (1 << (7 - bit)))) {
        // HIGH bit
        matrix_data[i].level0 = 1;     // T1H
        matrix_data[i].duration0 = 8;  // 0.8us
        matrix_data[i].level1 = 0;     // T1L
        matrix_data[i].duration1 = 4;  // 0.4us
      } else {
        // LOW bit
        matrix_data[i].level0 = 1;     // T0H
        matrix_data[i].duration0 = 4;  // 0.4us
        matrix_data[i].level1 = 0;     // T0L
        matrix_data[i].duration1 = 8;  // 0.8us
      }
      i++;
    }
  }
}

void clear() {
  for (int a = 0; a < 64; a++) {
    setPixel(a, 0, 0, 0);
  }
}


void clearColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int a = 0; a < 64; a++) {
    setPixel(a, r, g, b);
  }
  display();
}

void display() {
  rmtWrite(rmt_send, matrix_data, 2020);
}


/* void neopixelWrite2(uint8_t pin, uint8_t red_val, uint8_t green_val, uint8_t blue_val) {
  rmt_data_t led_data[24];
  static rmt_obj_t* rmt_send = NULL;
  static bool initialized = false;

  uint8_t _pin = pin;


  if (!initialized) {
    if ((rmt_send = rmtInit(_pin, RMT_TX_MODE, RMT_MEM_64)) == NULL) {
      rmt_send = NULL;
      return;
    }
    rmtSetTick(rmt_send, 100);
    initialized = true;
  }


  int i = 0;
  for (int col = 0; col < 3; col++) {
    for (int bit = 0; bit < 8; bit++) {
      if ((color[col] & (1 << (7 - bit)))) {
        // HIGH bit
        led_data[i].level0 = 1;     // T1H
        led_data[i].duration0 = 8;  // 0.8us
        led_data[i].level1 = 0;     // T1L
        led_data[i].duration1 = 4;  // 0.4us
      } else {
        // LOW bit
        led_data[i].level0 = 1;     // T0H
        led_data[i].duration0 = 4;  // 0.4us
        led_data[i].level1 = 0;     // T0L
        led_data[i].duration1 = 8;  // 0.8us
      }
      i++;
    }
  }
  rmtWrite(rmt_send, led_data, 24);
} */



void setup() {
  Serial.begin(115200);
  pinMode(14, OUTPUT);

  if (!initialized) {
    if ((rmt_send = rmtInit(14, RMT_TX_MODE, RMT_MEM_64)) == NULL) {
      rmt_send = NULL;
      return;
    }
    rmtSetTick(rmt_send, 100);
    initialized = true;
  }
/*   clear();
  setPixel(7, 0, 255, 0);
  setPixel(2, 0, 0, 255);
  display();
  delay(5000);
  setPixel(1, 255, 0, 0);
  setPixel(63, 255, 128, 0);
  display();
  delay(5000);
  setPixel(8, 0, 128, 128);
  setPixel(63, 32,32,32);
  display(); */

  /*   neopixelWrite(14, 255, 0, 0);
  neopixelWrite(14, 0, 255, 0);
  neopixelWrite(14, 0, 0, 255);
  neopixelWrite(14, 0, 255, 255); */
}


void loop() {
   clearColor(0,0,0);
   delay(2000);
   clearColor(16,0,0);
   delay(2000);
   clearColor(0,16,0);
   delay(2000);
   clearColor(0,0,16);
   delay(2000);
   clearColor(16,16,0);
   delay(2000);
   clearColor(0,16,16);
   delay(2000);
   clearColor(16,16,16);
   delay(2000);
}
