#include "AreaControl.h"

uint8_t AreaControl::current_ = 0;
bool AreaControl::isExited_ = false;
std::vector<Area> AreaControl::area_;

void AreaControl::addArea(int edge, int endColor)
{
    area_.push_back(Area(edge, endColor));
}

void AreaControl::run()
{
    if (isExited_ || current_ > area_.size())
    {
        isExited_ = true;
        return;
    }
    area_[current_].run();
    if (area_[current_].isFinished())
    {
        current_++;
    }
}

bool AreaControl::isExited()
{
    return isExited_;
}
