/***
Test für das 1,77 Zoll SPI TFT-Display Arduino
***/

/* Pinnung
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
 *  VCC  (2) - 5V
 *  SCK  (3) - D13
 *  SDA  (4) - D11
 *  RES  (5) - Arduino Reset-Pin
 *  RS   (6) - D8
 *  CS   (7) - GND
 *  LEDA (8) - 3.3V
 *  
 *  LEDA kann auch an 5V doch dann wird das Display sehr schnell sehr heiß - was ich nicht für optimal halte.
 *  Beim Betrieb mit 3.3V ist das Display nur minimal dunkler und bleibt kalt.
// SCK (CLK) ---> Adruino pin D13
// MOSI(DIN) ---> Arduino pin D11
*/

#define TFT_PIN_CS   -1  // connect to GND  
#define TFT_PIN_DC    8  //  
#define TFT_PIN_RST  -1  // Arduino Reset-Pin

#include <SPI.h>             // SPI für die Kommunikation
#include <Adafruit_GFX.h>    // Adafruit Grafik-Bibliothek wird benötigt
#include <Adafruit_ST7735.h> // Adafruit ST7735-Bibliothek wird benötigt

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_PIN_CS, TFT_PIN_DC, TFT_PIN_RST);  // ST7735-Bibliothek Setup

int cnt;

void setup(void) {
  /* ST7735-Chip initialisieren (INITR_BLACKTAB / INITR_REDTAB / INITR_GREENTAB) */
  tft.initR(INITR_BLACKTAB);   
  tft.setRotation(1);
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
  delay(2000); 
}
