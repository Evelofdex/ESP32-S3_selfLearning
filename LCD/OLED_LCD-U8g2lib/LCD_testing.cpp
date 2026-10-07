#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
/* di platformio.ini tambahin library U8g2:
  lib_deps:
    olikraus/U8g2@^2.35.19

abis itu di build dulu (yg tanda centang)
*/

// pas waktu scanning dpt ini, kemungkinan OLED LCD, tapi pas pake lib U8g2lib gk kepake amat 0x3C

#define SCK_SCL_PIN 40 // sesuain sama pin yg dipasang
#define SDA_PIN 41 // sesuain sama pin yg dipasang

U8G2_SH1106_128X32_VISIONOX_F_HW_I2C lcd(U8G2_R0, U8X8_PIN_NONE);
/* Penjelasan:
  U8G2_         = The library family name
  SH1106_128X64	= Your driver + resolution: SH1106 chip, 128 columns × 64 rows pixels
  NONAME        = Generic/cheap Chinese variant
  F_	          = Full buffer mode — keeps the whole screen in RAM, fastest, uses ~1KB
  HW_I2C	      = Uses hardware I2C (Wire / Wire1)
  lcd	          = Your object name; you can rename it to display, oled, etc.
  U8G2_R0	      = Rotation 0° (normal landscape)

  "Library, I have a 128×64 SH1106 OLED, connected by I2C, no reset pin, draw upright."

note:
  _F_ = full buffer (recommended for simple projects). _1_ or _2_ = page buffer (uses less RAM, but you redraw everything per page).

constructor umum yg lain:
  U8G2_SSD1306_128X64_NONAME_F_HW_I2C       // SSD1306 variant
  U8G2_SH1106_128X64_NONAME_F_SW_I2C        // software I2C (any two pins)
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C     // smaller 128x32 OLED
*/

void setup() {
  Serial.begin(921600);
  Serial.println("\nESP32-S3, Start");
  Wire.begin(SDA_PIN, SCK_SCL_PIN); // SDA, SCK/SCL

  lcd.begin(); //inisialisasi
  lcd.clearBuffer(); // hapus canvas, bersihin dulu
  lcd.setFont(u8g2_font_ncenB08_tr); // pilih font
  lcd.drawStr(0, 10, "Hello ESP32-S3!"); // masukin teks | (x, y, <teks nya>)
  lcd.sendBuffer();  //kirim data ny
  /* 
  syntax lain, buat referensi:
    u8g2.begin();                   // initialize
    u8g2.setFont(name);             // pick font
    u8g2.clearBuffer();             // erase canvas
    u8g2.drawStr(x, y, "text");     // draw text
    u8g2.drawLine(x0,y0,x1,y1);     // line
    u8g2.drawBox(x,y,w,h);          // filled rect
    u8g2.drawFrame(x,y,w,h);        // hollow rect
    u8g2.setCursor(x, y);           // for .print()
    u8g2.print(value);              // like Serial.print
    u8g2.sendBuffer();              // show it!
  */
}
void loop() {

}
