int Motor_A1 = 8;
int Motor_A2 = 6;
int Motor_B1 = 7;
int Motor_B2 = 5;

void setup() {
  pinMode(Motor_A1, OUTPUT);
  pinMode(Motor_A2, OUTPUT);
  pinMode(Motor_B1, OUTPUT);
  pinMode(Motor_B2, OUTPUT);
}

void loop() {
  digitalWrite(Motor_A1, HIGH);
  digitalWrite(Motor_A2, HIGH);
  digitalWrite(Motor_B1, LOW);
  digitalWrite(Motor_B2, HIGH);
}
