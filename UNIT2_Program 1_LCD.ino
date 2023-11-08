#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  lcd.init();
}

void loop() 
{
  lcd.backlight();
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("PRAKTIKUM");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("LCD I2C Module");
  delay(8000);
  lcd.clear();
  delay(8000);
  lcd.noBacklight();
}
