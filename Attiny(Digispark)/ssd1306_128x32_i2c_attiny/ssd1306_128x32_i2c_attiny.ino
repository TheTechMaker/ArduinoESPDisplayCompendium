/***
Test for OLED-Display 128x32 with Attiny85
***/

/* Pinning
 *  Display (Pin) - Attiny85
 *  GND  (1) - GND (Hardwarepin 4)  
 *  VCC  (2) - VCC (Hardwarepin 8)
 *  SCL  (3) - PB2 (Hardwarepin 7)
 *  SDA  (4) - PB0 (Hardwarepin 5)
*/

#include <TinyWireM.h>
#include <Tiny4kOLED.h>

uint8_t width = 128;
uint8_t height = 32;

int cnt;

void setup() {
	oled.begin(width, height, sizeof(tiny4koled_init_128x32br), tiny4koled_init_128x32br);
	oled.setFont(FONT6X8);
  	drawScreen(); 
	oled.on();
}

void loop() {
	oled.setCursor(30, 1);
  	oled.print(F("Hello World!"));  //wrap strings in F() to save RAM!
	oled.setCursor(60,2);
	oled.print(cnt);
	oled.on();	
	cnt++;
	delay(1000);
}

// this function is copied from Tiny4kOLED library, examples/Devices/128x32 128x32.ino 
void drawScreen() {
  for (uint8_t y = 0; y < 8; y++) {
    oled.setCursor(0, y);
    oled.startData();
    for (uint8_t x=0; x<128; x += 2) {
      oled.sendData(0b10101010);
      oled.sendData(0b01010101);
    }
    oled.endData();
  }

  oled.setCursor(0, 0);
  oled.startData();
  oled.sendData(0b11111111);
  oled.repeatData(0b00000001, width - 2);
  oled.sendData(0b11111111);
  oled.endData();

  for (uint8_t y = 1; y < (height - 8) / 8; y++) {
    oled.setCursor(0, y);
    oled.startData();
    oled.sendData(0b11111111);
    oled.repeatData(0b00000000, width - 2);
    oled.sendData(0b11111111);
    oled.endData();
  }

  oled.setCursor(0, (height - 8) / 8);
  oled.startData();
  oled.sendData(0b11111111);
  oled.repeatData(0b10000000, width - 2);
  oled.sendData(0b11111111);
  oled.endData();
}
