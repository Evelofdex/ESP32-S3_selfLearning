#include <Arduino.h>
#include <String>

#define AO_PIN 4 // analog
#define DO_PIN 40 // digital


void setup() {
  Serial.begin(921600);
  Serial.println("\nESP32-S3, Start");
  pinMode(AO_PIN, INPUT);
  pinMode(DO_PIN, INPUT);
}

int loudness;   
bool triggered;
void loop() {
  loudness = analogRead(AO_PIN); // 0 ~ 4095 on ESP32-S3
  triggered = digitalRead(DO_PIN) == HIGH;

  Serial.println("Loudness: " + String(loudness));
  Serial.println("isTriggered: " + String(triggered ? "yes" : "no"));
  delay(100);
}
