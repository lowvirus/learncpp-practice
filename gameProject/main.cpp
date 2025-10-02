#include "player.h"
#include "gameWorld.h"
#include "utils.h"

#include <iostream>
#include <string>

int main()
{

    initializePlayer();
    displayWelcomeStory();

    // The loop continues as long as the player is alive and hasn't won.
    while (isPlayerAlive() && !isGameWon())
    {
        //Describe the player's current situation.
        displayCurrentRoom();

        //Get the player's command.
        std::string command = getPlayerCommand();

        //Let the game world handle the command.
        handlePlayerInput(command);
    }

    // After the loop, we check why it ended.
    if (!isPlayerAlive())
    {
        std::cout << "\nYour adventure has come to a tragic end. Game Over.\n";
    }
    else if (isGameWon())
    {
        std::cout << "\nWith the Labyrinth Guardian defeated, you emerge victorious!\n";
        std::cout << "Congratulations, " << getPlayerName() << "!\n";
    }

    return 0;
}
