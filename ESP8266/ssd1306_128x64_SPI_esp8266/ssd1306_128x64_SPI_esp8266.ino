/***
Test for OLED-Display 128x64 SPI ESP8266
***/

/* Pinning
 *  Display (Pin) - ESP8266
 *  GND     (1) - GND  
 *  VCC     (2) - 3.3V
 *  D0/SCK  (3) - GPIO14
 *  D1/SDA  (4) - GPIO13
 *  RES     (5) - GPIO 4 / ESP Reset-Pin
 *  DC      (6) - GPIO 5
 *  CS      (7) - GPIO 15 / GND
 *  
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)
*/


#define OLED_RESET -1
#define OLED_DC     5
#define OLED_CS    -1


#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels

#include <Adafruit_GFX.h>    // Adafruit Grafik-Bibliothek wird benötigt
#include <Adafruit_SSD1306.h>// Adafruit SSD1306-Bibliothek wird benötigt

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

int cnt;

void setup(void) {
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
  oled.setCursor(30,6);
  oled.print("Hello World!");
  oled.fillRect(1,19,126,11,SSD1306_BLACK); 
  oled.setCursor(59,19);
  oled.print(cnt);
  oled.display();
  cnt++;
  delay(1000); 
}
