#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <string>


// Prints the description of the room the player is currently in.
void displayCurrentRoom();

// Takes the player's command and changes the game state accordingly.
void handlePlayerInput(const std::string& command);

// Checks if the player has met the win condition.
bool isGameWon();

#endif
