int Motor_A1 = 8;  // Left wheel, goes forward
int Motor_A2 = 6;  // Left wheel, goes backward
int Motor_B1 = 7;  // Right wheel, goes backward
int Motor_B2 = 5;  // Right wheel, goes forward
const int encoderPin_R2 = 9;
volatile int prevStateA = HIGH;
volatile int distanceMovedA = 0;

void isrA() {
  Serial.println("Motion detected");
//  int currentStateA = digitalRead(encoderPin_R2);
//  if (currentStateA != prevStateA) {
//    // Change in state detected
//    distanceMovedA++;
//    prevStateA = currentStateA;
//  }
}

void setup() {
  // Initialize encoder input pin and motor control pins
  pinMode(encoderPin_R2, INPUT_PULLUP);
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);

  // Attach interrupt service routine
  attachInterrupt(digitalPinToInterrupt(encoderPin_R2), isrA, CHANGE);

  // Start serial communication
  Serial.begin(9600);


  forward();
}

void loop() {
  forward();
  Serial.print("Distance Moved A: ");
  Serial.println(distanceMovedA);
  int valueR2 = digitalRead(encoderPin_R2);
  Serial.print("Value A: ");
  Serial.println(valueR2);
  // Delay for a short period
  delay(200);
}

void forward(){
    analogWrite(Motor_A1, 128);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 251);
}
