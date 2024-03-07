#include <Adafruit_NeoPixel.h>

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards




float speedParamA1 = 133.0;
float speedParamA2 = 119.5;
float speedParamB1 = 127.0;
float speedParamB2 = 131.5;

//float speedParamA1 = 189.0;
//float speedParamA2 = 102.0;
//float speedParamB1 = 126.0;
//float speedParamB2 = 151.0;


void setup() {



  for (int i = 0; i <= 7; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  
//  pinMode(echoPin, INPUT);
//  pinMode(trigPin, OUTPUT);
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);
  
  Serial.begin(9600); // Initialize serial communication
}

void loop() {

//  for (int i = 0; i <= 6; i++) {
//    Serial.println(" ");
//  }
  for (int i = 0; i <= 7; i++) {
//    Serial.print("Value "+String(i)+" : ");
    v[i] = analogRead(sensorPins[i]);
//    Serial.println(v[i]);
  }
  if (v[7] > 750) {
//    Serial.println("Time to turn left");
    turnLeft(500);
  }
  else if (v[7] < 700 && v[0] > 750){
//    Serial.println("Time to turn right or go forward");
    turnRightOrLeftOrMoveForward ();
  }
  else if ((v[2] > 700 && v[4] > 700) || ((v[3] < 700 && v[4] < 700) && v[1] > 700)) {
//    Serial.println("Time to readjust to the right");
    moveSlightlyRight ();
  }
  else if ((v[3] > 700 && v[5] > 700) || ((v[3] < 700 && v[4] < 700) && v[6] > 700)) {
//    Serial.println("Time to readjust to the left");
    moveSlightlyLeft ();
  } 
  else if (v[3] > 700 || v[4] > 700) { 
//    Serial.println("Continue moving forward");
    forward ();
  }
  else {
//    Serial.println("Continue moving forward");
    forward ();
  }
  delay(1); 
}



void forward () {
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
}

void moveSlightlyLeft () {
  analogWrite(Motor_A1, 128.1);
  analogWrite(Motor_A2, 124.9);
  analogWrite(Motor_B1, 126.0);
  analogWrite(Motor_B2, 139.5);
}

void moveSlightlyRight () {
  analogWrite(Motor_A1, 135.0);
  analogWrite(Motor_A2, 110.0);
  analogWrite(Motor_B1, 126.0);
  analogWrite(Motor_B2, 129.5);
}

void stopMoving() {
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);
  delay(500);
}

void turnLeft(int delayVariable) {
  stopMoving();
  delay(1000);
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
  delay(delayVariable);
  stopMoving();
  analogWrite(Motor_A1, 3.0);
  analogWrite(Motor_A2, 202.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 197.0);
  delay(410);

}


void turnRightOrLeftOrMoveForward () {
  stopMoving();
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
  delay(120);
  if (analogRead(sensorPins[7]) < 720) {
    turnLeft(380);
    return;
  } 
  stopMoving();
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);  
  delay(450);
  if (analogRead(sensorPins[1]) < 700 && analogRead(sensorPins[2]) < 700 && analogRead(sensorPins[3]) < 700 && analogRead(sensorPins[4]) < 700 && analogRead(sensorPins[5]) < 700 && analogRead(sensorPins[6]) < 700) {
    stopMoving();
    analogWrite(Motor_A1, 3.0);
    analogWrite(Motor_A2, 202.0);
    analogWrite(Motor_B1, 0.0);
    analogWrite(Motor_B2, 197.0);
    delay(1270);
  stopMoving();
  delay(500);
  }
}
