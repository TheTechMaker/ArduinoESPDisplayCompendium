/***
Test for LCD-Display 1602 with Attiny85
***/

/* Pinning
 *  Display (Pin) - Attiny85
 *  GND  (1) - GND (Hardwarepin 4)  
 *  VCC  (2) - VCC (Hardwarepin 8)
 *  SDA  (3) - PB0 (Hardwarepin 5)
 *  SCL  (4) - PB2 (Hardwarepin 7)
*/

#include <TinyWireM.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR          0x27
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

byte zeroLeftTop[8] = {
  0b11111,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};

byte zeroRightTop[8] = {
  0b11111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};

byte zeroLeftBottom[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b11111
};

byte zeroRightBottom[8] = {
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b11111
};


byte zeroRight[8] = {
  0b11111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b11111
};

byte top[8] = {
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte bottom[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111
};

int cnt = 0;

void setup() {
	// initialize I2C lib
    TinyWireM.begin(); 

    //Define the LCD as 20 column by 4 rows
  lcd.begin (16,2);
 	lcd.createChar(0, zeroLeftTop);
 	lcd.createChar(1, top);
  lcd.createChar(2, bottom);
	lcd.createChar(3, zeroRightTop);    

  lcd.createChar(4, zeroLeftBottom);    
  lcd.createChar(5, zeroRightBottom);    



  //Switch on backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);

	lcd.setCursor(0,0);
	lcd.write(byte(0));
	lcd.setCursor(15,0);
	lcd.write(byte(3));

	lcd.setCursor(0,1);
 	lcd.write(byte(4));
	lcd.setCursor(15,1);
	lcd.write(byte(5));

	for(int i=1; i<=14; i++) {
		lcd.setCursor(i,0);
		lcd.write(byte(1));
		lcd.setCursor(i,1);
		lcd.write(byte(2));
	}
	
	delay(2000);
	lcd.setCursor(0,0);
	lcd.print("                ");
	lcd.setCursor(0,1);
	lcd.print("                ");
}


void loop(){
	lcd.setCursor(2,0);
	lcd.print("Hello World!");
	lcd.setCursor(7,1);	
	lcd.print(cnt);
  cnt++;
	delay(1000);
}
