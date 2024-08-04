#pragma once
#include "ColorSensor.h"
#include "util.h"

using namespace ev3api;

class ColorSensorControl
{
public:
    ColorSensorControl(ePortS port);
    ~ColorSensorControl();
    rgb_raw_t getRawColor();
private:
    ColorSensor* colorSensor_;
};