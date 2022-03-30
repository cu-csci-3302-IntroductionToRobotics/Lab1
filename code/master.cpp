#include "master.h"

master::master(){
    // attach to robot interface
    robot.reset(new RobotInterface);
}

void master::Run(){
    // replace the code in this function with your own code
    // here is a dummy example of driving the robot forward

    double speed = 1.5; // [rad/s]

    robot->SetLeftMotorSpeed(speed);
    robot->SetRightMotorSpeed(speed);

    vector<double> dist;

    // continue simulating until StepSim() returns -1 (the simulator stop condition)
    while (robot->StepSim() != -1) {
        robot->getProximitySensors(dist);
        for(int ii=0;ii<dist.size();ii++){
            cout << dist.at(ii) << ',';
        }
        cout << endl;
    }
}