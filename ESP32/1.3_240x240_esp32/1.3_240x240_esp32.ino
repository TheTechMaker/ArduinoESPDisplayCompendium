/***
Test für das 1,3 Zoll SPI 240x240 OLED-Display ESP32
***/

/* Pinning
 *  Display (Pin) - ESP32
 *  GND  (1) - GND  
 *  VCC  (2) - 3.3V
 *  SCK  (3) - GPIO18
 *  SDA  (4) - GPIO23
 *  RES  (5) - GPIO 4
 *  DC   (6) - GPIO 2
 *  BLK  (7) - 3.3V // or not connected, back light turns off when connected to GND
 *  
*/


#define TFT_RST   4     // TFT RST GPIO4
#define TFT_DC    2     // TFT DC  GPIO2
#define TFT_CS    -1    // display has no CS 
  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int cnt;

void setup() {
    tft.init(240, 240, SPI_MODE2);
    tft.setRotation(1);
    tft.fillScreen(ST77XX_BLACK);
    tft.drawRect(0, 0, 240, 240, ST77XX_WHITE);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(3);
 }

void loop() {
  tft.setCursor(16,30);
  tft.print("Hello World!");
   // fill text area black before printing new value
  tft.fillRect(1,60,238,25,ST77XX_BLACK);
  tft.setCursor(110,62);
  tft.print(cnt);
  cnt++;
  delay(1000); 
}
