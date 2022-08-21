/***
Test for OLED-Display 128x64 with Arduino
***/

/* Pinning
 *  Display (Pin) - Arduino
 *  GND  (1) - GND  
 *  VCC  (2) - VCC
 *  SCL  (3) - A5
 *  SDA  (4) - A4
*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128	// OLED display width, in pixels
#define SCREEN_HEIGHT 64	// OLED display height, in pixels
#define OLED_RESET    -1	// Reset pin # (-1 if sharing Arduino reset pin or display has no reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int cnt;

void setup() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
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
  oled.fillRect(60,19,67 ,11,SSD1306_BLACK); 
  oled.setCursor(60,19);
  oled.print(cnt);
  oled.display();
  cnt++;
  delay(1000); 
}
