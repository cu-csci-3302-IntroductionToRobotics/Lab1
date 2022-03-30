#ifndef ROBOTINTERFACE_H__
#define ROBOTINTERFACE_H__

#include <webots/Camera.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>
#include <memory>

using namespace webots;
using namespace std;

class RobotInterface : public Robot {
public:
  RobotInterface() {
    timeStep = (int)getBasicTimeStep(); // set the control time step
    // get device tags from webots
    left_wheel.reset(getMotor("left wheel motor"));
    right_wheel.reset(getMotor("right wheel motor"));
  }

  void SetLeftMotorSpeed(double speed){
    left_wheel->setPosition(INFINITY);
    left_wheel->setVelocity(speed);
  }

  void SetRightMotorSpeed(double speed){
    right_wheel->setPosition(INFINITY);
    right_wheel->setVelocity(speed);
  }

  int StepSim() {
    return step(timeStep);
  }

private:
  int timeStep;
  shared_ptr<Motor> left_wheel;
  shared_ptr<Motor> right_wheel;
};

#endif // ROBOTINTERFACE_H__