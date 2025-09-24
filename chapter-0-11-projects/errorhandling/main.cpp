#include "funcheads.h"
#include <iostream>

int main()
{
    double x{userInput()};
    double y{userInput()};
    char ch{getOperator()};

    while(y == 0 && ch == '/')
    {
        std::cout << "Sorry division with zero is not supported :( \n";
        y = userInput();

    }
    printResult(x,ch,y);
    return 0;
}