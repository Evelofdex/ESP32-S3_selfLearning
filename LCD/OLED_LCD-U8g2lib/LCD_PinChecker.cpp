#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

#include <string>

#define PIN_4 4
#define PIN_6 6

#define SCK_SCL_PIN 40 // sesuain sama pin yg dipasang
#define SDA_PIN 41 // sesuain sama pin yg dipasang

U8G2_SH1106_128X32_VISIONOX_F_HW_I2C lcd(U8G2_R0, U8X8_PIN_NONE);


void setup() {
  Serial.begin(921600);
  Serial.println("\nESP32-S3, Start");

  // pinMode(PIN_4, INPUT_PULLUP);
  // pinMode(PIN_6, INPUT_PULLUP);

  pinMode(PIN_4, INPUT_PULLDOWN);
  pinMode(PIN_6, INPUT_PULLDOWN);

  Wire.begin(SDA_PIN, SCK_SCL_PIN); // SDA, SCK/SCL
  lcd.begin();
  lcd.clearBuffer();
  lcd.setFont(u8g2_font_ncenB08_tr);
  lcd.drawStr(3, 13, "Reading...");
  lcd.sendBuffer();
}

const int xPin_4 = 20;
const int yPin_4 = 10; 

const int xPin_6 = 20;
const int yPin_6 = 25; 
void loop() {
  if (digitalRead(PIN_4) == HIGH){
    // Serial.println("pin 4 high");
    lcd.drawStr(xPin_4, yPin_4, "pin 4: HIGH");
    delay(500);
  } else {
    // Serial.println("pin 4 low");
    lcd.drawStr(xPin_4, yPin_4, "pin 4: LOW");
  }

  if (digitalRead(PIN_6) == HIGH){
    // Serial.println("pin 6 high");
    lcd.drawStr(xPin_6, yPin_6, "pin 5: HIGH");
    delay(500);
  } else {
    // Serial.println("pin 6 low");
    lcd.drawStr(xPin_6, yPin_6, "pin 5: LOW");
  }
  lcd.sendBuffer();
  delay(500);
  lcd.clearBuffer();
}
