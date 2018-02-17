
void setup() {

  delay(1000);                         // หน่วงเวลา 1 วินาทีเพื่อรอให้บอร์ดพร้อมทำงาน
  pinMode(1, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
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

}



void SpinRight(int pwm) {
  digitalWrite(2, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(10, 1);
  analogWrite(3, pwm);
  analogWrite(6, pwm);
  analogWrite(10, pwm);
}

void SpinLeft(int pwm) {
  digitalWrite(2, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(10, 0);
  analogWrite(3, pwm);
  analogWrite(6, pwm);
  analogWrite(10, pwm);
}


void right(int pwm) {
  digitalWrite(2, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(10, 1);
  analogWrite(3, pwm);
  analogWrite(6, 0);
  analogWrite(10, pwm);
}

void left(int pwm) {
  digitalWrite(2, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(10, 1);
  analogWrite(3, 0);
  analogWrite(6, pwm);
  analogWrite(10, pwm);
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
  analogWrite(10, 0);
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
  analogWrite(10, 0);
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
  analogWrite(10, 0);
}


void loop() {
  // forward(1023);
  stopMortor();
}
