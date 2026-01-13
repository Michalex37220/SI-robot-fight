#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // attendre que le port série soit prêt
  }
  Serial.println("ESP32 prêt !");
}

void loop() {
  Serial.println("Hello World");
  delay(100); // 100 ms → ~10 messages par seconde
}



