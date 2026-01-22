// =============================
// Obstacle Avoiding Robot Code
// Arduino + HC-SR04 + L298N
// =============================

long duration;
int distance;

// Motor Driver Pins
int ENA = 6;
int IN1 = 7;
int IN2 = 8;

int ENB = 11;
int IN3 = 12;
int IN4 = 13;

// LED Pins
int leftLED = 3;
int rightLED = 5;

void setup() {
  // Ultrasonic pins
  pinMode(9, OUTPUT);   // TRIG
  pinMode(10, INPUT);  // ECHO

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // LEDs
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  Serial.begin(9600);
}

// Function to move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);

  digitalWrite(leftLED, HIGH);
  digitalWrite(rightLED, HIGH);
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, HIGH);

  analogWrite(ENA, 160);
  analogWrite(ENB, 160);
}

void loop() {
  // Ultrasonic Trigger
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);

  // Read Echo
  duration = pulseIn(10, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance < 15) {
    turnRight();
    delay(300);
  } else {
    forward();
  }

  delay(100);
}
