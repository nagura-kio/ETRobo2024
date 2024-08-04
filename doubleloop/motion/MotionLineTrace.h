#include "util.h"
#include "Motion.h"
#include "Color.h"

class MotionLineTrace : public Motion
{
public:
    MotionLineTrace();
    int setSpeed() override;
    int setAngle() override;

private:
    int pid(int feedback_val, int target_val);
    int error[2];
    int integral;
    float kp_;
    float ki_;
    float kd_;
};