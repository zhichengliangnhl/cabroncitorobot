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


int speedParamA1 = 130;
float speedParamA2 = 3.0;
float speedParamB1 = 0.0;
int speedParamB2 = 254;

unsigned long lastMillis = 0;
unsigned long interval = 1000;

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

  calculateSpeed ();
  
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

void calculateSpeed () {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= interval) {
    // Calculate speed for wheel A
    float speedA = (float) distanceMovedA / interval; // Speed = Distance / Time
    Serial.print("Speed of Wheel A: ");
    Serial.println(speedA, 3);
    
    // Calculate speed for wheel B
    float speedB = (float) distanceMovedB / interval; // Speed = Distance / Time
    Serial.print("Speed of Wheel B: ");
    Serial.println(speedB, 3);

    // Reset distance counters
    distanceMovedA = 0;
    distanceMovedB = 0;

    // Update lastMillis
    lastMillis = currentMillis;
  }
}

void forward(){
    analogWrite(Motor_A1, speedParamA1);
    analogWrite(Motor_A2, speedParamA2);
    analogWrite(Motor_B1, speedParamB1);
    analogWrite(Motor_B2, speedParamB2);
}
