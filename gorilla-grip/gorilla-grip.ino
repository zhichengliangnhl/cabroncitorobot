int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards

float speedParamA1 = 132.0;
float speedParamA2 = 123.0;
float speedParamB1 = 126.0;
float speedParamB2 = 129.5;

int gripper = 2;

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
  pinMode(gripper, OUTPUT);

  Serial.begin(9600); // Initialize serial communication
}

void loop() {

   for(int i = 0; i < 10; i++) {
    movegripper(180);
    delay(1000);
    movegripper(35);
    delay(1000);
  }
}

void movegripper(int angle) {
  int mapAngle = map(angle, 0 , 180, 544, 2400);

  digitalWrite(gripper, HIGH);
  delayMicroseconds(mapAngle);
  digitalWrite(gripper, LOW);
  delay(20);
  }

for(int i = 0; i < 10; i++) {
  moveGripper(45);
  delay(100)
  if(moveGripper == 45){
    break;
    } else if()
}

void loop() {
  for (int i = 0; i <= 6; i++) {
    Serial.println(" ");
  }
  for (int i = 0; i <= 7; i++) {
    Serial.print("Value "+String(i)+" : ");
    v[i] = analogRead(sensorPins[i]);
    Serial.println(v[i]);
  }
  if (v[7] > 700 || (v[7] > 750 && v[6] > 750 && v[5] > 750 && v[4] > 750) || (v[6] > 750 && v[5] > 750 && v[4] > 750)) {
//    Serial.println("Time to turn left");
    stopAndTurnLeft ();
  }
  else if ((v[2] > 700 && v[4] > 700) || ((v[3] < 700 && v[4] < 700) && v[1] > 700)) {
//    Serial.println("Time to readjust to the right");
    moveSlightlyRight ();
  }
  else if ((v[3] > 700 && v[5] > 700) || ((v[3] < 700 && v[4] < 700) && v[6] > 700)) {
//    Serial.println("Time to readjust to the left");
    moveSlightlyLeft ();
  } 
  else {
//    Serial.println("Continue moving forward");
    forward ();
  }
  delay(500); 
}



void forward () {
  analogWrite(Motor_A1, speedParamA1);
  analogWrite(Motor_A2, speedParamA2);
  analogWrite(Motor_B1, speedParamB1);
  analogWrite(Motor_B2, speedParamB2);
}

void moveSlightlyLeft () {
  analogWrite(Motor_A1, 128.1);
  analogWrite(Motor_A2, 124.9);
  analogWrite(Motor_B1, 126.0);
  analogWrite(Motor_B2, 139.5);
}

void moveSlightlyRight () {
  analogWrite(Motor_A1, 135.0);
  analogWrite(Motor_A2, 110.0);
  analogWrite(Motor_B1, 126.0);
  analogWrite(Motor_B2, 129.5);
}

void stopAndTurnLeft() {
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);

  delay(1000);
  // Turn left
  analogWrite(Motor_A1, 3.0);
  analogWrite(Motor_A2, 130.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 254.0);
  
  // Delay to complete the turn
  delay(550);
  
  analogWrite(Motor_A1, 0.0);
  analogWrite(Motor_A2, 0.0);
  analogWrite(Motor_B1, 0.0);
  analogWrite(Motor_B2, 0.0);

  delay(1000);
}
