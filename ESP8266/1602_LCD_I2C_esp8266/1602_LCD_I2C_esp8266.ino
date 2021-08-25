/***
Test for LCD-Display 1602 with ESP8266
***/

/* Pinning
 *  Display (Pin) - Arduino
 *  GND  (1) - GND  
 *  VCC  (2) - VCC
 *  SDA  (3) - GPIO04
 *  SCL  (4) - GPIO05
 */

#include <Wire.h>
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

byte borderLeftTop[8] = {
	0b11111,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000
};

byte borderRightTop[8] = {
	0b11111,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001
};

byte borderLeftBottom[8] = {
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b11111
};

byte borderRightBottom[8] = {
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b11111
};

byte borderLeft[8] = {
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000
};

byte borderRight[8] = {
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001
};

byte borderTop[8] = {
	0b11111,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

byte borderBottom[8] = {
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
	//Define the LCD as 16 column by 2 rows
	lcd.begin (16,2);
 	lcd.createChar(0, borderLeftTop);
 	lcd.createChar(1, borderTop);
	lcd.createChar(2, borderBottom);
	lcd.createChar(3, borderRightTop);    

	lcd.createChar(4, borderLeftBottom);	  
	lcd.createChar(5, borderRightBottom);    

    lcd.createChar(6, borderLeft);      
    lcd.createChar(7, borderRight);    



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
    lcd.setCursor(0,0);
    lcd.write(byte(6));
    lcd.setCursor(0,1);
    lcd.write(byte(6));

    lcd.setCursor(15,0);
    lcd.write(byte(7));
    lcd.setCursor(15,1);
    lcd.write(byte(7));

    
	lcd.setCursor(2,0);
	lcd.print("Hello World!");
	lcd.setCursor(7,1);	
	lcd.print(cnt);
	cnt++;
	delay(1000);
}
