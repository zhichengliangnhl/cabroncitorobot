int Echo = 7;
  int Trigger = 8;

void setup() {
  pinMode(Echo, INPUT);
  pinMode(Trigger, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lookMaybeStart();

}

void lookMaybeStart() {
  // Declare variables
  static int consecutiveDetections = 0;
  static boolean eyeState = false;
  long duration;
  long distance = 0; // Declare distance variable
  long prevDistance = 0; // Variable to store the previous distance

  // Loop until three consecutive detections are made
  while (consecutiveDetections < 3) {
    Serial.println("Untra");
    // Trigger the sensor
    digitalWrite(Trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);
    //delay(20);
    // Measure the duration of the pulse
    duration = pulseIn(Echo, HIGH);
    Serial.println(duration);
    // Calculate distance based on the duration
    distance = duration * 0.034 / 2;
    Serial.println(distance);
  }
} 
