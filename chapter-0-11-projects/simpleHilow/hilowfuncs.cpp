#include "hilowheads.h"
#include <iostream>
#include <random>
#include <limits>
#include <cstdlib>
//Function to get random number
namespace Random{
    int get(int x, int y)
    {
    static std::random_device rd;
    static std::mt19937 mt{rd()};
    static std::uniform_int_distribution res(x,y);
    return res(mt);
    }
}

//This function is to delete the cin buffer 
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//Function to flush the failed cin input and make it reusable again
bool clearFailedExtraction()
{
    if(!std::cin)
    {
        if(std::cin.eof())
        {
            std::exit(0);
        }
        std::cin.clear();
        ignoreLine();
        return true;
    }
    return false;

}

int getUserInput()
{
    
    while(true)
    {
        int input{};
        std::cout << "Enter an Integer number: ";
        std::cin >> input;
        if(clearFailedExtraction())
        {
            std::cout << "Error: invalid input, please try again :) \n";
            continue;
        }
        ignoreLine();
        return input;
    }
}

//Function with the main logic
bool highLow(int guesses,int min, int max)
{
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    
    const int number{Random::get(min,max)};
    for (int i{1}; i <= guesses;i++)
    {
        int input{getUserInput()};
        std::cout << "Guess #"<< i << " : " << input << '\n';
        if (input == number)
        {
            std::cout << "Voila! you got the answer :)\n";
            return true;
        }
        else if(input < number)
        {
            std::cout << "your guessed number (" << input <<") is too low\n";
        }
        else
        {
            std::cout << "your guessed number (" << input <<") is too high\n";
        }

    }
    std::cout << "Sorry, you lose. The correct answer was: " << number << ".\n";
    return false;

}

bool playAgain()
{
    while(true)
    {
        std::cout << "Do you want to play again? (y/n): ";
        char ch {};
        std::cin >> ch;
        ignoreLine();
            switch(ch)
            {
            case 'y': return true;
            case 'n': return false;
            case 'Y': return true;
            case 'N': return false;
                
            default:
                std::cout << "Error: enter 'y' to continue nd 'n' for not : \n";
            }
    }
}