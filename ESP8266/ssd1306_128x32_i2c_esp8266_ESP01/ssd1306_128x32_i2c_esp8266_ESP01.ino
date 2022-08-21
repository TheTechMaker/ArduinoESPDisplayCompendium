/***
Test for OLED-Display 128x32 with ESP8266
***/

/* Pinning
 *  Display (Pin) - Arduino
 *  GND  (1) - GND  
 *  VCC  (2) - VCC
 *  SCL  (3) - GPIO00
 *  SDA  (4) - GPIO02
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128	// OLED display width, in pixels
#define SCREEN_HEIGHT 32	// OLED display height, in pixels
#define OLED_RESET    -1	// Reset pin # (-1 if sharing Arduino reset pin or display has no reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int cnt;

void setup() {

	// change I2C default pins to GPIO2 (SDA) and GPIO0 (SCL)
    Wire.begin(2, 0);

   
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); // Don't proceed, loop forever
  }

  oled.clearDisplay();
  oled.setRotation(2);
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
