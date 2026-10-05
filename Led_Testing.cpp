void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

// void pin4(){
//   digitalWrite(4, HIGH);
//   delay(500);
//   digitalWrite(4, LOW);
//   delay(500);
// }

// void pin5(){
//   digitalWrite(4, HIGH);
//   delay(500);
//   digitalWrite(4, LOW);
//   delay(500);
// }

void pinLight2(int x, int y){
  digitalWrite(y, LOW);
  digitalWrite(x, HIGH);
  delay(500);
  digitalWrite(x, LOW);
  digitalWrite(y, HIGH);
  delay(500);
}

void pinLight3(int x, int y, int z){
  digitalWrite(x, HIGH);
  delay(100);
  digitalWrite(y, HIGH);
  digitalWrite(x, LOW);
  delay(100);
  digitalWrite(z, HIGH);
  digitalWrite(y, LOW);
  delay(100);
  digitalWrite(z, LOW);
  delay(500);
}

void loop() {
  // pinLight2(4, 5);
  pinLight3(4, 5, 6);
}

