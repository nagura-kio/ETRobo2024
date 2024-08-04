#include "MotorControl.h"
#include "ColorSensorControl.h"
#include "util.h"

using namespace ev3api;
using namespace std;

class Detection {
public:
    Detection();
    rgb_raw_t getColor();
    void detectColor();
    int getKyori();
    void detectKyori();
private:
    MotorControl leftWheel_;
    MotorControl rightWheel_;
    ColorSensorControl colorsensor_;
    //Clock clock;
    rgb_raw_t rgb_;
    int kyori_;
};