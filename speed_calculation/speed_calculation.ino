int Motor_A1 = 8;   // Left wheel, goes forward
int Motor_A2 = 6;   // Left wheel, goes backward
int Motor_B1 = 7;   // Right wheel, goes backward
int Motor_B2 = 5;   // Right wheel, goes forward
//you need to connect R1 and R2 rotation sensor pins with digital io pins
const int encoderPin_R2 = 11;
const int encoderPin_R1 = 12;
volatile int prevStateA = HIGH;
volatile int prevStateB = HIGH;
volatile int distanceMovedA = 0;
volatile int distanceMovedB = 0;

//I put the variables for speed testing here
float speedParamA1 = 133.0;
float speedParamA2 = 119.5;
float speedParamB1 = 127.0;
float speedParamB2 = 131.5;

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

  
  //all the functions are below
  movement();  
  recordDistancePassedByA();
  recordDistancePassedByB();

  //it counts distance passed in the time interval, and basically records average speed during the whole interval
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
    
  delay(2);
  }
}

//these two similiar fucntions add values to the distance passed for both motors A and B
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

void movement() {
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
}
