int gripper = 2;

void setup() {
  pinMode(gripper, OUTPUT);
}

void loop() {

   for(int i = 0; i < 10; i++) {
    movegripper(90);
    delay(1000);
    movegripper(0);
    delay(1000);
  }
}

void movegripper(int angle) {
  int mapAngle = map(angle, 0 , 180, 544, 2400);

  digitalWrite(gripper, HIGH);
  delayMicroseconds(mapAngle);
  digitalWrite(gripper, LOW);
  delay(20);
  }
