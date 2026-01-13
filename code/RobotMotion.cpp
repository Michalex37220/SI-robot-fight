#include "RobotMotion.h"
#include "Motor.h"
#include "Config.h"

// Création des moteurs
Motor leftMotor(
  MOTOR_LEFT_IN1,
  MOTOR_LEFT_IN2,
  MOTOR_LEFT_PWM,
  PWM_CHANNEL_LEFT
);

Motor rightMotor(
  MOTOR_RIGHT_IN1,
  MOTOR_RIGHT_IN2,
  MOTOR_RIGHT_PWM,
  PWM_CHANNEL_RIGHT
);

// Initialisation du robot
void initRobot() {
  leftMotor.begin();
  rightMotor.begin();
}

// Avancer
void moveForward(int speed) {
  leftMotor.forward(speed);
  rightMotor.forward(speed);
}

// Reculer
void moveBackward(int speed) {
  leftMotor.backward(speed);
  rightMotor.backward(speed);
}

// Tourner à gauche
void turnLeft(int speed) {
  leftMotor.stop();
  rightMotor.forward(speed);
}

// Tourner à droite
void turnRight(int speed) {
  leftMotor.forward(speed);
  rightMotor.stop();
}

// Arrêt total
void stopRobot() {
  leftMotor.stop();
  rightMotor.stop();
}

