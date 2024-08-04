#include "MotorControl.h"

MotorControl::MotorControl(ePortM port)
{
    msg_f("モータコントロール インスタンス生成", 1);
    motor_ = new Motor(port);
}

void MotorControl::setPWM(int pwm) { motor_->setPWM(pwm); }

int MotorControl::getPWM() { return 0;}

void MotorControl::stop()
{
    motor_->stop();
}

int MotorControl::getCount()
{
    return motor_->getCount();
}