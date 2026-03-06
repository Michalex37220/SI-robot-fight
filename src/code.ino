// code main qui importe le tout et le gère
#include "Config.h"
#include "Motor.h"
#include "RobotMotion.h"

void setup() {
  Serial.begin(115200);

  // Initialisation du robot
  initRobot();

  Serial.println("Robot ESP32 prêt !");
}

void loop() {

  // Déplacements initiaux (exemple)
  moveForward(150);
  delay(2000);

  turnLeft(150);
  delay(1000);

  moveForward(150);
  delay(2000);

  stopRobot();
  delay(3000);
}

