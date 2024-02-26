int gripper = 2;

void setup() {
  pinMode(gripper, OUTPUT);
}

void loop() {
  moving(0);

  moving(90);

  moving(180);
}

void moving(int angle) {
  int pulseWidth = map(angle, 0 , 180, 544, 2400);

  analogWrite(gripper, HIGH);
  delayMicroseconds(pulseWidth);
  analogWrite(gripper, LOW);
  delay(20);
  }
