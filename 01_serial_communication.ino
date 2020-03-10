int led = D4;
int val = 1;
void setup()
{
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
  Serial.println("Hello");
}
void loop()
{
  digitalWrite(led, 1); 
  Serial.print(val); 
  Serial.print(" ON "); 
  Serial.println("LED"); 
  delay(2000); 
  digitalWrite(led, LOW); 
  Serial.print("OFF ");
  Serial.println("LED"); 
  delay(2000); 

}
