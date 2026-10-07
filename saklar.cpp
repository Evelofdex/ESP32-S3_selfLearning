#include <Arduino.h>

#define SWITCH1 4
#define LED_RED 6

void setup() {
  Serial.begin(921600);
  Serial.println("hello ESP");
  pinMode(SWITCH1, INPUT_PULLUP); // secara default jadi dikasih tegangan
  pinMode(LED_RED, OUTPUT);
}



void loop() {
  if (digitalRead(SWITCH1) == HIGH){ // jadi jika tidak di switch on, default diberi tegangan
    digitalWrite(LED_RED, LOW);
  } else { // jika switch ny ke on, maka tegangan ke low, jadi dibalik  (saklar atau button, dibagian sisi yg off nya harus ke GND, jangan sisi sama buat di tegangan HIGH, bingung cek wokwi aj dah)
    digitalWrite(LED_RED, HIGH); 
  }
}
