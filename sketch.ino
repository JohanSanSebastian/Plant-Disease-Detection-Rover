// =======================================
// Plant Disease Detection Rover
// Made by: Zaid, Shriram, Abhinav, Johan
// =======================================

// ---------- LEFT DRIVER (healthy) ----------
#define L_IN1 2   // Front-Left
#define L_IN2 3
#define L_IN3 8   // Rear-Left
#define L_IN4 9

// ---------- RIGHT DRIVER (single channel) ----------
#define R_IN1 5   // Front-Right + Rear-Right
#define R_IN2 6

// ---------- LOW-LEVEL HELPERS ----------

void stopMotors() {
  // Left side
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, LOW);
  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, LOW);

  // Right side
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, LOW);
}

void leftForward() {
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  digitalWrite(L_IN3, HIGH);
  digitalWrite(L_IN4, LOW);
}

void leftBackward() {
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, HIGH);
  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, HIGH);
}

void rightForward() {
  digitalWrite(R_IN1, HIGH);
  digitalWrite(R_IN2, LOW);
}

void rightBackward() {
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, HIGH);
}

// ---------- HIGH-LEVEL MOTIONS ----------

void moveForward(unsigned long ms) {
  leftForward();
  rightForward();
  delay(ms);
  stopMotors();
}

void moveBackward(unsigned long ms) {
  leftBackward();
  rightBackward();
  delay(ms);
  stopMotors();
}

void turnLeft(unsigned long ms) {
  leftBackward();
  rightForward();
  delay(ms);
  stopMotors();
}

void turnRight(unsigned long ms) {
  leftForward();
  rightBackward();
  delay(ms);
  stopMotors();
}

// ---------- SETUP & LOOP ----------

void setup() {
  pinMode(L_IN1, OUTPUT);
  pinMode(L_IN2, OUTPUT);
  pinMode(L_IN3, OUTPUT);
  pinMode(L_IN4, OUTPUT);

  pinMode(R_IN1, OUTPUT);
  pinMode(R_IN2, OUTPUT);

  stopMotors();
}

void loop() {

moveBackward(3000);
  delay(1000);
  
  moveForward(2000);
  delay(1000);

  turnLeft(4000);
  delay(500);

  turnRight(6000);
  delay(500);

  moveBackward(5000);
  delay(2000);
}
