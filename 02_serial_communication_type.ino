int led = D4;
char key = 0;
void setup()
{
  pinMode(led, OUTPUT); // 
  Serial.begin(9600);
  delay(2000);
  Serial.println("");
  Serial.println("Serial Receive");
  digitalWrite(led, LOW);//ON
  delay(100);
  digitalWrite(led, HIGH);//OFF
  delay(100);
}

void loop()
{
  if (Serial.available() > 0)
  {
    key = Serial.read();

    if (key == '0')
    {
      Serial.print("Value : ");
      Serial.println(key);
      digitalWrite(led, HIGH);

      Serial.print("LED ");
      Serial.println("OFF");
      delay(2000);
    }
    if (key == '1')
    {
      Serial.print("Value : ");
      Serial.println(key);
      digitalWrite(led, LOW);

      Serial.print("LED ");
      Serial.println("ON");
      delay(2000);
    }
   
  }

}
