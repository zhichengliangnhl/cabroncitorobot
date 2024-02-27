#include <Servo.h>

Servo gripperServo;  // Create a servo object to control the gripper

void setup() {
  gripperServo.attach(2); // Attach the servo to pin 2
}

void loop() {
  moveGripper(90);  // Move gripper to 90 degrees
  delay(1000);
  
  moveGripper(0);   // Move gripper to 0 degrees
  delay(1000);
}

void moveGripper(int angle) {
  gripperServo.write(angle);  // Move the servo to the specified angle
  delay(500);  // Delay to allow the servo to reach the desired position
}
