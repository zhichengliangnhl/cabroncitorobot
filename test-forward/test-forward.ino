int Motor_A1 = 10;   // Left wheel, goes forward
int Motor_A2 = 6;   // Left wheel, goes backward
int Motor_B1 = 9;   // Right wheel, goes backward
int Motor_B2 = 5;   // Right wheel, goes forward
//you need to connect R1 and R2 rotation sensor pins with digital io pins
void setup() {
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);

}

void loop() {
  forward();  
}

void forward() {
  analogWrite(Motor_A1, 208);
  analogWrite(Motor_A2, 0);
  analogWrite(Motor_B1, 0);
  analogWrite(Motor_B2, 214);
}
