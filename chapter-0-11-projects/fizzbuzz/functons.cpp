#include "heads.h"
#include <iostream>

//TO get input from the user
int userInput()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

//To print numbers upto range given and replace numbers which are divisble by 2, 5 and 7;

void fizzbuzz(int range)
{
    bool tracker{0};

    for(int i{1}; i <= range; i++)
    {
        if (i % 3 == 0)
        {
            std::cout << "Fizz";
            tracker = 1;
        }
        if (i % 5 == 0)
        {
            std::cout << "Buzz";
            tracker = 1;
        }
        if (i % 7 == 0)
        {
            std::cout << "Pop";
            tracker = 1;
        }
        if (!tracker)
            std::cout << i;
        else
            std::cout << " ( " << i << " ) ";
        tracker = 0;
        std::cout << '\n';
    }    
    std::cout << '\n';
    
}