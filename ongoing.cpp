#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <driver/i2s.h>
#include <String>

// LCD OLED
#define PIN_20 20 // SCK/SCL
#define PIN_21 21 // SDA

U8G2_SH1106_128X32_VISIONOX_F_HW_I2C lcd(U8G2_R0, U8X8_PIN_NONE);

//MIC
#define PIN_42 42 // SD
#define PIN_41 41 // SCK
#define PIN_40 40 // WS
#define I2S_PORT I2S_NUM_0
#define SAMPLE_RATE 16000
#define BUFFER_LEN  512

int32_t sBuffer[BUFFER_LEN];


// LCD OLED METHODs
void LCD_OLED_SETUP(int SDA, int SCK){
    Wire.begin(SDA, SCK); // SDA, SCK/SCL
    lcd.begin();
    lcd.clearBuffer();
    lcd.setFont(u8g2_font_ncenB08_tr);
    lcd.drawStr(3, 13, "Reading...");
    lcd.sendBuffer();
}
int num = 0;
String numText;
void LCD_OLED_LOOP(){
    lcd.clearBuffer();
    numText = "Counter: " + String(num);
    lcd.drawStr(35, 20,  numText.c_str());
    lcd.sendBuffer();
    delay(1000);
    num++;
}

//MIC METHODs
void MIC_SETUP(int SD, int SCK, int WS, i2s_port_t PortNum, uint32_t SampleRate, int BufferLen){
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = SampleRate,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 8,
        .dma_buf_len = BufferLen,
        .use_apll = false
    };
    i2s_pin_config_t pin_config = {
        .bck_io_num = SCK,
        .ws_io_num = WS,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num = SD
    };
    i2s_driver_install(PortNum, &i2s_config, 0, NULL);
    i2s_set_pin(PortNum, &pin_config);
    i2s_zero_dma_buffer(PortNum);
}

double rms;
void MIC_LOOP(i2s_port_t PortNum){
    size_t bytes_read = 0;
    i2s_read(PortNum, sBuffer, sizeof(sBuffer), &bytes_read, portMAX_DELAY);
    int samples_read = bytes_read / sizeof(int32_t);
    double sum = 0;
    for (int i = 0; i < samples_read; i++) {
        // INMP441 sends 24-bit audio left-aligned in 32-bit word
        // shift right 8 bits to get the real 24-bit value
        int32_t sample = sBuffer[i] >> 8;
        sum += (double)sample * (double)sample;
    }
    rms = sqrt(sum / samples_read);
    Serial.println(rms, 0);
}









void setup() {
    Serial.begin(921600);
    Serial.println("\nESP32-S3, Start");
    // LCD_OLED_SETUP(PIN_20, PIN_21);
    MIC_SETUP(PIN_42, PIN_41, PIN_40, I2S_PORT, SAMPLE_RATE, BUFFER_LEN);
}

String content;
void loop() {
    // LCD_OLED_LOOP();
    MIC_LOOP(I2S_PORT);
    // lcd.clearBuffer();
    // lcd.drawBox(0, 20, map(rms, 0, 300000, 0, 128), 10);
    // lcd.sendBuffer();
}   


