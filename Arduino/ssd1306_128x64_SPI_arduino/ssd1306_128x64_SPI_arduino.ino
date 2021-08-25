/***
Test for OLED-Display 128x64 SPI Arduino
***/

/* Pinning
 *  Display (Pin) - Arduino
 *  GND     (1) - GND  
 *  VCC     (2) - VCC
 *  D0/SCK  (3) - D13
 *  D1/SDA  (4) - D11
 *  RES     (5) - D8 / Arduino Reset-Pin
 *  DC      (6) - D7
 *  CS      (7) - D6
*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128	// OLED display width, in pixels
#define SCREEN_HEIGHT 64	// OLED display height, in pixels

#define OLED_RESET -1
#define OLED_DC    7
#define OLED_CS    6

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

int cnt;

void setup() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!oled.begin(SSD1306_SWITCHCAPVCC)) { 
    for(;;); // Don't proceed, loop forever
  }

  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
  oled.display();
}

void loop() {

    /*
    oled.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,SSD1306_WHITE);
    oled.display();   
    */
  oled.setCursor(30,6);
  oled.print("Hello World!");
  oled.fillRect(1,19,126,11,SSD1306_BLACK); 
  oled.setCursor(59,19);
  oled.print(cnt);
  oled.display();
  cnt++;
  delay(1000); 
}
