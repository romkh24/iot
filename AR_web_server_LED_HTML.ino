#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;
uint8_t pin_led = 16;
char* ssid = "unit_tester";
char* password = "unit_tester";

char webpage[] PROGMEM = R"=====(
<html>
<head>
</head>
<body>
<form action="/toggle">
<button> TOGGLE </button>
</form>
</body>
</html>
)=====";

void setup()
{
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/html","<h1>Hello World!</h1>");});
  server.on("/toggle",toggleLED);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send_P(200,"text/html", webpage);
}
