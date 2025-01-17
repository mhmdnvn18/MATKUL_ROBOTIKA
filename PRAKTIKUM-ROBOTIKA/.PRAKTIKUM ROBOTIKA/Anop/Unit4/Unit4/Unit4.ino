#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);
#define echoPin 10
#define trigPin 9
unsigned int waktu;
float jarak;

void setup() 
{
  pinMode(echoPin, INPUT);//PIN 10
  pinMode(trigPin, OUTPUT);//PIN 9
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("ukur jarak");
  delay(200);
  lcd.setCursor(3,0);
  lcd.print("HC SR40");
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("jarak");
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  waktu = pulseIn(echoPin, HIGH);
  jarak = (0.034*waktu)/2;
  lcd.setCursor(6,1);
  lcd.print(jarak);
  lcd.print(" CM ");
  delay(200);
}
