const int gripperPin = 2; // Assuming gripper control pin

void moveGripper(int angle); // Function prototype declaration
void dropGripper(); // Function prototype declaration

void setup() {
  pinMode(gripperPin, OUTPUT);
}

void loop() { 
    moveGripper(55);
    // Perform other actions here
    // After completing the action, call dropGripper
//    dropGripper();
    // Add delay or other actions as needed
    delay(1000);
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
}
