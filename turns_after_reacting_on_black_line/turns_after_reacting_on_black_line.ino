

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 10;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 9;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards
bool lineMaze = false;
bool finished = false;



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
//  for (int i = 0; i <= 7; i++) {
////    Serial.print("Value "+String(i)+" : ");
//    v[i] = analogRead(sensorPins[i]);
////    Serial.println(v[i]);
//  }

  
  if (isEverythingWhite()) {
    turnAround();
  }
  else if (analogRead(sensorPins[2]) > 700 && analogRead(sensorPins[4]) > 700) {
    moveSlightlyRight();
  }
  else if ((analogRead(sensorPins[3]) > 700 && analogRead(sensorPins[5]) > 700) || analogRead(sensorPins[5]) > 700 || analogRead(sensorPins[6]) > 700) {
    moveSlightlyLeft();
  } 
  else if (analogRead(sensorPins[0]) > 800){
    turnRight();
  }
  else {
//    Serial.println("Continue moving forward");
    forward();
  }
  delay(1); 
}

void forward() {
  analogWrite(Motor_A1, 155);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 164);
}

void moveSlightlyLeft() {
  analogWrite(Motor_A1, 155);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 201);
}

void moveSlightlyRight() {
  analogWrite(Motor_A1, 197);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 164);
}

void stopMoving() {
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, LOW);
  delay(500);
}

void turnAround() {
  delay(220);
  spinLeft();
  delay(470);
  stopMoving();
  if (!isEverythingWhite()) {
    forward();
    return;
  }
  spinLeft();
  delay(430);
  stopMoving();
}

//void turnAround() {
//  delay(320);
//  spinRight();
//  delay(470);
//  stopMoving();
//  if (!isEverythingWhite()) {
//    forward();
//    return;
//  }
//  spinLeft();
//  delay(920);
//  stopMoving();
//  if (!isEverythingWhite()) {
//    forward();
//    return;
//  }
//  spinLeft();
//  delay(500);
//}

void turnRight() {
  delay(340);
  spinRight();
  delay(470);
  stopMoving();
}

void spinLeft() {
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, 202.0);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 192.0);  
}

void spinRight() {
  analogWrite(Motor_A1, 190.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, 188.0);
  analogWrite(Motor_B2, LOW);  
}

//void turnRightOrLeftOrMoveForward() {
//  unsigned long startTime = millis();
//  while (millis() - startTime < 180) {
//    if (analogRead(sensorPins[7]) > 700 || analogRead(sensorPins[6]) > 700 || analogRead(sensorPins[5]) > 700) {
//      turnAround(0);
//      return;
//    }  
//  }
//  if (isEverythingWhite()) {
//    delay(100);
//    spinRight();
//    delay(420);
//  }
//  forward();
//  delay(50);
//}

bool isEverythingWhite() {
  for (int i = 0; i <= 7; i++) {
    if (analogRead(sensorPins[i]) > 720 ) {
      return false;
    }
  }
  return true;
}

bool black() {
  for (int i = 1; i <= 6; i++) {
    if (analogRead(sensorPins[i]) < 720 ) {
      return false;
    }
  }
  return true;
}
