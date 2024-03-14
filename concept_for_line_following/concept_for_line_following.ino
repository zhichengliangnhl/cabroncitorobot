

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 10;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 9;  // Right wheel, goes forward
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
  if (v[2] > 720 && v[4] > 720) {
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
  analogWrite(Motor_A1, 155);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_B1, 0);
  analogWrite(Motor_B2, 164);
}

void moveSlightlyLeft() {
  analogWrite(Motor_A1, 155);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 184);
}

void moveSlightlyRight() {
  analogWrite(Motor_A1, 175);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 164);
}

void stopMoving() {
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);
  delay(500);
}
