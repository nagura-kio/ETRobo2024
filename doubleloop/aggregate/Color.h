#pragma once
#include "util.h"
#include "ColorSensorControl.h"

using namespace ev3api;

class Color
{
private:
    static int r_;
    static int g_;
    static int b_;
    static ColorSensorControl colorSensorControl_;
public:
    enum E_RGB {
        RED,
        GREEN,
        BLUE,
    };
    static int getColor(E_RGB rgb);
    static void setColor();
};