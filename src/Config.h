#ifndef CONFIG_H
#define CONFIG_H

// ===============================
// ========== MOTEURS ============
// ===============================

// Moteur gauche
#define MOTOR_LEFT_IN1   25
#define MOTOR_LEFT_IN2   26
#define MOTOR_LEFT_PWM   27

// Moteur droit
#define MOTOR_RIGHT_IN1  14
#define MOTOR_RIGHT_IN2  12
#define MOTOR_RIGHT_PWM  13

// ===============================
// ========= PWM ESP32 ===========
// ===============================

#define PWM_FREQUENCY   1000
#define PWM_RESOLUTION  8

#define PWM_CHANNEL_LEFT   0
#define PWM_CHANNEL_RIGHT  1

#endif

