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

float speedParamA1 = 250.0;
float speedParamA2 = 123.0;
float speedParamB1 = 126.0;
float speedParamB2 = 250.5;

//slightly right
//130.0
//0.0
//0.0
//209.5
//slightly right, slow
//135.0
//110.0
//126.0
//129.5
//slightly left
//128.0
//36.2
//0.0
//254.5
//slightly left, slow
//128.1
//124.9
//126.0
//139.5
//turn left
//3.0
//202.0
//0.0
//197.0

unsigned long lastMillis = 0;
unsigned long interval = 3000;

void setup() {
  // Initialize encoder input pin and motor control pins
  pinMode(encoderPin_R1, INPUT_PULLUP);
  pinMode(encoderPin_R2, INPUT_PULLUP);
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  delay(2500);
  
  stopAndTurnLeft(); 
    
  delay(500);
}

void recordDistancePassedByA() {
  int currentStateA = digitalRead(encoderPin_R2);
  if (currentStateA != prevStateA) {
    distanceMovedA++;
    prevStateA = currentStateA;
  }
}

void movement() {
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
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
  
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
  
  delay(1000);
  
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);

  delay(500);
  
  analogWrite(Motor_A1, 3.0);
  analogWrite(Motor_A2, 202.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 197.0);
  
  delay(470);
  
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);
}
