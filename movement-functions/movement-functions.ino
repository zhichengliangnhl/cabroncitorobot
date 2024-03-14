

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards


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
  forward();
  delay(20);
}



void forward () {
  analogWrite(Motor_A1, 128.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 250.5);
}

void moveSlightlyLeft () {
  analogWrite(Motor_A1, 128.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 254.8);
}

void moveSlightlyRight () {
  analogWrite(Motor_A1, 131.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 244.8);
}

void stopMoving() {
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);
  delay(500);
}

void turnAround() {
  forward();
  delay(200);
  stopMoving();
  spin();
  delay(450);
  stopMoving();
  if (!isEverythingWhite()) {
    forward();
    return;
  }
  spin();
  delay(450);
  stopMoving();
  delay(100);
}

void spin() {
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, 202.0);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 192.0);  
}


void turnRightOrMoveForward() {
  stopMoving();
  forward();
  delay(20);
  stopMoving();
  if (analogRead(sensorPins[7]) > 720 || analogRead(sensorPins[6]) > 720) {
    turnAround();  
  }
  if (isEverythingWhite()) {
    spin();
    delay(1050);
  }
  stopMoving();
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
