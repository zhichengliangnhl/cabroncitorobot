

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards

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
  if (v[0] < 720 && v[1] < 720 && v[2] < 720 && v[3] < 720 && v[4] < 720 && v[5] < 720 && v[6] < 720 && v[7] < 720) {
//    Serial.println("Time to turn left");
    turnAround();
  }
  else if (v[7] < 720 && v[0] > 700){
//    Serial.println("Time to turn right or go forward");
    turnRightOrLeftOrMoveForward();
  }
  else if ((v[2] > 720 && v[4] > 720) || ((v[3] < 720 && v[4] < 720) && v[1] > 720)) {
//    Serial.println("Time to readjust to the right");
    moveSlightlyRight();
  }
  else if ((v[3] > 720 && v[5] > 720) || ((v[3] < 720 && v[4] < 720) && v[6] > 720)) {
//    Serial.println("Time to readjust to the left");
    moveSlightlyLeft ();
  } 
  else if (v[3] > 720 || v[4] > 720) { 
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
}

void spin() {
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, 202.0);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 192.0);  
}


void turnRightOrLeftOrMoveForward () {
  stopMoving();
  forward();
  delay(180);
  stopMoving();
  if (isEverythingWhite()) {
    spin();
    delay(850);
  delay(500);
  }
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
