#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("LCD I2C Module ");  // Teks awal
}

void loop() {
  for (int i = 0; i < 12; i++) {  // Bergeser sebanyak 12 karakter
    lcd.scrollDisplayLeft();
    delay(300);  // Jeda antara pergeseran
  }
  lcd.clear();  // Bersihkan layar setelah pergeseran selesai
}
