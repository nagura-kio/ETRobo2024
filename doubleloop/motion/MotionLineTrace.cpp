#include "MotionLineTrace.h"

MotionLineTrace::MotionLineTrace(){}

int MotionLineTrace::setSpeed()
{
    return 0;
}

int MotionLineTrace::setAngle()
{
    return pid(100, 100);
}

int MotionLineTrace::pid(int feedback_val, int target_val)
{

    float p, i, d;

    error[0] = error[1];
    error[1] = feedback_val - target_val;
    integral += (error[1] + error[0]) / 2.0 * 2;

    p = kp_ * error[1];
    i = ki_ * integral;
    d = kd_ * (error[1] - error[0])/2;

    return (p + i + d);

}