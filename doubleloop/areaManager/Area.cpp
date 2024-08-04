#include "Area.h"

Area::Area(int edge, int endColor){
  edge_ = edge;
  endColor_ = endColor;
}

void Area::run()
{
  motion_.run();
  isFinished_ = true;
}

bool Area::isFinished()
{
    return isFinished_;
}
