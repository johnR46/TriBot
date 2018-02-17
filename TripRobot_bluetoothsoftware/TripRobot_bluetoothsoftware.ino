#include <SoftwareSerial.h>
SoftwareSerial BT(11, 12); //Rx,Tx
int Rxapp = 0; // value start
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  BT.begin(38400);

}



void SpinLeft(int pwm) {
  digitalWrite(2, 1);
  digitalWrite(4, 0);

  digitalWrite(5, 1);
  digitalWrite(7, 0);

  digitalWrite(8, 0);
  digitalWrite(10, 1);
  analogWrite(3, pwm);
  analogWrite(6, pwm);
  analogWrite(9, pwm);
}

void SpinRight(int pwm) {
  digitalWrite(2, 0);
  digitalWrite(4, 1);

  digitalWrite(5, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(10, 0);
  analogWrite(3, pwm);
  analogWrite(6, pwm);
  analogWrite(9, pwm);
}


void right(int pwm) {
  digitalWrite(2, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(10, 1);
  analogWrite(3, pwm);
  analogWrite(6, 0);
  analogWrite(9, pwm);
}

void left(int pwm) {
  digitalWrite(2, 0);
  digitalWrite(4, 0);

  digitalWrite(5, 1);
  digitalWrite(7, 0);

  digitalWrite(8, 1);
  digitalWrite(10, 0);
  analogWrite(3, 0);
  analogWrite(6, pwm);
  analogWrite(9, pwm);
}


void forward(int pwm) {
  digitalWrite(2, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(10, 0);
  analogWrite(3, pwm);
  analogWrite(6, pwm);
  analogWrite(9, 0);
}

void backward(int pwm) {
  digitalWrite(2, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(10, 0);
  analogWrite(3, pwm);
  analogWrite(6, pwm);
  analogWrite(9, 0);
}

void stopMortor() {
  digitalWrite(2, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(10, 0);
  analogWrite(3, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
}


void loop() {
  if (BT.available()) {
    Rxapp = BT.read();
  }
  if (Rxapp == 49) {
    forward(1023);
  }
  else if (Rxapp == 50) {
    backward(1023);
  } else if (Rxapp == 52) {
    SpinLeft(1023);
  }
  else if (Rxapp == 51) {
    SpinRight(1023);
  }
  else if (Rxapp == 65) {
    left(1023);
  }
  else if (Rxapp == 66) {
    right(1023);
  }
  else  stopMortor();


  Serial.println(Rxapp);
}
