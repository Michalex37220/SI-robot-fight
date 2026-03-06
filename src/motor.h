class Motor {
  private:
    int in1;
    int in2;
    int pwm;
    int pwmChannel;

  public:
    // Constructeur
    Motor(int pin1, int pin2, int pinPWM, int channel) {
      in1 = pin1;
      in2 = pin2;
      pwm = pinPWM;
      pwmChannel = channel;
    }

    // Initialisation du moteur
    void begin() {
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);

      // Configuration PWM ESP32
      ledcSetup(pwmChannel, PWM_FREQUENCY, PWM_RESOLUTION);
      ledcAttachPin(pwm, pwmChannel);

      stop();
    }

    // Faire tourner le moteur en avant
    void forward(int speed) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      ledcWrite(pwmChannel, speed);
    }

    // Faire tourner le moteur en arrière
    void backward(int speed) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      ledcWrite(pwmChannel, speed);
    }

    // Arrêter le moteur
    void stop() {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      ledcWrite(pwmChannel, 0);
    }
};


