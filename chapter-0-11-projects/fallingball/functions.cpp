#include "heads.h"
#include <iostream>

namespace ballsheight

{
//Functions to get Tower Heght from the user
double towerHeight()
{
    std::cout << "Enter the height of the tower: ";
    double x{};
    std::cin >> x;
    return x;
}

double time()
{
    std::cout << "Enter the time in seconds to check for the height of the ball at x second is: ";
    double x{};
    std::cin >> x;
    return x;
}
//Functions to determine the distance the ball is now with the tower
//here we use the equation s = (u * t) + (a * (t^2)/2)

void distanceFromGround(double towerheight,double seconds)
{
    const double gravity {9.8}; //The value of acceleration due to gravity is always constant
    for(double i{1}; i <= seconds;i++)
    {
        double fallenDistance{gravity * (i * i)/2};
        double ballHeight{ towerheight - fallenDistance};

        if(ballHeight > 0)
            std::cout << "The ball is at the distance '" << ballHeight <<"' from the ground\n";
        else
        {
            std::cout << "The ball is at the ground\n";
            break;
        }
    }
}

}