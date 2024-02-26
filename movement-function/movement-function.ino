int Motor_A1 = 8;  // Left wheel, goes forward
int Motor_A2 = 6;  // Left wheel, goes backward
int Motor_B1 = 7;  // Right wheel, goes backward
int Motor_B2 = 5;  // Right wheel, goes forward

void setup() {
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);
}

void loop() {
    forward();
}

void forward(){
    analogWrite(Motor_A1, 128.2);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 252.1);
  }

void backward() {
    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 220);
    analogWrite(Motor_B1, 220);
    analogWrite(Motor_B2, 0);

    delay(1000);

    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
  }

void right() {
    analogWrite(Motor_A1, 220);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 220);
    analogWrite(Motor_B2, 0);

    delay(1000);

    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
  }

void left() {
    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 220);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 220);

    delay(1000);

    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
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

void stop() {
    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
  }
