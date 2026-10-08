#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

#include <string>

#define SCK_SCL_PIN 40 // sesuain sama pin yg dipasang
#define SDA_PIN 41 // sesuain sama pin yg dipasang

U8G2_SH1106_128X32_VISIONOX_F_HW_I2C lcd(U8G2_R0, U8X8_PIN_NONE);


void setup() {
  Serial.begin(921600);
  Serial.println("\nESP32-S3, Start");

  Wire.begin(SDA_PIN, SCK_SCL_PIN); // SDA, SCK/SCL
  lcd.begin();
  lcd.clearBuffer();
  lcd.setFont(u8g2_font_ncenB08_tr);
  lcd.drawStr(3, 13, "Reading...");
  lcd.sendBuffer();
}

int num = 0;
String numText;
void loop() {
  lcd.clearBuffer();
  numText = "Counter: " + String(num);
  lcd.drawStr(35, 20,  numText.c_str());
  lcd.sendBuffer();
  delay(1000);
  num++;
}
