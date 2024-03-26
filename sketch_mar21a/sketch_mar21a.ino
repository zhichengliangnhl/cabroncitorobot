#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(4, 4, NEO_RGB);

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 10;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 9;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards
bool lineMaze = false;
bool finished = false;

const int gripperPin = 2;
void moveGripper(int angle); // Function prototype declaration
void dropGripper(); // Function prototype declaration
bool stopGripper = false;

bool state = true;

int NeoPixels = 1;

int Echo = 7;
int Trigger = 8;

unsigned long startTime;

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
//  for (int i = 0; i <= 7; i++) {
////    Serial.print("Value "+String(i)+" : ");
//    v[i] = analogRead(sensorPins[i]);
////    Serial.println(v[i]);
//  }

//  if (lineMaze) {
//    if (isEverythingWhite()) {
//      turnAround();
//    }
//    else if (analogRead(sensorPins[2]) > 700 && analogRead(sensorPins[4]) > 700) {
//      moveSlightlyRight();
//    }
//    else if ((analogRead(sensorPins[3]) > 700 && analogRead(sensorPins[5]) > 700) || analogRead(sensorPins[5]) > 700 || analogRead(sensorPins[6]) > 700) {
//      moveSlightlyLeft();
//    } 
//    else if (analogRead(sensorPins[0]) > 800){
//      turnRight();
//    }
//    else {
//  //    Serial.println("Continue moving forward");
//      forward();
//    }
//    delay(1);
//  } 
}

void forward() {
  setStrip("F");
  analogWrite(Motor_A1, 155);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 164);
}

void moveSlightlyLeft() {
  setStrip("F");
  analogWrite(Motor_A1, 155);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 201);
}

void moveSlightlyRight() {
  setStrip("F");
  analogWrite(Motor_A1, 197);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 164);
}

void stopMoving() {
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, LOW);
  delay(500);
}

void turnAround() {
  delay(220);
  spinLeft();
  delay(470);
  stopMoving();
  if (!isEverythingWhite()) {
    forward();
    return;
  }
  spinLeft();
  delay(430);
  stopMoving();
}

//void turnAround() {
//  delay(320);
//  spinRight();
//  delay(470);
//  stopMoving();
//  if (!isEverythingWhite()) {
//    forward();
//    return;
//  }
//  spinLeft();
//  delay(920);
//  stopMoving();
//  if (!isEverythingWhite()) {
//    forward();
//    return;
//  }
//  spinLeft();
//  delay(500);
//}

void turnRight() {
  delay(340);
  spinRight();
  delay(470);
  stopMoving();
}

void spinLeft() {
  setStrip("L");
  analogWrite(Motor_A1, LOW);
  analogWrite(Motor_A2, 202.0);
  analogWrite(Motor_B1, LOW);
  analogWrite(Motor_B2, 192.0);  
}

void spinRight() {
  setStrip("R");
  analogWrite(Motor_A1, 190.0);
  analogWrite(Motor_A2, LOW);
  analogWrite(Motor_B1, 188.0);
  analogWrite(Motor_B2, LOW);  
}

//void turnRightOrLeftOrMoveForward() {
//  unsigned long startTime = millis();
//  while (millis() - startTime < 180) {
//    if (analogRead(sensorPins[7]) > 700 || analogRead(sensorPins[6]) > 700 || analogRead(sensorPins[5]) > 700) {
//      turnAround(0);
//      return;
//    }  
//  }
//  if (isEverythingWhite()) {
//    delay(100);
//    spinRight();
//    delay(420);
//  }
//  forward();
//  delay(50);
//}

bool isEverythingWhite() {
  for (int i = 0; i <= 7; i++) {
    if (analogRead(sensorPins[i]) > 720 ) {
      return false;
    }
  }
  return true;
}

bool black() {
  for (int i = 1; i <= 6; i++) {
    if (analogRead(sensorPins[i]) < 720 ) {
      return false;
    }
  }
  return true;
}

void setStrip(String dir) {
  strip.clear();
  if (dir == "L") {
    strip.setPixelColor(3, strip.Color(255, 120, 0));
  } else if (dir == "R") {
    strip.setPixelColor(2, strip.Color(255, 120, 0));
  } else if (dir == "B") {
    strip.setPixelColor(0, strip.Color(255, 0, 0));
    strip.setPixelColor(1, strip.Color(255, 0, 0));
  } else if (dir == "F") {
    strip.setPixelColor(3, strip.Color(0, 255, 0));
    strip.setPixelColor(2, strip.Color(0, 255, 0));
  }
  strip.show();
}

void moveGripper(int angle) {
  int mapAngle = map(angle, 0, 180, 544, 2400);

  unsigned long startTime = millis(); // Record the start time
  unsigned long duration = 1000; // Duration for gripper action in milliseconds
  
  for (int i = 0; i < 10; i++) { // Loop the gripper movement 10 times
    if (millis() - startTime >= duration) {
      break; // Exit the loop if the duration is exceeded
    }

    digitalWrite(gripperPin, HIGH); // Activate gripper
    delayMicroseconds(mapAngle); // Hold gripper position
    digitalWrite(gripperPin, LOW); // Release gripper
    delay(20); // Delay between actions
  }
}

void dropGripper() {
  // Function to drop the gripper
  int mapAngle = map(90, 0, 180, 544, 2400);
  // You can define the action to drop the gripper here
  // For example, open the gripper fully
  digitalWrite(gripperPin, HIGH); // Activate gripper (open)
  delayMicroseconds(mapAngle); // Delay to keep gripper open for 1 second (adjust as needed)
  digitalWrite(gripperPin, LOW); // Release gripper
  delay(20);

  if (stopGripper) {
    return;
    }
}

void lookMaybeStart() {
  // Declare variables
  static int consecutiveDetections = 0;
  long duration;
  long distance = 0; // Declare distance variable
  long prevDistance = 0; // Variable to store the previous distance

  // Loop until three consecutive detections are made
  while (consecutiveDetections < 10) {
    Serial.println("Untra");
    // Trigger the sensor
    digitalWrite(Trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);

    // Measure the duration of the pulse
    duration = pulseIn(Echo, HIGH);
    delay(100);
    
    // Calculate distance based on the duration
    distance = duration * 0.034 / 2;
    Serial.println(distance);
    // Check if the current distance matches the previous distance
    if (distance == prevDistance && distance <= 35) {
      // Increment consecutive detections counter
      consecutiveDetections++;
    } else {
      // Reset consecutive detections counter if the distance changes
      consecutiveDetections = 0;
    }

    // Store the current distance as the previous distance for the next iteration
    prevDistance = distance;
  }

  // Once three consecutive detections are made, perform actions
  // Perform actions
  forward();
  startTime = millis();
  while (millis() - startTime < 1000) {
    continue; 
  }
  
  // Move gripper
  moveGripper(58);
  
  // Turn left
  spinLeft();
  startTime = millis();
  while (millis() - startTime < 450) {
    continue; 
  }
  stopMoving();
  lineMaze = true;
}
