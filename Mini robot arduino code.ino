//#include <Servo.h>

//Ultrasonic
#define trigPin1  2
#define echoPin1  8
#define trigPin2  7
#define echoPin2  4

long duration1, distance1;

long duration2, distance2;


//Servo
//Servo myservo;
//#define ServoPin 6

//Driver
#define DriverINP1 11
#define DriverINP2 5
#define DriverINP3 9
#define DriverINP4 10

//IR
#define IR 13

char commands;

int a;

void setup() {
  //servo
  //myservo.attach(ServoPin);
  //  pinMode(ServoPin ,OUTPUT);

  //IR
  pinMode(IR, INPUT);

  //Driver
  pinMode(DriverINP1, OUTPUT);
  pinMode(DriverINP2, OUTPUT);
  pinMode(DriverINP3, OUTPUT);
  pinMode(DriverINP4, OUTPUT);

  //Ultrasonic
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  //Bluetooth
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    commands = Serial.read();
    if (commands == 'F') {a = 130;
      Forward();
    }
    else if (commands == 'B') {a = 130;
      Backward();
    }
    else if (commands == 'R') {a = 130;
      TurnRight();
    }
    else if (commands == 'L') {a = 130;
      TurnLeft();
    }
    else if (commands == 'S') {
      Stop();
    }

    //----------------------------------------
    //else if(commands == 'C' ) {
    //for(int i = 5; i < 45; i = i + 5){
    //myservo.write(i);
    //delay(100);
    //}
    //}
    //else if(commands == 'V' ) {
    //for(int i = 45; i > 0; i =i - 5){
    //myservo.write(i);
    //delay(100);
    //}
    //}
    //------------------------------------------
    else if (commands = 'A') {
      y();
      x();
      a = 60;
      if (distance1 < 13) {
        TurnRight();
      }
      else if (distance2 < 13) {
        TurnLeft();
      }
      else { 
        Forward();
      }
      if (digitalRead(IR) == HIGH) {
        Stop();
        commands = 'S';
      }
    }
  }
}
//------------------------------------------------
void Forward()  {
  analogWrite(DriverINP1, a);
  analogWrite(DriverINP2, 0);
  analogWrite(DriverINP3, a);
  analogWrite(DriverINP4, 0);
}

void Backward() {
  analogWrite(DriverINP1, 0);
  analogWrite(DriverINP2, a);
  analogWrite(DriverINP3, 0);
  analogWrite(DriverINP4, a);
}

void TurnRight() {
  analogWrite(DriverINP1, 0);
  analogWrite(DriverINP2, a);
  analogWrite(DriverINP3, a);
  analogWrite(DriverINP4, 0);
}

void TurnLeft() {
  analogWrite(DriverINP1, a);
  analogWrite(DriverINP2, 0);
  analogWrite(DriverINP3, 0);
  analogWrite(DriverINP4, a);
}

void Stop() {
  analogWrite(DriverINP1, 0);
  analogWrite(DriverINP2, 0);
  analogWrite(DriverINP3, 0);
  analogWrite(DriverINP4, 0);
}
//------------------------------------------------
//Ultrasonic
int x () {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) * 0.034029; // 340.29 * (100/1000000) = 340.29/10000
}
int y () {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) * 0.034029; // 340.29 * (100/1000000) = 340.29/10000
}

