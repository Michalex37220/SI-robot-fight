#include "Motor.h"

// Constructeur
Motor::Motor(int pin1, int pin2, int pinPWM) {
  in1 = pin1;
  in2 = pin2;
  pwm = pinPWM;
}

// Initialisation du moteur
void Motor::begin() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // API PWM ESP32-C6 (Arduino core >= 3.x)
  ledcAttach(pwm, 1000, 8); // pin, fréquence, résolution

  stop();
}

// Marche avant
void Motor::forward(int speed) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  ledcWrite(pwm, speed);
}

// Marche arrière
void Motor::backward(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  ledcWrite(pwm, speed);
}

// Arrêt
void Motor::stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  ledcWrite(pwm, 0);
}

