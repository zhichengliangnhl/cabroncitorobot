int green = 13, yellow = 12, red = 11;
int btn1 = 4;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(btn1, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(!digitalRead(btn1)) {
    lights();
    } else {
      digitalWrite(green, HIGH);
      digitalWrite(yellow, HIGH);
      digitalWrite(red, HIGH);
      Serial.println("No");
      }
}

void lights() {

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
