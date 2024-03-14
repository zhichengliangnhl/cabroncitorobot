

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 10;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 9;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards
unsigned long turnRightMillis = 0;



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
  if (v[0] < 720 && v[1] < 720 && v[2] < 720 && v[3] < 720 && v[4] < 720 && v[5] < 720 && v[6] < 720 && v[7] < 720) {
//    Serial.println("Time to turn left");
    turnAround(0);
  }
  else if ((v[7] < 720 && v[0] > 720) || (v[6] < 720 && v[0] > 720)){
//    Serial.println("Time to turn right or go forward");
    turnRightOrMoveForward();
  }
  else if (v[2] > 720 && v[4] > 720) {
//    Serial.println("Time to readjust to the right");
    moveSlightlyRight();
  }
  else if ((v[3] > 700 && v[5] > 700) || v[5] > 700 || v[6] > 700 || v[7] > 700) {
//    Serial.println("Time to readjust to the left");
    moveSlightlyLeft();
  } 
  else if (v[3] > 700 || v[4] >700) {
//    Serial.println("Continue moving forward");
    forward();
  }
  else {
//    Serial.println("Continue moving forward");
    forward();
  }
  delay(1); 
}

void forward() {
  analogWrite(Motor_A1, 128.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 250.8);
}

void moveSlightlyLeft() {
  analogWrite(Motor_A1, 128.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 255);
  //
}

void moveSlightlyRight() {
  analogWrite(Motor_A1, 131.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 244.0);
}

void stopMoving() {
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);
  delay(500);
}

void turnAround(int forwardDelay) {
  delay(220 - forwardDelay);
  stopMoving();
  spinLeft();
  delay(440);
  stopMoving();
  if (!isEverythingWhite()) {
    forward();
    return;
  }
  spinLeft();
  delay(440);
}

void spinLeft() {
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, 202.0);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 192.0);  
}

void spinRight() {
  analogWrite(Motor_A1, 138.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, 128.0);
  analogWrite(Motor_B2, LOW);  
}

void turnRightOrMoveForward() {
  turnRightMillis = millis();
  while (millis() < turnRightMillis + 160) {
    if (analogRead(sensorPins[7]) > 720 || analogRead(sensorPins[6]) > 720 || analogRead(sensorPins[5]) > 720) {
      turnAround(0);
      return;
    }  
    delay(1);
  }
  if (isEverythingWhite()) {
    delay(100);
    spinRight();
    delay(420  );
  }
  forward();
  delay(50);
}

bool isEverythingWhite() {
  for (int i = 0; i <= 7; i++) {
    v[i] = analogRead(sensorPins[i]);
    if (v[i] > 720 ) {
      return false;
    }
  }
  return true;
}
