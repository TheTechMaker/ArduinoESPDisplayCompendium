/***
Test für das 1,3 Zoll SPI 240x240 OLED-Display Arduino
***/

/* Pinning
 *  !!! level shifter is required, display works ONLY with 3.3V !!!
 *                  
 *  Arduino Pin  --/\/\/\---- Display Pin 
 *                   1k   |  
 *                        >
 *                        < 2k2
 *                        >
 *                        |  
 *                       -–-
 *  
 *  Display (Pin) - Arduino
 *  GND  (1) - GND  
 *  VCC  (2) - 3.3V
 *  SCK  (3) - D13
 *  SDA  (4) - D11
 *  RES  (5) - D10
 *  DC   (6) - D9
 *  BLK  (7) - 3.3V // or not connected, back light turns off when connected to GND
 *  
// SCK (CLK) ---> Adruino pin D13
// MOSI(DIN) ---> Arduino pin D11
*/


#define TFT_DC    9    // TFT DC  pin is connected to NodeMCU pin D1 (GPIO5)
#define TFT_RST   10   // TFT RST pin is connected to NodeMCU pin D2 (GPIO4)
#define TFT_CS    -1    // 
  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int cnt;

void setup() {
    tft.init(240, 240, SPI_MODE2);
    tft.setRotation(1);
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(3);
 }

void loop() {
  tft.setCursor(12,30);
  tft.print("Hello World!");
   // fill text area black before printing new value
  tft.fillRect(110,60,130,21,ST77XX_BLACK);
  tft.setCursor(110,60);
  tft.print(cnt);
  cnt++;
  delay(1000); 
}
