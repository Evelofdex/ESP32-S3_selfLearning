#include <Arduino.h>
#include <Wire.h>


#define SCK_SCL_PIN 40 // sesuain sama pin yg dipasang
#define SDA_PIN 41 // sesuain sama pin yg dipasang


void setup() {
  Serial.begin(921600); // sesuain juga bagian ini
  Serial.println("hello ESP");
  Wire.begin(SDA_PIN, SCK_SCL_PIN); // SDA, SCK/SCL
}



void loop() {
  byte count = 0;
  for (byte addr = 8; addr < 120; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C at 0x");
      Serial.println(addr, HEX);
      count++;
    }
  }
  Serial.println(count ? "Done." : "Nothing found.");
  delay(3000);
}

// sebagian besar dibantu AI
