int Motor_A1 = 8;  // Left wheel, goes forward
int Motor_A2 = 6;  // Left wheel, goes backward
int Motor_B1 = 7;  // Right wheel, goes backward
int Motor_B2 = 5;  // Right wheel, goes forward
const int encoderPin_R2 = 9;
const int encoderPin_R1 = 10;
volatile int prevStateA = HIGH;
volatile int prevStateB = HIGH;
volatile int distanceMovedA = 0;
volatile int distanceMovedB = 0;

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
  forward();
  recordDistancePassedByA();
  recordDistancePassedByB();
  Serial.print("Distance Moved A: ");
  Serial.println(distanceMovedA);
  Serial.print("Distance Moved B: ");
  Serial.println(distanceMovedB);
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
    analogWrite(Motor_A1, 128);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 254);
}
