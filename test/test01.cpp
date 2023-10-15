
hw_timer_t *My_timer = NULL;

void delay_ns(uint64_t del) {
  timerRestart(My_timer);

  uint64_t t = del / 25;
  while ((timerRead(My_timer)&0x3ffffff) < t);

}

void delay_nop16() {
}

void delay_ns300() {
  int64_t st = ESP.getCycleCount();
  /*
  //95
  for(int a=0; a<16; a++){
    asm("nop;");
  }
  */
  //95
  // for(int a=0; a<32; a++){
  //   asm("nop;");
  // }

  uint64_t en = ESP.getCycleCount();

  Serial.printf(" st:%d end:%d diff:%d  \n", (int)st, (int)en, (int)(en - st));
}

void delay_ns850() {
}

int th=0;
int tl=0;

void NZR_0(int pin) {
  gpio_set_level(GPIO_NUM_14, 1);  
  //digitalWrite(pin, HIGH);
  delay_ns(th);
   gpio_set_level(GPIO_NUM_14, 0);  
  //digitalWrite(pin, LOW);
  delay_ns(tl);
}

inline void NZR_1(int pin) {
  gpio_set_level(GPIO_NUM_14, 1);  
  //digitalWrite(pin, HIGH);
  delay_ns(tl);
  gpio_set_level(GPIO_NUM_14, 0);  
  //digitalWrite(pin, LOW);
  delay_ns(th);
}


inline void NZR_RST(int pin) {
  digitalWrite(pin, LOW);
  delayMicroseconds(300);
}

void NZR_RGB(int pin, uint32_t color) {
  for (int a = 0; a < 24; a++) {
    if (color & (1 << a)) {
      NZR_1(pin);
    } else {
      NZR_0(pin);
    }
  }
}

void test() {
  int pin = 14;
  for (int a = 0; a < 32; a++)
    NZR_RGB(pin, 0x000001);
  NZR_RST(pin);
  

/*   delay(10);

  for (int a = 0; a < 1; a++)
    NZR_RGB(pin, 0x00ff00);
  NZR_RST(pin);

  delay(10);

  for (int a = 0; a < 1; a++)
    NZR_RGB(pin, 0xff);
  NZR_RST(pin);

  delay(10); */
}

void setup() {
  Serial.begin(115200);

  gpio_pad_select_gpio(GPIO_NUM_14);
  gpio_set_direction(GPIO_NUM_14, GPIO_MODE_OUTPUT);   
  My_timer = timerBegin(3, 2, true);
  timerStart(My_timer);
}

int a = 0;
void loop() {

  th=a;
  tl=a*2;
  test();
  Serial.printf("cnt: %d  %d  %d\n", a++, th,tl);
  delay_ns(100000000);
}
