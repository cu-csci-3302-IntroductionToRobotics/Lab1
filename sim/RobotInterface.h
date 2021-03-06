#ifndef ROBOTINTERFACE_H__
#define ROBOTINTERFACE_H__

#include <iostream>
#include <webots/Camera.hpp>
#include <webots/Motor.hpp>
#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <memory>

using namespace webots;
using namespace std;

class RobotInterface : public Supervisor {
public:
  RobotInterface() {
    //create supervisor and get the robot node
    robot_node = getFromDef("MY_ROBOT");

    timeStep = (int)getBasicTimeStep(); // set the control time step
    // get device tags from webots
    left_wheel.reset(getMotor("left wheel motor"));
    right_wheel.reset(getMotor("right wheel motor"));

    for(int ii=0;ii<8;ii++){
      distsen.push_back(getDistanceSensor("ps"+to_string(ii)));
      distsen.at(ii)->enable(timeStep);
    }
  }

  void SetLeftMotorSpeed(double speed){
    left_wheel->setPosition(INFINITY);
    left_wheel->setVelocity(speed);
  }

  void SetRightMotorSpeed(double speed){
    right_wheel->setPosition(INFINITY);
    right_wheel->setVelocity(speed);
  }

  void GetPosition(){

  }

  void getProximitySensors(vector<double>& values){
    if(values.size()!=distsen.size()){
      values.resize(distsen.size());
    }
    for(int ii=0;ii<distsen.size();ii++){
      values.at(ii) = distsen.at(ii)->getValue();
    }
  }

  int StepSim() {
    return step(timeStep);
  }

private:
  int timeStep;
  shared_ptr<Motor> left_wheel;
  shared_ptr<Motor> right_wheel;
  Node* robot_node;
  vector<DistanceSensor*> distsen;
};

#endif // ROBOTINTERFACE_H__