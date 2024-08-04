#include "ColorSensorControl.h"

ColorSensorControl::ColorSensorControl(ePortS port)
{
    msg_f("カラーセンサーコントロール インスタンス生成", 1);
    colorSensor_ = new ColorSensor(port);
}

ColorSensorControl::~ColorSensorControl()
{
    msg_f("カラーセンサーコントロール インスタンス破棄", 1);
}

rgb_raw_t ColorSensorControl::getRawColor()
{
    rgb_raw_t rgb;
    colorSensor_->getRawColor(rgb);
    return rgb;
}