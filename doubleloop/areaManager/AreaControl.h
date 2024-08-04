#include "util.h"
#include "Area.h"
#include <vector>

class AreaControl
{
private:
    static int8_t edge_;
    static std::vector<Area> area_;
    static uint8_t current_;
    static bool isExited_;

public:
    static void addArea(int edge, int endColor);
    static void run();
    static bool isExited();
};