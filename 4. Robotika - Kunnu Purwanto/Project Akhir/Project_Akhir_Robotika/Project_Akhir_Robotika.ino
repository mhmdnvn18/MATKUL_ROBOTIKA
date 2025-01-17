// Mendefinisikan Pin 
#define sensor1 4
#define sensor2 5
#define sensor3 6
#define kanan1 3
#define kanan2 7
#define kiri1 8
#define kiri2 9
#define PWM1 10
#define PWM2 11

// Membuat Penyimpanan data
bool bacaan1;
bool bacaan2;
bool bacaan3;
int posisi = 3;
float P, I, D;
float Kp = 100;
float Ki = 0;
float Kd = 0;
int error;
const int setPoint = 3;
int sum_error = 0;
int last_error = 0;


void setup() {
  // Mendifinisikan Mode Pin
  Serial.begin(9600);
  
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(kanan1, OUTPUT);
  pinMode(kanan2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(kiri1, OUTPUT);
  pinMode(kiri2, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void loop() {
  // Membaca Sensor
  bacaan1 = digitalRead(sensor1);
  bacaan2 = digitalRead(sensor2);
  bacaan3 = digitalRead(sensor3);

  // Membaca posisi robot terhadap garis
  if (bacaan2 == HIGH && bacaan1 == LOW && bacaan3 == LOW || (bacaan1 == HIGH && bacaan2 == HIGH && bacaan3 == HIGH)) {
    posisi = 3;
  }else if (bacaan1 == HIGH && bacaan2 == HIGH && bacaan3 == LOW) {
    posisi = 2;
  }else if (bacaan1 == HIGH && bacaan2 == LOW && bacaan3 == LOW) {
    posisi = 1;
  }else if (bacaan3 == HIGH && bacaan2 == HIGH && bacaan1 == LOW) {
    posisi = 4;
  }else if (bacaan3 == HIGH && bacaan2 == LOW && bacaan1 == LOW) {
    posisi = 5;
  }

  // Menghitung Nilai Error 
  error = setPoint - posisi;
  sum_error = sum_error + error;

  // Melakukan Perhitungan PID
  P = Kp * error;
  I = Ki * sum_error;
  D = Kd * (error - last_error);
  float kecepatan =  P + I + D;
  last_error = error;

  // Mengubah Nilai PWM Normal
  int PWMMotor1 = 100 - kecepatan;
  int PWMMotor2 = 100 + kecepatan;

  PWMMotor1 = constrain(PWMMotor1, 0, 255);
  PWMMotor2 = constrain(PWMMotor2, 0, 255);

  digitalWrite(kanan1, HIGH);
  digitalWrite(kanan2, LOW);
  analogWrite(PWM1, PWMMotor1);

  digitalWrite(kiri1, HIGH);
  digitalWrite(kiri2, LOW);
  analogWrite(PWM2, PWMMotor2);

  //Tampilkan hasil bacaan      
  Serial.print(bacaan1);
  Serial.print(bacaan2);
  Serial.print(bacaan3);
  Serial.print(posisi);
  Serial.print(PWMMotor1);
  Serial.println(PWMMotor2);
}