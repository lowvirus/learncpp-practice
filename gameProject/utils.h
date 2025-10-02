#ifndef UTILS_H
#define UTILS_H

#include <string>


// Displays the initial welcome story.
void displayWelcomeStory();

// Prompts the user for their name and returns it.
std::string getName();

// Gets a single line of input from the player and converts it to lowercase.
std::string getPlayerCommand();

// Generates a random integer within the specified inclusive range.
int getRandomNumber(int min, int max);

#endif
