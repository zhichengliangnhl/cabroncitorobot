int Motor_A1 = 8;  // Left wheel, goes forward
int Motor_A2 = 6;  // Left wheel, goes backward
int Motor_B1 = 7;  // Right wheel, goes backward
int Motor_B2 = 5;  // Right wheel, goes forward
const int encoderPin_R1 = 9;
const int encoderPin_R2 = 10// Connect the DO pin of the encoder to digital pin 2

void loop() {
  int encoderValue = digitalRead(encoderPin);
  Serial.println(encoderValue); // Print the value to the serial monitor
  delay(100); // Adjust delay as needed
}
void setup() {
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);
  pinMode(encoderPin, INPUT);
  pinMode(encoderPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    forward();
    int encoderValue_R1 = digitalRead(encoderPin_R1);
    int encoderValue_R2 = digitalRead(encoderPin_R2);
    Serial.println(encoderValue_R1);
    Serial.println(encoderValue_R2);// Print the value to the serial monitor
    delay(200); // Adjust delay as needed
}

void forward(){
    analogWrite(Motor_A1, 128.2);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 250.2);
  }

void backward() {
    analogWrite(Motor_A1, 220);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 220);

    delay(1000);

    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
  }

void right() {
    analogWrite(Motor_A1, 220);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 220);
    analogWrite(Motor_B2, 0);

    delay(1000);

    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
  }

void left() {
    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 220);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 220);

    delay(1000);

    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
  } 

void stop() {
    analogWrite(Motor_A1, 0);
    analogWrite(Motor_A2, 0);
    analogWrite(Motor_B1, 0);
    analogWrite(Motor_B2, 0);
  }
