
// ===============================
// ========== CONFIG =============
// ===============================

// --------- MOTEUR GAUCHE ---------
int MOTOR_LEFT_IN1  = 25;   // Direction moteur gauche
int MOTOR_LEFT_IN2  = 26;   // Direction moteur gauche
int MOTOR_LEFT_PWM  = 27;   // Vitesse (PWM)

// --------- MOTEUR DROIT ----------
int MOTOR_RIGHT_IN1 = 14;   // Direction moteur droit
int MOTOR_RIGHT_IN2 = 12;   // Direction moteur droit
int MOTOR_RIGHT_PWM = 13;   // Vitesse (PWM)

// --------- CONFIG PWM ESP32 ------
int PWM_FREQUENCY = 1000;  // Fréquence PWM
int PWM_RESOLUTION = 8;    // Résolution (0–255)
int PWM_CHANNEL_LEFT  = 0;
int PWM_CHANNEL_RIGHT = 1;

// ===============================
// ======= CLASSE MOTEUR =========
// ===============================

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

// ===============================
// ====== OBJETS MOTEURS =========
// ===============================

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

// ===============================
// ===== FONCTIONS ROBOT =========
// ===============================

// Avancer tout droit
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

// ===============================
// ========== SETUP ==============
// ===============================

void setup() {
  Serial.begin(115200);

  // Initialisation des moteurs
  leftMotor.begin();
  rightMotor.begin();

  Serial.println("Robot prêt !");
}

// ===============================
// ========== LOOP ===============
// ===============================

void loop() {

  // Séquence de déplacement initiale (exemple)
  moveForward(150);   // Avance à vitesse moyenne
  delay(2000);

  turnLeft(150);      // Tourne à gauche
  delay(1000);

  moveForward(150);   // Avance
  delay(2000);

  stopRobot();        // Stop
  delay(3000);
}
