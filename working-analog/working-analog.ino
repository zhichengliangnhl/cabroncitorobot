int alog-d1 = A0, alog-d2 = A1, alog-d3 = A2, alog-d4 = A3, alog-d5 = A4, alog-d6 = A5, alog-d7 = A6, alog-d8 = A7;
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards

const int trigPin = 9;
const int echoPin = 10;
const int stopDistance = 150; // Threshold distance to stop and turn left


void setup() {
  pinMode(alog-d1, OUTPUT);
  pinMode(alog-d2, OUTPUT);
  pinMode(alog-d3, OUTPUT);
  pinMode(alog-d4, OUTPUT);
  pinMode(alog-d5, OUTPUT);
  pinMode(alog-d6, OUTPUT);
  pinMode(alog-d7, OUTPUT);
  pinMode(alog-d8, OUTPUT);
  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);

}

void loop() {
  // Read distance from ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  
  // Check if the robot is too close to an obstacle
  if (distance < 20) {
    stopAndTurnLeft();
  } else {
    // Move forward
    analogWrite(Motor_A1, HIGH);
    analogWrite(Motor_A2, LOW);
    analogWrite(Motor_B1, LOW);
    digitalWrite(Motor_B2, HIGH);
  }
}

void stopAndTurnLeft() {
  // Stop the robot
  analogWrite(Motor_A1, HIGH);
  analogWrite(Motor_A2, HIGH);
  analogWrite(Motor_B1, HIGH);
  analogWrite(Motor_B2, HIGH);

  delay(500);
  // Turn left
  analogWrite(Motor_A1, HIGH);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, HIGH);
  analogWrite(Motor_B2, LOW);
  
  // Delay to complete the turn
  delay(450); // Adjust this delay as needed
  
  // Resume moving forward
  analogWrite(Motor_A1, HIGH);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, HIGH);
}
