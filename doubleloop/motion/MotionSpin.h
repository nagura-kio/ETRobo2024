#include "util.h"
#include "Color.h"
#include "Motion.h"

class MotionSpin : public Motion {
public:
    MotionSpin();
    int setAngle() override;
    int setSpeed() override;
};