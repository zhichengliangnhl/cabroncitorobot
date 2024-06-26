int Motor_A1 = 10;   // Left wheel, goes forward
int Motor_A2 = 6;   // Left wheel, goes backward
int Motor_B1 = 9;   // Right wheel, goes backward
int Motor_B2 = 5;   // Right wheel, goes forward
//you need to connect R1 and R2 rotation sensor pins with digital io pins
const int encoderPin_R2 = 11;
const int encoderPin_R1 = 12;
volatile int prevStateA = HIGH;
volatile int prevStateB = HIGH;
volatile int distanceMovedA = 0;
volatile int distanceMovedB = 0;

//I put the variables for speed testing here


//slightly left
//float speedParamA1 = 150;
//float speedParamB2 = 220;
//slightly right
//float speedParamA1 = 197;
//float speedParamB2 = 164;
//turn left
//3.0
//197.0
//forward
//float speedParamA1 = 128.0;
//float speedParamB2 = 250.5;

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
  spinLeft();  
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
    
  delay(1);
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

void goBackwards(){
  analogWrite(Motor_A1, 0);// Left wheel, goes forward
  analogWrite(Motor_A2, 182);// Left wheel, goes backward
  analogWrite(Motor_B1, 171);//Right wheel, goes backward
  analogWrite(Motor_B2, 0);// Right wheel, goes forward
}

void forward() {
  analogWrite(Motor_A1, 207);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_B1, 0);
  analogWrite(Motor_B2, 213);
}

void moveSlightlyLeft() {
  analogWrite(Motor_A1, 150);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_B1, 0);
  analogWrite(Motor_B2, 220);
}

void moveSlightlyRight() {
  analogWrite(Motor_A1, 221);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_B1, 0);
  analogWrite(Motor_B2, 160);
}

void spinLeft() {
  analogWrite(Motor_A1, 0);
  analogWrite(Motor_A2, 238);//
  analogWrite(Motor_B1, 0);
  analogWrite(Motor_B2, 219);//  
}

void spinRight() {
  analogWrite(Motor_A1, 200);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_B1, 198);
  analogWrite(Motor_B2, 0);  
}

void backwards () {
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, 182);
  analogWrite(Motor_B1, 164);
  analogWrite(Motor_B2, LOW);
}
