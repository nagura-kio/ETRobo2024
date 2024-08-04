#include "util.h"
#include "MotorControl.h"

using namespace ev3api;

class Angle
{
private:
    static int8_t angle_;
    static MotorControl rightmotorControl_;
    static MotorControl leftmotorControl_;

public:
    static int8_t getAngle();
    static void aggregateAngle();
};