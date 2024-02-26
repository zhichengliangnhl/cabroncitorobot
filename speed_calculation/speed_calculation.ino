int Motor_A1 = 8;   // Left wheel, goes forward
int Motor_A2 = 6;   // Left wheel, goes backward
int Motor_B1 = 7;   // Right wheel, goes backward
int Motor_B2 = 5;   // Right wheel, goes forward
const int encoderPin_R2 = 11;
const int encoderPin_R1 = 12;
volatile int prevStateA = HIGH;
volatile int prevStateB = HIGH;
volatile int distanceMovedA = 0;
volatile int distanceMovedB = 0;

float speedParamA1 = 130.0;
float speedParamA2 = 0.0;
float speedParamB1 = 0.0;
float speedParamB2 = 0.0;
//slightly right
//128.0
//31.0
//0.0
//201.0
//slightly left
//128.0
//35.0
//0.0
//220.0

unsigned long lastMillis = 0;
unsigned long interval = 3000;

void setup() {
  // Initialize encoder input pin and motor control pins
  pinMode(encoderPin_R1, INPUT_PULLUP);
  pinMode(encoderPin_R2, INPUT_PULLUP);
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  
//  recordDistancePassedByA();
//  recordDistancePassedByB();
//
//  unsigned long currentMillis = millis();
  stopAndTurnLeft();
//  if (currentMillis - lastMillis >= interval) {
//    // Calculate speed for wheel A
//    float speedA = (float) distanceMovedA / interval; // Speed = Distance / Time
//    Serial.print("Speed of Wheel A: ");
//    Serial.println(speedA, 3);
//    
//    // Calculate speed for wheel B
//    float speedB = (float) distanceMovedB / interval; // Speed = Distance / Time
//    Serial.print("Speed of Wheel B: ");
//    Serial.println(speedB, 3);
//
//    // Reset distance counters
//    distanceMovedA = 0;
//    distanceMovedB = 0;
//
//    // Update lastMillis
//    lastMillis = currentMillis;
  
  delay(5);
  
}

void recordDistancePassedByA() {
  int currentStateA = digitalRead(encoderPin_R2);
  if (currentStateA != prevStateA) {
    distanceMovedA++;
    prevStateA = currentStateA;
  }
}

void recordDistancePassedByB() {
  int currentStateB = digitalRead(encoderPin_R1);
  if (currentStateB != prevStateB) {
    distanceMovedB++;
    prevStateB = currentStateB;
  }
}

void forward(){
    analogWrite(Motor_A1, speedParamA1);
    analogWrite(Motor_A2, speedParamA2);
    analogWrite(Motor_B1, speedParamB1);
    analogWrite(Motor_B2, speedParamB2);
}

void stopAndTurnLeft() {
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);

  delay(1000);
  // Turn left
  analogWrite(Motor_A1, 3.0);
  analogWrite(Motor_A2, 130.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 254.0);
  
  // Delay to complete the turn
  delay(400);
  
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);

  delay(2000);
}
