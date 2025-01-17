#include <Wire.h>
#include<LiquidCrystal_I2C.h>
const int SW1 = 12;
const int SW2 = 13;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  lcd.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Tombol");

  if(digitalRead(SW1)==HIGH)
  {
    lcd.setCursor(0,1);
    lcd.print("tombol 1");
    delay(500);
    lcd.clear();
    lcd.scrollDisplayLeft();
    delay(200);
  }

  if(digitalRead(SW2)==HIGH)
  {
    lcd.setCursor(0,1);
    lcd.print("tombol 2");
    delay(500);
    lcd.clear();
    lcd.scrollDisplayLeft();
    delay(200);
  }
}
