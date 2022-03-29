#ifndef MASTER_H__
#define MASTER_H__

#include <iostream>
#include <webots/Camera.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

using namespace webots;
using namespace std;

class master : public Robot {
public:
  master() {
    timeStep = (int)getBasicTimeStep(); // set the control time step

    // get device tags
    left_wheel.reset(getMotor("left wheel motor"));
    right_wheel.reset(getMotor("right wheel motor"));
  }

  void run() {
    double speed = 1.5; // [rad/s]

    left_wheel->setPosition(INFINITY);
    left_wheel->setVelocity(speed);
    right_wheel->setPosition(INFINITY);
    right_wheel->setVelocity(speed);

    // main control loop: perform simulation steps of 32 milliseconds
    // and leave the loop when the simulation is over
    while (step(timeStep) != -1) {
    }
  }

private:
  int timeStep;
  shared_ptr<Motor> left_wheel;
  shared_ptr<Motor> right_wheel;
};

#endif // MASTER_H__