#include "Motion.h"

Motion::Motion(){}

MotorControl Motion::rightmotorControl_(PORT_B);
MotorControl Motion::leftmotorControl_(PORT_C);

void Motion::run()
{
    speed_ = setSpeed();
    angle_ = setAngle();
    printf("drive %d, %d\n", speed_ + angle_, speed_ - angle_);
    //Motion::drive(speed_ + angle_, speed_ - angle_);
    Motion::drive(30, 0);
}

void Motion::drive(int8_t rightPwm, int8_t leftPwm)
{
    printf("setPWM");
    rightmotorControl_.setPWM(rightPwm);
    leftmotorControl_.setPWM(leftPwm);
}