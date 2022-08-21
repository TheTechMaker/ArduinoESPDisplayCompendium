/***
Test für das 1,77 Zoll SPI TFT-Display ESP32 - Wemos D1 R32
***/

/* Pinning
 *  Display (Pin) - Wemos D1 R32
 *  GND  (1) - GND  
 *  VCC  (2) - 3.3V
 *  SCK  (3) - GPIO18
 *  SDA  (4) - GPIO23
 *  RES  (5) - ESP Reset-Pin
 *  RS   (6) - GPIO 5
 *  CS   (7) -  GND
 *  LEDA (8) - 3.3V
 *  
 *  LEDA kann auch an 5V doch dann wird das Display sehr schnell sehr heiß - was ich nicht für optimal halte.
 *  Beim Betrieb mit 3.3V ist das Display nur minimal dunkler und bleibt kalt.
// SCK (CLK) ---> D1 R32 GPIO18
// MOSI(DIN) ---> D1 R32 GPIO23
*/


#define TFT_PIN_CS   -1  // connect to GND  
#define TFT_PIN_DC    5  // GPIO 5 / D1 
#define TFT_PIN_RST  33  // ESP Reset-Pin will work but it's better to use a GPIO pin 

#include <Adafruit_GFX.h>    // Adafruit Grafik-Bibliothek wird benötigt
#include <Adafruit_ST7735.h> // Adafruit ST7735-Bibliothek wird benötigt

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_PIN_CS, TFT_PIN_DC, TFT_PIN_RST);

int cnt;

void setup(void) {
  /* ST7735-Chip initialisieren (INITR_BLACKTAB / INITR_REDTAB / INITR_GREENTAB) */
  tft.initR(INITR_BLACKTAB);   
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(2);
}

void loop() {
  tft.setCursor(12,30);
  tft.print("Hello World!");
  // fill text area black before printing new value
  tft.fillRect(75,52,85,14,ST7735_BLACK);
  tft.setCursor(75,52);
  tft.print(cnt);
  cnt++;
  delay(1000); 
}
