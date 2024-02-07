int green = 13, yellow = 12, red = 11;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {

    digitalWrite(green, LOW);
    delay(4000);
    digitalWrite(green, HIGH);

    digitalWrite(yellow, LOW);
    delay(1000);
    digitalWrite(yellow, HIGH); 

    digitalWrite(red, LOW);
    delay(3000);
    digitalWrite(red, HIGH);

}
