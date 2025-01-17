// Lampu LED Berjalan Menggunakan Wemos D1 R1 UNO
// Menyalakan LED dengan Aktif HIGH

void setup() {
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);

  // menjadikan PIN 4 dan 3 sebagai OUTPUT
}

void loop() {
  // menyala secara bergilir
  digitalWrite(D4, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
  delay(1000);
  
  digitalWrite(D4, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D3, LOW);
  delay(1000);

  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D3, HIGH);
  delay(1000);
}