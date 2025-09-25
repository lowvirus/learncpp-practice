#include "gameLogic.h"
#include <iostream>
#include <string>

int main()
{

    const std::string playerName{ getName() };
    constexpr int maxPlayerHealth{ 100 };
    int playerHealth{ maxPlayerHealth };

    const std::string goblin{ "Vicious Goblin" };
    const std::string ogre{ "Hulking Ogre" };
    const std::string dragon{ "Shadow Dragon" };


    displayStat("Hero", playerName);
    displayStat("HP", playerHealth);
    std::cout << "\nThe trial begins!\n\n";

    //Battle
    fightMonster(playerHealth, goblin, 10, 20);
    fightMonster(playerHealth, ogre, 20, 35);
    fightMonster(playerHealth, dragon, 30, 50);

        if (playerHealth > 0)
    {
        std::cout << "Congratulations, " << playerName << ", you have survived the trial!\n";
    }
    else
    {
        std::cout << "You have fallen, " << playerName << ". The trial has claimed another hero.\n";
    }

    return 0;
}