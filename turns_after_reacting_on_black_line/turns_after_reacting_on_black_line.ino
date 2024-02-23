int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards

float speedParamA1 = 130.0;
float speedParamA2 = 3.0;
float speedParamB1 = 0.0;
float speedParamB2 = 254.0;


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
  for (int i = 0; i <= 6; i++) {
    Serial.println(" ");
  }
  for (int i = 0; i <= 7; i++) {
    Serial.print("Value "+String(i)+" : ");
    Serial.println(analogRead(sensorPins[i])); // Set sensor pins as inputs
  }
if (analogRead(sensorPins[1]) > 700 && analogRead(sensorPins[2]) > 700 && analogRead(sensorPins[3]) < 700 && analogRead(sensorPins[0]) < 700 && analogRead(sensorPins[4]) < 700 && analogRead(sensorPins[5]) < 700 && analogRead(sensorPins[6]) < 700 && analogRead(sensorPins[7]) < 700) {
  Serial.println("Time to readjust to the right");
//  moveSlightlyRight ();
}
else if (analogRead(sensorPins[4]) < 700 && analogRead(sensorPins[5]) > 700 && analogRead(sensorPins[6]) > 700 && analogRead(sensorPins[0]) < 700 && analogRead(sensorPins[1]) < 700 && analogRead(sensorPins[2]) < 700 && analogRead(sensorPins[3]) < 700 && analogRead(sensorPins[7]) < 700) {
  Serial.println("Time to readjust to the left");
//  moveSlightlyLeft ();
} 
//if (analogRead(sensorPins[7]) > 750) {
//  stopAndTurnLeft();;
//} 
//else {
//  forward ();
//}
  delay(500); 
}

void stopAndTurnLeft() {
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);

  delay(500);
  // Turn left
  analogWrite(Motor_A1, 3.0);
  analogWrite(Motor_A2, 130.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 254.0);
  
  // Delay to complete the turn
  delay(800);
 
  forward ();
  
  delay(10);
}

void forward () {
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
}

void moveSlightlyLeft () {
  analogWrite(Motor_A1, 145.0);
  analogWrite(Motor_A2, 3.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 254.0);
}

void moveSlightlyRight () {
  analogWrite(Motor_A1, 130.0);
  analogWrite(Motor_A2, 6.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 254.0);
}
