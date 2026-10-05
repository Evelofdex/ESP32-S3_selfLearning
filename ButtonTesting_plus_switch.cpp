// #define button_grey 13
#define button_green 4
#define switch1 12
#define led_red 11
#define led_oren 5

void setup() {
  Serial.begin(115200);
  pinMode(button_green, INPUT_PULLUP);
  // pinMode(button_grey, INPUT_PULLUP);
  pinMode(switch1, INPUT_PULLUP);
  pinMode(led_oren, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void pressButton(int led, int button){
  if (digitalRead(button) == HIGH){
    //button not press
    // Serial.println("high");
    // delay(500);
    digitalWrite(led, LOW);
  } else {
    //button pressed
    // Serial.println("low");
    // delay(500);
    digitalWrite(led, HIGH);
  }
}

// bool isDown;
// void toggleButton(int led, int button){
//   if (digitalRead(button) == HIGH){
//     //button up
//     // Serial.println("high, button up");
//     // delay(500);
//     digitalWrite(led, LOW);
//   } else {
//     //button down
//     // Serial.println("low, button down");
//     // delay(500);
//     if (isDown){
//       isDown = false;
//     } else {
//       isDown = true;
//     }
//     digitalWrite(led, HIGH);
//   }
//   Serial.println(isDown);
//   delay(300);
// }

void switchLed(int led, int sw){
  if (digitalRead(sw) == HIGH){
    // Serial.println("high, to right");
    // delay(400);
    digitalWrite(led, HIGH);
  } else {
    // Serial.println("low, to left");
    // delay(400);
    digitalWrite(led, LOW);
  }
}


void loop() {
  pressButton(led_oren, button_green);
  // toggleButton(led_red, button_grey);
  switchLed(led_red, switch1);
}
