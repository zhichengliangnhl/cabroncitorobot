int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};

void setup() {
   for (int i = 0; i <= 7; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  Serial.println("===============");
  for (int i = 0; i <= 7; i++) {
    Serial.println("Value "+String(i)+" : ");
    Serial.println(analogRead(sensorPins[i])); // Set sensor pins as inputs
  }
  Serial.println("===============");
  delay(5000); 
}
