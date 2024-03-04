int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int v[] = {0, 0, 0, 0, 0, 0, 0, 0};
const int Motor_A1 = 8;  // Left wheel, goes backwards
const int Motor_A2 = 6;  // Left wheel, goes forward
const int Motor_B1 = 7;  // Right wheel, goes forward
const int Motor_B2 = 5;  // Right wheel, goes backwards

//So, these are just variables I set for moving forward, so that I instantly see and readjust them, but it's unnecessary 
float speedParamA1 = 133.0;
float speedParamA2 = 119.5;
float speedParamB1 = 127.0;
float speedParamB2 = 131.5;



void setup() {
  //just setup
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
  //I am not sure, but I heard that serial prints can slow down the code, therefore I would remove them all or comment them during the ride tests
  for (int i = 0; i <= 6; i++) {
    Serial.println(" ");
  }
  for (int i = 0; i <= 7; i++) {
    //it prints out the values that each sensor returns
    Serial.print("Value "+String(i)+" : ");
    v[i] = analogRead(sensorPins[i]);
    Serial.println(v[i]);
  }
  if ((v[2] > 700 && v[4] > 700) || ((v[3] < 700 && v[4] < 700) && v[1] > 700)) {
    Serial.println("Time to readjust to the right");
//    Here you should add some function to readjust a bit to the left
  }
  else if ((v[3] > 700 && v[5] > 700) || ((v[3] < 700 && v[4] < 700) && v[6] > 700)) {
    Serial.println("Time to readjust to the left");
//    Here you should add some function to readjust a bit to the left
  } 
  else {
    Serial.println("Continue moving forward");
//    Here you should add some function to readjust a bit to the left
  }
  delay(1); 
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
