#include "Angle.h"

int8_t Angle::angle_ = 0;
MotorControl Angle::rightmotorControl_(PORT_B);
MotorControl Angle::leftmotorControl_(PORT_C);

int8_t Angle::getAngle()
{
    return angle_;
}

void Angle::aggregateAngle()
{
    angle_ = rightmotorControl_.getCount() + leftmotorControl_.getCount();
    printf("[angle] %d, %d\n", rightmotorControl_.getCount(), leftmotorControl_.getCount());
}