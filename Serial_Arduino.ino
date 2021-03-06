#include <SoftwareSerial.h>
SoftwareSerial Uno(3, 2); // RX | TX
int led = 13;
void setup()
{
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Uno.begin(9600);
}

void loop() {
  while (Uno.available() > 0) // ถ้ามีการสื่อสารทาง Serial เข้ามา
  {
    if (Uno.read() == '\n') { // ถ้าค่าที่อ่านได้เป็น '\n' แสดงว่าจบค่าที่ส่งแล้ว
      int val = Uno.parseInt(); // อ่านค่าที่ส่งเข้ามาแล้วแปลงเป็นตัวเลข 
      Serial.println(val); // แสดงค่าที่อ่านได้ ออกไปที่จอ Serial Monitor

      if (val == 0) { // ประมวลผลจากข้อมูลที่ส่งเข้ามาทาง Serial เพื่อควบคุมตามที่ต้องการ
        digitalWrite(led, 0); 
      } else if (val == 1) {
        digitalWrite(led, 1);
      }
    }
  }
  delay(500);
}
