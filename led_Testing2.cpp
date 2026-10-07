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

void ledOn(int led_1, int led_2, int led_3){
  digitalWrite(led_3, LOW);
  digitalWrite(led_1, HIGH); 
  delay(50);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH);
  delay(50);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH);
  delay(50);
  digitalWrite(led_3, LOW);
  delay(500);
}

void loop() {
  ledOn(LED_RED, LED_YELLOW, LED_BLUE);
}
