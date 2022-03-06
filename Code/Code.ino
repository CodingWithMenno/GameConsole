#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Test.h"

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);

  lcd.init();

  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
}

void loop() 
{
  turnOn();
  delay(100);  
  turnOff();
  delay(100);   

//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print("Oke!");
}
