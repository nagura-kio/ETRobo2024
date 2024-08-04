#include "util.h"
#include "MotionSpin.h"

class Area
{
private:
    int edge_;
    int endColor_;
    int isFinished_;
    MotionSpin motion_;

public:
    Area(int edge, int endColor);
    void run();
    bool isFinished();
};