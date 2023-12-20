#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

#define echoPin A0
#define trigPin A1

int kiriA=9;
int kiriB=6;
int kananA=5;
int kananB=3;

unsigned int waktu;
float jarak;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(echoPin,INPUT);
pinMode(trigPin,OUTPUT);
pinMode(kiriA,OUTPUT);
pinMode(kiriB,OUTPUT);
pinMode(kananA,OUTPUT);
pinMode(kananB,OUTPUT);

lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("jarak");
}

void loop() {
  // put your main code here, to run repeatedly:
long duration, inches, cm;

digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

waktu=pulseIn(echoPin,HIGH);

jarak=(0.034*waktu)/2;

lcd.setCursor(6,0);
lcd.print(jarak);
lcd.print("CM");
delay(200);

inches=microsecondsToInches(waktu);
cm=microsecondsToCentimeters(waktu);

Serial.print(inches);
Serial.print("in,");
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(200);

if(jarak<=60)
{
  analogWrite(kiriA,255);
  analogWrite(kiriB,0);
  analogWrite(kananA,0);
  analogWrite(kananB,255);
  delay(5000);
  analogWrite(kiriA,0);
  analogWrite(kiriB,0);
  analogWrite(kananA,0);
  analogWrite(kananB,0);
  delay(5000);

}

else
{
  analogWrite(kiriA,0);
  analogWrite(kiriB,255);
  analogWrite(kananA,0);
  analogWrite(kananB,255);
  delay(5000);
  analogWrite(kiriA,0);
  analogWrite(kiriB,0);
  analogWrite(kananA,0);
  analogWrite(kananB,0);
  delay(5000);
}
}

long microsecondsToInches(long microseconds)
{
  return microseconds/74/2;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds/29/2;
}
