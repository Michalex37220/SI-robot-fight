#ifndef ROBOT_MOTION_H
#define ROBOT_MOTION_H

void initRobot();

void moveForward(int speed);
void moveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stopRobot();

#endif

