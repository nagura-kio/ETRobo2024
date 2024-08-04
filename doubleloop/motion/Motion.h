#include "util.h"
#include "MotorControl.h"

class Motion
{
public:
    Motion();
    void run();

protected:
    virtual int setSpeed() = 0;
    virtual int setAngle() = 0;

private:
    static MotorControl rightmotorControl_;
    static MotorControl leftmotorControl_;
    int angle_;
    int speed_;
    void drive(int8_t rightPwm, int8_t leftPwm);
};