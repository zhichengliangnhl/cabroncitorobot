#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(4, 4, NEO_RGB);

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards

int gripper = 2;
int NeoPixels = 1;

int Echo = 10;
int Trigger = 9;

boolean startRace = false;
boolean endRace = false;
boolean onBlack = false;
boolean onWhite = false;

void setup() {

  for (int i = 0; i <= 7; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  strip.begin();
  strip.show();
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);

  pinMode(Echo, INPUT);
  pinMode(Trigger, OUTPUT);

  pinMode(gripper, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 7; i++) {
    v[i] = analogRead(sensorPins[i]);
  }

  if (v[0] >= 750 && v[1] >= 750 && v[3] >= 750 && v[4] >= 750) {
    turnRight();
  } else if (v[7] >= 750 && v[6] >= 750 && v[3] >= 750 && v[4] >= 750) {
    turnLeft();
  } else if (v[0] >= 750 || v[1] >= 750 || v[2] >= 750 || v[3] >= 750 || v[4] >= 750 || v[5] >= 750 v[6] >= 750 || v[7] >= 750) {
    goForward();
  } else {
    turnAround();
  }

}

void setPixels(String dir) {
  strip.clear();
  if (dir == "L") {
    strip.setPixelColor(3, strip.Color(255, 120, 0));
  } else if (dir == "R") {
    strip.setPixelColor(2, strip.Color(255, 120, 0));
  } else if (dir == "B") {
    strip.setPixelColor(0, strip.Color(255, 0, 0));
    strip.setPixelColor(1, strip.Color(255, 0, 0));
  } else if (dir == "F") {
    strip.setPixelColor(3, strip.Color(0, 255, 0));
    strip.setPixelColor(2, strip.Color(0, 255, 0));
  }
  strip.show();
}

void moveSlightlyRight()
{
  digitalWrite(Motor_A1, LOW);// Left wheel, goes backwards
  analogWrite(Motor_A2, 220);// Left wheel, goes forward
  analogWrite(Motor_B1, 210);//Right wheel, goes forward
  digitalWrite(Motor_B2, LOW);// Right wheel, goes backwards

  delay(100);

  setPixelsRed();
  strip.clear();
}

void moveSlightlyLeft()
{
  analogWrite(Motor_A1, 0);// Left wheel, goes backwards
  analogWrite(Motor_A2, 210);// Left wheel, goes forward
  analogWrite(Motor_B1, 220);//Right wheel, goes forward
  analogWrite(Motor_B2, 0);// Right wheel, goes backwards
}

void goForward()
{
  setStrip("F");
  if (v[2] >= 750 || v[1] >= 750) {
    moveSlightlyRight();
  } else if (v[5] >= 750 || v[6] >= 750) {
    moveSlightlyLeft();
  } else if (v[7] >= 750) {
    moveBigLeft();
  } else if (v[0] >= 750) {
    moveBigRight();
  } else {
    analogWrite(Motor_A1, 0);// Left wheel, goes backwards
    analogWrite(Motor_A2, 220);// Left wheel, goes forward
    analogWrite(Motor_B1, 220);//Right wheel, goes forward
    analogWrite(Motor_B2, 0);// Right wheel, goes backwards
  }
}


void goBackwards()
{
  analogWrite(Motor_A1, 210);// Left wheel, goes backwards
  analogWrite(Motor_A2, 0);// Left wheel, goes forward
  analogWrite(Motor_B1, 0);//Right wheel, goes forward
  analogWrite(Motor_B2, 210);// Right wheel, goes backwards
}

void turnRight()
{
  analogWrite(Motor_A1, 0);// Left wheel, goes backwards
  analogWrite(Motor_A2, 210);// Left wheel, goes forward
  analogWrite(Motor_B1, 0);//Right wheel, goes forward
  analogWrite(Motor_B2, 210);// Right wheel, goes backwards

  delay(500);
  analogWrite(Motor_A1, 100);// Left wheel, goes backwards
  analogWrite(Motor_A2, 0);// Left wheel, goes forward
  analogWrite(Motor_B1, 100);//Right wheel, goes forward
  analogWrite(Motor_B2, 0);// Right wheel, goes backwards

  delay(100);

  analogWrite(Motor_A1, 0);// Left wheel, goes backwards
  analogWrite(Motor_A2, 0);// Left wheel, goes forward
  analogWrite(Motor_B1, 0);//Right wheel, goes forward
  analogWrite(Motor_B2, 0);// Right wheel, goes backwards
}

void turnAround()
{
  analogWrite(Motor_A1, 0);// Left wheel, goes backwards
  analogWrite(Motor_A2, 0);// Left wheel, goes forward
  analogWrite(Motor_B1, 0);//Right wheel, goes forward
  analogWrite(Motor_B2, 0);// Right wheel, goes backwards
  turnRight();
  isitBlack();
  if (onBlack) return;
  turnLeft();
  isitBlack();
  if (onBlack) return;
  turnLeft();
  isitBlack();
  if (onBlack) return;
  turnLeft();
  while (!onBlack) {
    isItBlack();
    goForward();
  }
}

void isItBlack() {
  if (v[0] >= 750 || v[1] >= 750 || v[2] >= 750 || v[3] >= 750 || v[4] >= 750, v[5] >= 750 || v[6] >= 750 || v[7] >= 750) {
    onBlack = true;
  } else {
    onBlack = false;
  }
}

void isItBlack() {
  if (v[0] >= 750 || v[1] >= 750 || v[2] >= 750 || v[3] >= 750 || v[4] >= 750, v[5] >= 750 || v[6] >= 750 || v[7] >= 750) {
    onBlack = true;
  } else {
    onBlack = false;
  }
}

void raceHasStarted() {
  startRace = true;
}

void raceHasEnded() {
  endRace = true;
}
