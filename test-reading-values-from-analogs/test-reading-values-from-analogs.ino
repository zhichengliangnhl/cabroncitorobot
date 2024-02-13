const int sensorPins[] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  for (int i = 0; i < 8; i++) {
    Serial.print("Value: ");
    Serial.println(analogRead(sensorPins[i])); // Set sensor pins as inputs
  }

  delay(1000); 
}
