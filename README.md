# 🚗 Obstacle-Aware Robot (Arduino + Ultrasonic Sensor)

An **obstacle-avoiding robot simulation** built using **Arduino Uno**, **HC-SR04 Ultrasonic Sensor**, **L298N Motor Driver**, DC gear motors, and LEDs.

This project demonstrates how a robot can detect obstacles and automatically change direction to avoid collisions.

---

## 📘 Project Overview

**Behavior logic:**

- If an object is detected **closer than 15 cm** → Robot turns right
- Otherwise → Robot moves forward

This project is designed for **simulation only** (no physical components required).

---

## 🧰 Components Used

- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- L298N Motor Driver
- 2 DC Gear Motors
- 2 LEDs
- 2 × 220Ω resistors
- Breadboard
- Jumper wires
- External power supply (7–12V)

---

## 🔌 Circuit Connections

### Ultrasonic Sensor (HC-SR04)

| HC-SR04 Pin | Arduino Pin    |
| ----------- | -------------- |
| VCC         | 5V             |
| GND         | GND            |
| TRIG        | Digital Pin 9  |
| ECHO        | Digital Pin 10 |

---

### LEDs (Motor Indicators)

**Left LED (Motor A):**

- (+) → 220Ω resistor → Arduino Pin 3
- (–) → GND

**Right LED (Motor B):**

- (+) → 220Ω resistor → Arduino Pin 5
- (–) → GND

---

### L298N Motor Driver Connections

**Motor Outputs**

- OUT1 & OUT2 → Motor A
- OUT3 & OUT4 → Motor B

**Control Pins**

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| ENA       | 6           |
| IN1       | 7           |
| IN2       | 8           |
| ENB       | 11          |
| IN3       | 12          |
| IN4       | 13          |

---

## ⚙️ How It Works

1. Ultrasonic sensor measures distance
2. Arduino processes the distance value
3. Robot decides movement:
   - Turn right if obstacle detected
   - Move forward otherwise
4. LEDs indicate motor activity

---

## 💻 Arduino Code

```cpp
long duration;
int distance;

int ENA = 6;
int IN1 = 7;
int IN2 = 8;

int ENB = 11;
int IN3 = 12;
int IN4 = 13;

int leftLED = 3;
int rightLED = 5;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  Serial.begin(9600);
}

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

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 160);
  analogWrite(ENB, 160);

  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, HIGH);
}

void loop() {
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);

  duration = pulseIn(10, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 15) {
    turnRight();
    delay(300);
  } else {
    forward();
  }

  delay(100);
}
```

---

## 🧪 Simulation Platform

- [https://app.cirkitdesigner.com/](https://app.cirkitdesigner.com/project/cc1bcf29-9763-441a-80d4-aea258119a0c)

---

