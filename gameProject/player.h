#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// --- Player Data (Shared across files) ---
// We declare these as 'extern' so other files like main.cpp and gamelogic.cpp
// know they exist and can use them. They are defined once in player.cpp.
extern int g_playerHealth;
extern int g_playerPotions;
extern std::string g_playerName;


// Sets up the player's initial state at the start of the game.
void initializePlayer();

// Checks if the player's health is above zero.
bool isPlayerAlive();

// Returns the player's name.
// We return a const reference for efficiency, no copy is made.
const std::string& getPlayerName();

// Displays the player's current health and potion count.
void displayPlayerStatus();

#endif
