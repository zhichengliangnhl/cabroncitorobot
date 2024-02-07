int green = 13, yellow = 12, red = 11;
int btn1 = 4, btn2 = 3, btn3 = 2;
unsigned long time = 0;
bool state;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  Serial.begin(9600);

}

void loop() {
  if(millis() - 1500 >= time) {

    time = millis();

    state = !state;

    digitalWrite(red, state);
    }
    if(!digitalRead(btn1) || !digitalRead(btn2) || !digitalRead(btn3)) {
      digitalWrite(green, LOW);
      } else {
        digitalWrite(green, HIGH);
        }
    delay(100);
}
