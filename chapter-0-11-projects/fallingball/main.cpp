#include "heads.h"

int main()
{
    double height{ballsheight::towerHeight()};
    double second{ballsheight::time()};
    ballsheight::distanceFromGround(height,second);
    
    return 0;
}