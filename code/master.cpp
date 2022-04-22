#include "master.h"

master::master(){
    // attach to robot interface
    robot.reset(new RobotInterface);
}

void master::Run(){
    // replace the code in this function with your own code
    // here is a dummy example of driving the robot forward

    double speed = 1.5; // [rad/s]

    // this is how you set speed of each motor
    robot->SetLeftMotorSpeed(speed);
    robot->SetRightMotorSpeed(speed);

    vector<double> dist;

    // continue simulating until StepSim() returns -1 (the simulator stop condition)
    while (robot->StepSim() != -1) {
        // print proximity sensor values while driving forward
        robot->getProximitySensors(dist);
        for(int ii=0;ii<dist.size();ii++){
            cout << dist.at(ii) << ',';
        }
        cout << endl;
    }

    // Remove the dummy code above and add your own code bellow
    // you want to create a state machine which would define your
    // robot's behaviour
    
}