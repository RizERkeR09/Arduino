// Motor Pins (Connect to L298N)
#define ENA 9   // Enable pin for Motor A
#define IN1 8   // Input 1 for Motor A
#define IN2 7   // Input 2 for Motor A
#define ENB 10  // Enable pin for Motor B
#define IN3 6   // Input 3 for Motor B
#define IN4 5   // Input 4 for Motor B

// IR Sensor Pins
#define IR_LEFT A0  // Left IR sensor
#define IR_RIGHT A1 // Right IR sensor

// Speed Settings
#define SPEED 90 // Speed for motors (0-255)

void setup() {
  // Motor Pins as Output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // IR Sensor Pins as Input
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  // Initial Motor States
  stopMotors();
}

void loop() {
  // Read IR sensor values
  int leftSensor = digitalRead(IR_LEFT);
  int rightSensor = digitalRead(IR_RIGHT);

  // Control logic for line following
  if (leftSensor == LOW && rightSensor == LOW) {
    // Both sensors detect black (on the line)
    moveForward();
    delay(20);
    stopMotors();
    delay(20);

    
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Left sensor detects white (off the line), right sensor detects black (on the line)
    turnLeft();
    
    

  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Left sensor detects black (on the line), right sensor detects white (off the line)
    turnRight();
    

  } else {
    // Both sensors detect white (off the line)
    stopMotors();
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

// Function to turn left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

// Function to stop all motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
