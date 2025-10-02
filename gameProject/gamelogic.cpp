#include "gameLogic.h"
#include "utils.h"
#include "player.h" 

#include <iostream>
#include <thread>
#include <chrono>

// Handles a complete combat encounter.
bool handleCombat(std::string_view monsterName, int& monsterHealth, int minAttack, int maxAttack)
{
    // The combat loop continues as long as both player and monster are alive.
    while (g_playerHealth > 0 && monsterHealth > 0)
    {
        // To Show status
        std::cout << "\n--- Battle Status ---\n";
        std::cout << g_playerName << " HP: " << g_playerHealth << " | Potions: " << g_playerPotions << '\n';
        std::cout << monsterName << " HP: " << monsterHealth << '\n';
        std::cout << "+-----------+----------+\n";
        std::cout << "What will you do? (attack / potion)\n";

        //Get player action
        std::string command = getPlayerCommand();

        if (command == "attack")
        {
            int playerDamage = getRandomNumber(20, 35);
            monsterHealth -= playerDamage;
            std::cout << "\n> You attack " << monsterName << " for " << playerDamage << " damage!\n";
        }
        else if (command == "potion")
        {
            if (g_playerPotions > 0)
            {
                --g_playerPotions;
                g_playerHealth = 100; // Fully heal
                std::cout << "\n> You drink a health potion, restoring you to full health!\n";
            }
            else
            {
                std::cout << "\n> You don't have any potions left!\n";
                continue; 
            }
        }
        else
        {
            std::cout << "\n> Invalid command! You hesitate, giving the " << monsterName << " an opening!\n";
        }

        // Check for monster defeat
        if (monsterHealth <= 0)
        {
            std::cout << "\nCongratulations! You defeated the " << monsterName << "!\n";
            std::cout << "It dropped a health potion!\n";
            ++g_playerPotions;
            return true; 
        }

        // Monster's turn
        std::cout << "The " << monsterName << " prepares to attack...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        int damageTaken = getRandomNumber(minAttack, maxAttack);
        g_playerHealth -= damageTaken;
        std::cout << "> The " << monsterName << " attacks you for " << damageTaken << " damage!\n";
    }

    // If the loop ends, it must be because the player was defeated.
    return false; 
}
