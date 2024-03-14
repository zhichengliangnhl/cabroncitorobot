#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(4, 4, NEO_RGB);

int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 10;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 9;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards

const int gripperPin = 2;
void moveGripper(int angle); // Function prototype declaration
void dropGripper(); // Function prototype declaration
bool state = true;

int NeoPixels = 1;

int Echo = 8;
int Trigger = 7;
unsigned long currentTime;

boolean startRace = false;
boolean endRace = false;
boolean onBlack = false;
boolean onWhite = false;

void setup() {

  for (int i = 0; i <= 7; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  strip.begin();
  strip.show();
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);

  pinMode(Echo, INPUT);
  pinMode(Trigger, OUTPUT);

  pinMode(gripperPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
//  for (int i = 0; i <= 7; i++) {
//    v[i] = analogRead(sensorPins[i]);
//  }
//
//  if (v[0] >= 750 && v[1] >= 750 && v[3] >= 750 && v[4] >= 750) {
//    turnRight();
//  } else if (v[7] >= 750 && v[6] >= 750 && v[3] >= 750 && v[4] >= 750) {
//    turnLeft();
//  } else if (v[0] >= 750 || v[1] >= 750 || v[2] >= 750 || v[3] >= 750 || v[4] >= 750 || v[5] >= 750 || v[6] >= 750 || v[7] >= 750) {
//    goForward();
//  } else {
//    turnAround();
//  }

//    if (lookMaybeStart) {
//        // If something is detected, perform the sequence of actions
//        goForward(); // Move forward
//        moveGripper(55); // Move the gripper
//        delay(100); // Wait for a short duration (adjust as needed)
//        turnLeft(); // Turn left
//    } else {
//        // If nothing is detected, drop the gripper and stop
//        dropGripper(); // Drop the gripper
//        Stop(); // Stop the robot
//    }

//    if (startRace) {
//        // Start the race logic
//        goForward();
//        moveGripper(55);
//        delay(100);
//        turnLeft();
//        goForward();
//
//        while (!endRace) {
//            // Check for T-like intersections
//            if (isItBlack()) {
//                moveSlightlyForward();
//                Stop();
//                // If at a T-intersection, check for additional black readings
//            } else if() {
//                    // If more than 2 black readings, drop the gripper
//                    turnAround();
//                } else {
//                    // Otherwise, prioritize turning right
//                    turnRight();
//                }
//            } else {
//                // If not at a T-intersection, continue forward
//                goForward();
//            }
//            // Delay to control speed
//            delay(100); // Adjust delay as needed
//        }
//        // If the race has ended, stop the robot
//        Stop();
//    } else {
//        // If the race hasn't started yet, check for the start signal
//        if (lookMaybeStart()) {
//            // If the start signal is detected, mark the race as started
//            raceHasStarted();
//        }
//    }

//    analogWrite(Motor_A1, 0);// Left wheel, goes forward
//    analogWrite(Motor_A2, 202);// Left wheel, goes backward
//    analogWrite(Motor_B1, 0);//Right wheel, goes backward
//    analogWrite(Motor_B2, 192);// Right wheel, goes forward
//    Serial.println("wheel");
//
//    delay(1000)

      goForward();
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

void goForward()
{
  setStrip("F");
  if (v[2] >= 750 || v[1] >= 750) {
    moveSlightlyRight();
  } else if (v[5] >= 750 || v[6] >= 750) {
    moveSlightlyLeft();
  } else if (v[7] >= 750) {
    moveBigLeft();
  } else if (v[0] >= 750) {
    moveBigRight();
  } else {
    analogWrite(Motor_A1, 175);// Left wheel, goes forward
    analogWrite(Motor_A2, 0);// Left wheel, goes backward
    analogWrite(Motor_B1, 0);//Right wheel, goes backward
    analogWrite(Motor_B2, 184);// Right wheel, goes forward
  }
}

void moveSlightlyForward() {
  setStrip("F");
    analogWrite(Motor_A1, 165);// Left wheel, goes forward
    analogWrite(Motor_A2, 0);// Left wheel, goes backward
    analogWrite(Motor_B1, 0);//Right wheel, goes backward
    analogWrite(Motor_B2, 174);// Right wheel, goes forward
  Stop();
  if (onBlack) {
    return;
  }
  else {
    turnRight();  
  }
}

void turnRight()
{
  setStrip("R");
  analogWrite(Motor_A1, 190);// Left wheel, goes forward
  analogWrite(Motor_A2, 0);// Left wheel, goes backward
  analogWrite(Motor_B1, 188);//Right wheel, goes backward
  analogWrite(Motor_B2, 0);// Right wheel, goes forward

  delay(500);

  analogWrite(Motor_A1, 150);// Left wheel, goes backwards
  analogWrite(Motor_A2, 0);// Left wheel, goes forward
  analogWrite(Motor_B1, 150);//Right wheel, goes forward
  analogWrite(Motor_B2, 0);// Right wheel, goes backwards

  delay(100);

  analogWrite(Motor_A1, 0);// Left wheel, goes backwards
  analogWrite(Motor_A2, 0);// Left wheel, goes forward
  analogWrite(Motor_B1, 0);//Right wheel, goes forward
  analogWrite(Motor_B2, 0);// Right wheel, goes backwards
}

void moveSlightlyRight()
{
  setStrip("R");
  analogWrite(Motor_A1, 155);// Left wheel, goes forward
  analogWrite(Motor_A2, 0);// Left wheel, goes backward
  analogWrite(Motor_B1, 164);//Right wheel, goes backward
  analogWrite(Motor_B2, 0);// Right wheel, goes forward

  delay(100);
}

void moveBigRight() {
  setStrip("R");
  analogWrite(Motor_A1, 185);// Left wheel, goes forward
  analogWrite(Motor_A2, 0);// Left wheel, goes backward
  analogWrite(Motor_B1, 174);//Right wheel, goes backward
  analogWrite(Motor_B2, 0);// Right wheel, goes forward

  delay(100);
}

void turnLeft() {
  setStrip("L");
  analogWrite(Motor_A1, 0);// Left wheel, goes forward
  analogWrite(Motor_A2, 202);// Left wheel, goes backward
  analogWrite(Motor_B1, 0);//Right wheel, goes backward
  analogWrite(Motor_B2, 192);// Right wheel, goes forward

  delay(500);

  analogWrite(Motor_A1, 0);// Left wheel, goes backwards
  analogWrite(Motor_A2, 150);// Left wheel, goes forward
  analogWrite(Motor_B1, 0);//Right wheel, goes forward
  analogWrite(Motor_B2, 150);// Right wheel, goes backwards

  delay(100);

  analogWrite(Motor_A1, 0);// Left wheel, goes backwards
  analogWrite(Motor_A2, 0);// Left wheel, goes forward
  analogWrite(Motor_B1, 0);//Right wheel, goes forward
  analogWrite(Motor_B2, 0);// Right wheel, goes backwards
}

void moveSlightlyLeft()
{
  setStrip("L");
  analogWrite(Motor_A1, 0);// Left wheel, goes forward
  analogWrite(Motor_A2, 155);// Left wheel, goes backward
  analogWrite(Motor_B1, 0);//Right wheel, goes backward
  analogWrite(Motor_B2, 164);// Right wheel, goes forward

  delay(100); 
}

void moveBigLeft() {
  setStrip("L");
  analogWrite(Motor_A1, 0);// Left wheel, goes forward
  analogWrite(Motor_A2, 185);// Left wheel, goes backward
  analogWrite(Motor_B1, 0);//Right wheel, goes backward
  analogWrite(Motor_B2, 174);// Right wheel, goes forward
}

void goBackwards()
{
  setStrip("B");
  analogWrite(Motor_A1, 0);// Left wheel, goes forward
  analogWrite(Motor_A2, 182);// Left wheel, goes backward
  analogWrite(Motor_B1, 164);//Right wheel, goes backward
  analogWrite(Motor_B2, 0);// Right wheel, goes forward
}

void Stop() {
  analogWrite(Motor_A1, 0);// Left wheel, goes forward
  analogWrite(Motor_A2, 0);// Left wheel, goes backward
  analogWrite(Motor_B1, 0);//Right wheel, goes backward
  analogWrite(Motor_B2, 0);// Right wheel, goes forward
  delay(20);
}

void turnAround()
{
  Stop();
  turnRight();
  isItBlack();
  if (onBlack) return;
  turnLeft();
  isItBlack();
  if (onBlack) return;
  turnLeft();
  isItBlack();
  if (onBlack) return;
  turnLeft();
  while (!onBlack) {
    isItBlack();
    goForward();
  }
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
  int mapAngle = map(140, 0, 180, 544, 2400);
  // You can define the action to drop the gripper here
  // For example, open the gripper fully
  digitalWrite(gripperPin, HIGH); // Activate gripper (open)
  delayMicroseconds(mapAngle); // Delay to keep gripper open for 1 second (adjust as needed)
  digitalWrite(gripperPin, LOW); // Release gripper
  delay(20);
}

void lookMaybeStart() {
  // Declare variables
  long duration;
  bool eyeState = false;
  long distance = 0; // Declare distance variable

  // Perform actions while distance is less than or equal to 22 units
  while (distance <= 22) {
    // Trigger the sensor
    digitalWrite(Trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);
    
    // Measure the duration of the pulse
    duration = pulseIn(Echo, HIGH);
    
    // Calculate distance based on the duration
    distance = duration * 0.034 / 2;

    // Check if distance is less than or equal to 22 units
    if (distance <= 22) {
      // If not already in state, set current time and update state
      if (!eyeState) {
        currentTime = millis() + 1000; // Set current time 1 second in the future
        eyeState = true; // Update state to indicate action initiated
      }

      // Check if current time exceeds the set time
      if (millis() >= currentTime) {
        // If distance is still less than or equal to 22 units, return from the function
        if (distance <= 22) {
          eyeState = true; // Update eye state
          return;
        }
      }
    }
  }
}

void isItBlack() {
  if (v[0] >= 750 || v[1] >= 750 || v[2] >= 750 || v[3] >= 750 || v[4] >= 750 || v[5] >= 750 || v[6] >= 750 || v[7] >= 750) {
    onBlack = true;
  } else {
    onBlack = false;
  }
}

void raceHasStarted() {
  startRace = true;
}

void raceHasEnded() {
  endRace = true;
}
