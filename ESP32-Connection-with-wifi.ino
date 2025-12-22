#include <WiFi.h>

const char* ssid = "ESP32_AP";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println("ESP32 started AP");
  Serial.println(WiFi.softAPIP());
}

void loop() {}

