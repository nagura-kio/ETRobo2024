#include "Detection.h"

Detection::Detection():
leftWheel_(PORT_C), rightWheel_(PORT_B), colorsensor_(PORT_2){
}

rgb_raw_t Detection::getColor()
{
    return rgb_;
}

void Detection::detectColor()
{
    rgb_raw_t rgb;
    //colorsensor_.getRawColor(rgb);
    rgb_ = rgb;
    printf("[rgb] %d, %d, %d\n", rgb.r, rgb.g, rgb.b);
}

int Detection::getKyori()
{
    return kyori_;
}

void Detection::detectKyori()
{
    kyori_ = 100;
}