#include <AFMotor.h>
//defining pins and variables
#define sensor1 A0
#define sensor2 A1
AF_DCMotor motor1(3);
AF_DCMotor motor2(3);
AF_DCMotor motor3(4);
AF_DCMotor motor4(4);

void setup() {
  //Setting the motor speed
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  //Declaring PIN input types
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  //Begin serial communication
  Serial.begin(9600);
}
void loop(){
  //Printing values of the sensors to the serial monitor
  Serial.println(analogRead(sensor1));
  Serial.println(analogRead(sensor2));
  //light detected by both
  if(analogRead(sensor1)<=350 && analogRead(sensor2)<=350){
    //Forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  //light detected by left sensor
  else if(analogRead(sensor1)<=350 && !analogRead(sensor2)<=350){
    //turn left
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);   
  }
  //light detected by right sensor
  else if(!analogRead(sensor1)<=350 && analogRead(sensor2)<=350){
    //turn right
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  //light detected by none
  else if(!analogRead(sensor1)<=350 && !analogRead(sensor2)<=350){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
}