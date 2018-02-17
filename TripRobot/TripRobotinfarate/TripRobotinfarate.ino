#define Min_CH4    1080
#define Center_CH4 1490
#define Max_CH4    1905

#define Min_CH2    1080
#define Center_CH2 1490
#define Max_CH2    1905

#define Min_CH1    1070
#define Center_CH1 1474
#define Max_CH1    1900
#define Error 100
byte ch1 = 11;
byte ch2 = 12;
byte ch4 = 13;


void setup() {
  Serial.begin(9600);
  pinMode(ch1, INPUT_PULLUP);
  pinMode(ch2, INPUT_PULLUP);
  pinMode(ch4, INPUT_PULLUP);
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
void rightF(int pwm) {
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

void rightB(int pwm) {
  digitalWrite(2, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(10, 0);
  analogWrite(3, pwm);
  analogWrite(6, 0);
  analogWrite(9, pwm);
}
void leftF(int pwm) {
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

void leftB(int pwm) {
  digitalWrite(2, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(10, 1);
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
void TestPWM() {
  int CH1 = pulseIn(ch1, HIGH);
  int CH2 = pulseIn(ch2, HIGH);
  int CH4 = pulseIn(ch4, HIGH);

  Serial.print(CH1);
  Serial.print('\t');
  Serial.print(CH2);
  Serial.print('\t');
  Serial.print(CH4);
  Serial.println();
}
void loop() {
  int CH1 = pulseIn(ch1, HIGH);
  int CH2 = pulseIn(ch2, HIGH);
  int CH4 = pulseIn(ch4, HIGH);

  int PWM_Speed; //  = 0
  if (!((CH1 >= Center_CH1 + Error || CH1 <= Center_CH1 - Error) || (CH2 >= Center_CH2 + Error || CH2 <= Center_CH2 - Error)))
  {
    stopMortor();

  }
  else if (CH2 > (Center_CH2 + Error))
  {
    PWM_Speed = map(CH2, Center_CH2 + Error, Max_CH2, 0, 1023);// map(ค่าดิบ,ค่าอยู่ในช่วงที่กด,ค่าสูงสุดของค่าดิบ,ค่าต่ำสุดที่ต้องการ (MIN),ค่าสูงสุดที่ต้องการ (MAX));
    backward(PWM_Speed);
  }
  else if (CH2 < (Center_CH2 - Error))
  {
    PWM_Speed = map(CH2, Center_CH2 - Error, Max_CH2, 0, 1023);
    forward(PWM_Speed);
  }
  if (CH1 > (Center_CH1 + Error))
  {
    //  PWM_Speed = map(CH1, Center_CH1 + Error, Min_CH1, 0, 1023);
    // right(PWM_Speed);
  }
  if (CH1 < (Center_CH1 - Error))
  {
    //PWM_Speed = map(CH1, Center_CH1 - Error, Min_CH1, 0, 1023);
    //left(PWM_Speed);
  }
  if (CH4 > (Center_CH4 + Error))
  {
    PWM_Speed = map(CH4, Center_CH4 - Error, Min_CH4, 0, 1023);
    SpinLeft(PWM_Speed);
  }

  if (CH4 < (Center_CH4 - Error))
  {
    PWM_Speed = map(CH4, Center_CH4 - Error, Min_CH4, 0, 1023);
    SpinRight(PWM_Speed);
  }
  if (((CH1 >= Center_CH1 + Error || CH1 <= Center_CH1 - Error) && (CH2 >= Center_CH2 + Error || CH2 <= Center_CH2 - Error))) {
    if ((CH1 <= Center_CH1 - Error) && (CH2 <= Center_CH2 - Error)) {
      // ตะวันตกเฉียงเหนือ
      rightB(1023);
      //    Serial.print(CH1);
      //  Serial.print('\t');
      //  Serial.print(CH2);
      //  Serial.println();
    }
    if ((CH1 >= Center_CH1 - Error) && (CH2 <= Center_CH2 - Error)) {
      //   ตะวันออกเฉียงเหนือ
      leftB(1023);
      //   Serial.print(CH1);
      //  Serial.print('\t');
      //  Serial.print(CH2);
      //  Serial.println();
    }
    if ((CH1 >= Center_CH1 - Error) && (CH2 >= Center_CH2 - Error)) {
      ////   ตะวันออกเฉียงใต
      rightF(1023);
      //  Serial.print(CH1);
      //Serial.print('\t');
      //Serial.print(CH2);
      //Serial.println();
    }

    if ((CH1 <= Center_CH1 - Error) && (CH2 >= Center_CH2 - Error)) {
      ////   ตะวันตกเฉียงใต
      leftF(1023);
      //      Serial.print(CH1);
      //      Serial.print('\t');
      //      Serial.print(CH2);
      //      Serial.println();
    }
  }

}
