float MA1 = 8;
float MA2 = 6;
float MB1 = 7;
float MB2 = 5;
int echo = 10;
int trigger = 9;


void setup() {
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);

}

void loop() {
  stop();
  delay(2000);
  forward();
  delay(200);
  stop();
  delay(500);
  analogWrite(MA1, 130.0);
  analogWrite(MA2, 3.0);
  analogWrite(MB1, 0.0);
  analogWrite(MB2, 244.0);
  delay(200);
  stop();
  delay(2000);
  analogWrite(MA1, 130.0);
  analogWrite(MA2, 3.2);
  analogWrite(MB1, 0.0);
  analogWrite(MB2, 254.0);
  delay(200);
}

void stop() {
  analogWrite(MA1, 0.0);
  analogWrite(MA2, 0.0);
  analogWrite(MB1, 0.0);
  analogWrite(MB2, 0.0);
}

void forward() {
  analogWrite(MA1, 130.0);
  analogWrite(MA2, 0.0);
  analogWrite(MB1, 0.0);
  analogWrite(MB2, 254.2);
}
