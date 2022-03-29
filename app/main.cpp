#include <iostream>
#include <webots/Camera.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

using namespace webots;
using namespace std;

int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();

  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();

  Motor *wheels[2];
  wheels[0] = robot->getMotor("left wheel motor");
  wheels[1] = robot->getMotor("right wheel motor");
  double speed = 1.5; // [rad/s]
  wheels[0]->setPosition(INFINITY);
  wheels[0]->setVelocity(speed);
  wheels[1]->setPosition(INFINITY);
  wheels[1]->setVelocity(speed);

  float pos = -1;

  while (robot->step(timeStep) != -1) {
    if (pos < 1) {
      pos += 0.01;
    } else {
      pos = -1;
    }
  };

  delete robot;
  return 0;
}