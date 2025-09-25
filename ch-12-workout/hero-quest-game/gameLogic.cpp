#include "gameLogic.h"
#include <iostream>
#include <string>
#include <random>



// Functon to get the player's name from input.
std::string getName()
{
    std::cout << "Welcome, hero! What is your name? ";
    std::string name{};
    std::getline(std::cin, name);
    return name;
}

//To get random number for damage
int getRandomDamage(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mt{rd()};
    std::uniform_int_distribution rand(min, max);
    return rand(mt);
}


void fightMonster(int& playerHealth, const std::string& monsterName, int minDamage, int maxDamage)
{
    // Get the damage for this specific monster.
    const int damageDealt{ getRandomDamage(minDamage, maxDamage) };

    // Permanently reduce the player's health using the reference.
    playerHealth -= damageDealt;

    // Report the outcome of this single battle.
    std::cout << "The " << monsterName << " strikes! You take " << damageDealt
              << " damage. You have " << playerHealth << " HP left.\n\n";
}