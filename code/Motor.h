#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
  private:
    int in1;
    int in2;
    int pwm;
    int pwmChannel;

  public:
    Motor(int pin1, int pin2, int pinPWM);

    void begin();
    void forward(int speed);
    void backward(int speed);
    void stop();
};

#endif

