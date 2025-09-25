#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <string>
#include <iostream>

//Declaration for access
std::string getName();
int getRandomDamage(int min, int max);
void fightMonster(int& playerHealth, const std::string& monsterName, int minDamage, int maxDamage);



template <typename T>
void displayStat(const std::string& label, const T& value)
{
    std::cout << label << ": [" << value << "]\n";
}

#endif