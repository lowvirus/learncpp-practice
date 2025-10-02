#include "utils.h"
#include <iostream>
#include <string>
#include <random>
#include <cctype>

// This function now takes the string by REFERENCE (&).
// This means it modifies the ORIGINAL string passed to it, which is
// more efficient than making a copy.
void toLowerCase(std::string& text)
{
    for (char& c : text)
    {
        c = static_cast<char>(std::tolower(c));
    }
}

std::string getPlayerCommand()
{
    std::cout << "> ";
    std::string command{};
    std::getline(std::cin, command);

    // Now we call the function to modify the 'command' variable directly.
    toLowerCase(command);
    return command;
}

void displayWelcomeStory()
{
    std::cout << "Welcome, adventurer!\n";
    std::cout << "You find yourself at the entrance of the dreaded Labyrinth of Primitives.\n";
    std::cout << "Your goal is to find and defeat the Labyrinth Guardian.\n\n";
}

std::string getName()
{
    std::string name{};
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << '\n';
    return name;
}

int getRandomNumber(int min, int max)
{
    // A more concise way to seed the random number generator.
    static std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution range(min, max);
    return range(mt);
}
