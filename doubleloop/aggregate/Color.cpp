#include "Color.h"

ColorSensorControl Color::colorSensorControl_(PORT_2);
int Color::r_ = 0;
int Color::g_ = 0;
int Color::b_ = 0;

int Color::getColor(Color::E_RGB rgb)
{
    int retRgb = -1;
    switch (rgb)
    {
    case Color::RED:
        retRgb = r_;
        break;
    case Color::GREEN:
        retRgb = g_;
        break;
    case Color::BLUE:
        retRgb = b_;
        break;
    default:
        break;
    }
    return retRgb;
}

void Color::setColor()
{
    rgb_raw_t rgb;
    rgb = colorSensorControl_.getRawColor();
    r_ = rgb.r;
    g_ = rgb.g;
    b_ = rgb.b;
    printf("[rgb] %d, %d, %d\n", r_, g_, b_);
}