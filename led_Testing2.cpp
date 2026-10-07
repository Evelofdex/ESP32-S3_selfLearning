#include <Arduino.h>

#define LED_RED 4
#define LED_YELLOW 5
#define LED_BLUE 6

void setup() {
  Serial.begin(921600);
  Serial.println("hello ESP");
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  
}
