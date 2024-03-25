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
  Serial.println("Nice!");
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
