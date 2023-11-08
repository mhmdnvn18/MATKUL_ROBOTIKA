#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  delay(2000);
  lcd.print(" LCD I2C Module ");
  lcd.setCursor(0, 1);
  lcd.print("PRAKTIKUM");
  delay(8000);
  lcd.clear();
  delay(2000);
  lcd.noBacklight();
  delay(8000);
  lcd.backlight();
}
