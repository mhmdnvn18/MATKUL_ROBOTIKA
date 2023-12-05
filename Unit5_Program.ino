#include <LiquidCrystal_I2C.h>

const int trigPin = 9;    // Pin trigger sensor HC-SR04
const int echoPin = 10;   // Pin echo sensor HC-SR04
const int motorPin1 = 5;  // Pin motor DC 1
const int motorPin2 = 6;  // Pin motor DC 2
const int pwmPin = 3;     // Pin PWM motor DC

LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C dan ukuran LCD LM015L

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);

  lcd.begin(16, 2); // Inisialisasi LCD
  lcd.print("Distance: ");
}

void loop() 
{
  // Baca jarak dari sensor HC-SR04
  float distance = getDistance();
  // Tampilkan jarak di LCD
  lcd.setCursor(0, 1);
  lcd.print("            "); // Hapus teks sebelumnya
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  // Kontrol motor DC berdasarkan jarak
  controlMotor(distance);
  delay(500);
}

float getDistance() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

void controlMotor(float distance) 
{
  int motorSpeed = map(distance, 5, 20, 255, 0); // Map jarak ke kecepatan motor
  motorSpeed = constrain(motorSpeed, 0, 255); // Batasi kecepatan antara 0 dan 255
  analogWrite(pwmPin, motorSpeed);

  if (distance < 10) 
  {
    // Belok ke kiri jika jarak kurang dari 10 cm
    analogWrite(motorPin1, 50);
    analogWrite(motorPin2, 0);
    lcd.setCursor(0, 0);
    lcd.print("Turn Left      ");
  } 
  else if (distance > 20) 
  {
    // Belok ke kanan jika jarak lebih dari 20 cm
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 50);
    lcd.setCursor(0, 0);
    lcd.print("Turn Right     ");
  } 
  else if (distance < 5) 
  {
      // Berhenti jika jarak kurang dari 5 cm
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    lcd.setCursor(0, 0);
    lcd.print("STOP    ");
  } 
  else 
  {
     // Jalan lurus jika jarak antara 10 cm dan 20 cm
    analogWrite(motorPin1, 50);
    analogWrite(motorPin2, 50);
    lcd.setCursor(0, 0);
    lcd.print("Go Straight    ");
  }
}

