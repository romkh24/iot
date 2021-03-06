//
// NodeMCU

#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

SoftwareSerial NodeMCU(D2, D3); // RX | TX
void setup() {
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(9600); // Hardware Serial ที่แสดงออกหน้าจอ Serial Monitor
  NodeMCU.begin(9600); // Software Serial ที่ NodeMCU ใช้สื่อสากับ Arduino Uno
}

void loop() {
  NodeMCU.println(1); // ส่งเลข 1 ไปให้ Arduino Uno และจบค่าที่ส่งด้วย \n
  delay(500);
  NodeMCU.println(0); 
  delay(500);
}
