/***
Test für das 1,77 Zoll SPI TFT-Display ESP8266
***/

/* Pinning
 *  Display (Pin) - ESP8266
 *  GND  (1) - GND  
 *  VCC  (2) - 3.3V
 *  SCK  (3) - GPIO14
 *  SDA  (4) - GPIO13
 *  RES  (5) - ESP Reset-Pin
 *  RS   (6) - GPIO 5
 *  CS   (7) -  GND
 *  LEDA (8) - 3.3V
 *  
 *  LEDA kann auch an 5V doch dann wird das Display sehr schnell sehr heiß - was ich nicht für optimal halte.
 *  Beim Betrieb mit 3.3V ist das Display nur minimal dunkler und bleibt kalt.
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)
*/


#define TFT_PIN_CS   -1  // connect to GND  
#define TFT_PIN_DC    5  // GPIO 5 / D1 
#define TFT_PIN_RST  -1  // ESP Reset-Pin

#include <Adafruit_GFX.h>    // Adafruit Grafik-Bibliothek wird benötigt
#include <Adafruit_ST7735.h> // Adafruit ST7735-Bibliothek wird benötigt

#include <myFonts/OpenSans_Regular6pt7b.h>


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_PIN_CS, TFT_PIN_DC, TFT_PIN_RST);

int cnt = 0;
String testText = "Das ist mein scrollender - Text Das ist mein scrollender";

int16_t  xText = 150;

unsigned long waitTime_1 = 0;
#define INTERVAL_1 200

unsigned long waitTime_2 = 0;
#define INTERVAL_2 1000


void setup(void) {
  /* ST7735-Chip initialisieren (INITR_BLACKTAB / INITR_REDTAB / INITR_GREENTAB) */
  tft.initR(INITR_BLACKTAB);   
  tft.setRotation(1);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE);
  tft.setFont(&OpenSans_Regular6pt7b);
  tft.setTextWrap(false); 
  tft.setTextSize(1);
}

void loop() {

    if(millis() >= waitTime_2 + INTERVAL_2){
        waitTime_2 += INTERVAL_2;8

        tft.setTextColor(ST7735_WHITE);
        //  tft.fillRect(0,22,160,12,ST7735_BLUE);
        tft.setCursor(12,30);
        tft.print("Hello World! - All is good.");
        // fill text area black before printing new value
        tft.fillRect(75,44,85,12,ST7735_BLUE);
        tft.setCursor(75,52);
        tft.print(cnt);
        tft.print(" |g");
        cnt++;
    }



    if(millis() >= waitTime_1 + INTERVAL_1){
        waitTime_1 += INTERVAL_1;


    

  
  tft.setTextColor(ST7735_YELLOW);
  tft.fillRect(0,82,160,12,ST7735_BLACK);
  tft.setCursor(xText,90);
  tft.print(testText);

int16_t  x1;
int16_t  y1;
uint16_t w, h;
    tft.getTextBounds(testText, xText, 90, &x1, &y1, &w, &h);

    xText -= 5; 

    if(xText <= -w) { xText = 155; }

    }


/* 
  tft.setTextColor(ST7735_YELLOW);
  tft.fillRect(0,102,160,12,ST7735_BLACK);
  tft.setCursor(0,110);
  tft.print(x1);
  tft.print(" ");
  tft.print(y1);
  tft.print(" ");
  tft.print(w);
  tft.print(" ");
  tft.print(h);
*/




}
