#include "player.h"
#include "utils.h" // For getName()
#include <iostream>


int g_playerHealth;
int g_playerPotions;
std::string g_playerName;


void initializePlayer()
{
    g_playerHealth = 100;
    g_playerPotions = 1; 
    g_playerName = getName();
}

bool isPlayerAlive()
{
    return g_playerHealth > 0;
}

const std::string& getPlayerName()
{
    return g_playerName;
}

void displayPlayerStatus()
{
    std::cout << "[*** Your Status ***]\n";
    std::cout << " Health: " << g_playerHealth << "/100\n";
    std::cout << " Potions: " << g_playerPotions << '\n';
    std::cout << "+----------+---------+\n";
}
