#include "hilowheads.h"
#include <iostream>

int main()
{
    
    int totalGuess{7};
    constexpr int min     { 1 };
	constexpr int max     { 100 };
    do
    {
        highLow(totalGuess,min,max);
    } while (playAgain());
    
}