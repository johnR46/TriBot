#include <PS2X_lib.h>                  // เรียกใช้งานไลบรารีสำหรับจอยสติ๊ก PS2

#define PS2_DAT   8 // 8 (เดิม)               // กำหนดขา Data    เป็นขา 30
#define PS2_CMD   9  // 9(เดิม)                   // กำหนดขา Command เป็นขา 4
#define PS2_SEL   10
#define PS2_CLK   11                  // กำหนดขา Clock   เป็นขา 12

PS2X ps2x;                             // ประกาศตัวแปรสำหรับจอยสติ๊ก PS2

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

  Serial.println("Connecting");        // แสดงข้อความเพื่อแจ้งว่า กำลังเชื่อมต่อกับจอยสติ๊ก
  while (true)                         // วนรอการเชื่อมต่อกับจอยสติ๊ก
  {
    // กำหนดขาเชื่อมต่อกับจอยสติ๊ก โดยมีการเก็บค่าที่ส่งกลับมาเป็น Integer เพื่อรู้ได้ว่าเชื่อมต่อได้หรือไม่
    int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);

    if (error == 0)                    // กรณีที่เชื่อมต่อได้ Error = 0
    {
      Serial.println("OK");            // แสดงข้อความว่า เชื่อมต่อกับจอยสติ๊กเรียบร้อยแล้ว
      delay(1000);                     // หน่วงเวลา 1 วินาที
      break;                           // ออกจาก while(true)
    }
    delay(500);                        // หน่วงเวลา 500 มิลลิวินาทีเพื่อรอการเชื่อมต่อครั้งต่อไปในกรณีที่เชื่อมต่อไม่สำเร็จ
  }
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
  ps2x.read_gamepad(false, false);     // อ่านข้อมูลจาก PS2 Controller
  if (ps2x.Button(PSB_CIRCLE))         // ถ้าปุ่มวงกลมถูกกด
    left(1023);
  // Serial.println("Circle");          // แสดงข้อความว่า Circle
  else if (ps2x.Button(PSB_CROSS))     // ถ้าปุ่มกากบาทถูกกด
    backward(1023);
  //Serial.println("Cross");           // แสดงข้อความว่า Cross
  else if (ps2x.Button(PSB_SQUARE))    // ถ้าปุ่มสี่เหลี่ยมถูกกด
    right(1023);
  //Serial.println("Square");          // แสดงข้อความว่า Square
  else if (ps2x.Button(PSB_TRIANGLE))  // ถ้าปุ่มสามเหลี่ยมถูกกด
    forward(1023);
  //Serial.println("Triangle");        // แสดงข้อความว่า Triangle
  else if (ps2x.Button(PSB_PAD_LEFT))  // ถ้าปุ่ม Left ถูกกด
    SpinLeft(1023);
  // Serial.println("Left");            // แสดงข้อความว่า Left
  else if (ps2x.Button(PSB_PAD_RIGHT)) // ถ้าปุ่ม Right ถูกกด
    SpinRight(1023);
  //Serial.println("Right");           // แสดงข้อความว่า Right

  else  stopMortor();
  delay(50);
}
