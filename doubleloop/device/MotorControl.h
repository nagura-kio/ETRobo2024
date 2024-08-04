#pragma once
#include "Motor.h"
#include "util.h"

using namespace ev3api;

class MotorControl
{
public:
    MotorControl(ePortM port);
    void setPWM(int pwm);
    void stop();
    int getPWM();
    int getCount();
private:
    Motor* motor_;
};