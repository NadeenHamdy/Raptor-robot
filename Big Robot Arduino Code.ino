#include <Servo.h>

//Servo 
#define ServoPin1 10
#define ServoPin2 11
#define ServoPin3 12
#define ServoPin4 13

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos1 = 10;
int pos2 = 10;
int pos3 = 10;
int pos4 = 10;

//Drivers
#define D1INP1 2
#define D1INP2 3
#define D1INP3 4
#define D1INP4 5
#define D2INP1 6
#define D2INP2 7
#define D2INP3 8
#define D2INP4 9
int Speed = 255;

//Bluetooth Module
char commands;

void setup() {
  //Drivers
  pinMode(D1INP1, OUTPUT);
  pinMode(D1INP2, OUTPUT);
  pinMode(D1INP3, OUTPUT);
  pinMode(D1INP4, OUTPUT);
  pinMode(D2INP1, OUTPUT);
  pinMode(D2INP2, OUTPUT);
  pinMode(D2INP3, OUTPUT);
  pinMode(D2INP4, OUTPUT);

  //Bluetooth Module
  Serial.begin(9600);

  //Servo
  myservo1.attach(ServoPin1);
  myservo2.attach(ServoPin2);
  myservo3.attach(ServoPin3);
  myservo4.attach(ServoPin4);

  myservo1.write(10);
  delay(200);
  myservo2.write(10);
  delay(200);
  myservo3.write(10);
  delay(200);
  myservo4.write(10);
  delay(200);
}

void loop() {
  if(Serial.available()){
    commands = Serial.read();
    //Directions
    if(commands == 'F'){
      Forward();
      }
      else if(commands == 'B'){
      Backward();
      }
      else if(commands == 'R'){
      TurnRight();
      }
      else if(commands == 'L'){
      TurnLeft();
      }
      else if(commands == 'S'){
      Stop();
      }
      else{
        Servos();
        }
    } //the end of the first if (Serial.available)
}

void Forward(){
  analogWrite(D1INP1, Speed);
  analogWrite(D1INP2, 0);
  analogWrite(D1INP3, Speed);
  analogWrite(D1INP4, 0);
  analogWrite(D2INP1, Speed);
  analogWrite(D2INP2, 0);
  analogWrite(D2INP3, Speed);
  analogWrite(D2INP4, 0);
  }

void Backward(){
  analogWrite(D1INP1, 0);
  analogWrite(D1INP2, Speed);
  analogWrite(D1INP3, 0);
  analogWrite(D1INP4, Speed);
  analogWrite(D2INP1, 0);
  analogWrite(D2INP2, Speed);
  analogWrite(D2INP3, 0);
  analogWrite(D2INP4, Speed);
    }

void TurnRight(){
  analogWrite(D1INP1, Speed);
  analogWrite(D1INP2, 0);
  analogWrite(D1INP3, 0);
  analogWrite(D1INP4, Speed);
  analogWrite(D2INP1, 0);
  analogWrite(D2INP2, Speed);
  analogWrite(D2INP3, Speed);
  analogWrite(D2INP4, 0);
      }

void TurnLeft(){
  analogWrite(D1INP1, 0);
  analogWrite(D1INP2, Speed);
  analogWrite(D1INP3, Speed);
  analogWrite(D1INP4, 0);
  analogWrite(D2INP1, Speed);
  analogWrite(D2INP2, 0);
  analogWrite(D2INP3, 0);
  analogWrite(D2INP4, Speed);
        }

void Stop(){
  analogWrite(D1INP1, 0);
  analogWrite(D1INP2, 0);
  analogWrite(D1INP3, 0);
  analogWrite(D1INP4, 0);
  analogWrite(D2INP1, 0);
  analogWrite(D2INP2, 0);
  analogWrite(D2INP3, 0);
  analogWrite(D2INP4, 0);
  }

void Servos(){
      //Servo1
      if(commands == 'Q'){
      pos1 = pos1 + 5;
      if(pos1 > 170){
      pos1 = 170;
      }
      myservo1.write(pos1);
      commands = 'S';
      delay(200);
      }

      else if(commands == 'W'){
      pos1 = pos1 - 5;
      if(pos1 <= 10){
      pos1 = 10;
      }
      myservo1.write(pos1);
      commands = 'S';
      delay(200);
      }
      
//servo 2
      else if(commands == 'E')
      {
      pos2 = pos2 + 5;
      if(pos2 >= 170){
      pos2 = 170;
      }
      myservo2.write(pos2);
      commands = 'S';
      delay(200);
      }

     else if(commands == 'G')
      {
      pos2 = pos2 - 5;
      if(pos2 >= 10){
      pos2 = 10;
      }
      myservo2.write(pos2);
      commands = 'S';
      delay(200);
      }
      
//servo 3
      else if(commands == 'T'){
      pos3 = pos3 + 5;
      if(pos3 >= 170){
      pos3 = 170;
      }
      myservo3.write(pos3);
      commands = 'S';
      delay(200);
      }

      else if(commands == 'Y'){
      pos3 = pos3 - 5;
      if(pos3 <= 10){
      pos3 = 10;
      }
      myservo3.write(pos3);
      commands = 'S';
      delay(200);
      }

//servo 4
      else if(commands == 'U'){
      pos4 = pos4 + 5;
      if(pos4 >= 170){
      pos4 = 170;
      }
      myservo4.write(pos4);
      commands = 'S';
      delay(200);
      }

      else if(commands == 'I'){
      pos4 = pos4 - 5;
      if(pos4 <= 10){
      pos4 = 10;
      }
      myservo4.write(pos4);
      commands = 'S';
      delay(200);
      }
  }
