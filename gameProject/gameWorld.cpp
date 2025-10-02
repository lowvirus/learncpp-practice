#include "gameWorld.h"
#include "gameLogic.h"
#include "player.h" 
#include "utils.h"

#include <iostream>

void displayGoblinArt()
{
    std::cout << R"(
          ..__
           "-.`-.
              \  '.
              :   :_
              .-"   o`--.
           _."           `.
        .-"   .-' '-  \__ :
      .'    .'   i-..-'  `"
    .'     :   .'
   :            ".      .__
  :    .-'        '-.--i._.?)
 :    :     '-. '.  .'..-"?)
 : `.     :   `  ` /-'-"  '
:  .    .'        :
: :    : `-    .-'".__
!             / :-._. '-.
 `.  "-._  _.'  :_  "-..?)
   `-.   ""   .'  "-..-"?)
      `-.._.-'          '
)" << '\n';
}

void displayQueenArt()
{
    
    std::cout << R"(
⠀⣀⣀⡀⣤⣤⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠉⣿⣿⣿⣿⣿⡧⣶⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠴⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠛⠛⠛⠛⠛⠓⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣶⣶⣾⣶⡆⣀⣤⣆⣿⡇⠸⣇⣤⣤⣤⣤⣤⣀⡀⠀⠀⠹⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⠿⠿⣥⠀⢠⣿⢿⣿⡇⣿⣿⣣⣤⣹⣿⣿⣿⣿⣿⣿⣯⣗⣦⣼⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠋⠁⠀⠀⠀⠘⣆⡾⠁⣀⣹⡀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢶⣿⣿⣿⣷⣼⣿⣿⠿⠿⢿⡿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣆⣠⣤⣿⣤⣴⣶⣯⣤⣴⣦⣿⣍⣿⠛⡿⠙⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣸⣿⣿⣿⣿⣤⡸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣭⣿⣿⣿⢏⣾⡳⢹⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⢟⢿⣿⣿⣿⣿⢿⣿⣿⠟⣿⠿⠟⠛⢡⣿⣿⡼⢿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⠈⠛⠟⠖⠈⠀⠀⠀⣾⣿⠿⣧⣼⣿⣿⣿⡟⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⢿⣶⣤⡀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⣽⠯⣴⣿⣿⣿⡟⠻⠝⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⡟⠉⠁⠁⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⡇⠀⢠⣶⢦⣤⣀⣀⠀⠀⢀⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢠⡾⠋⠀⠛⠀⠈⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣸⡿⠀⠘⢿⣿⣿⣷⣿⠏⠀⣸⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⠷⣄⠀⠀⠀⠈⠛⢁⣠⣾⣿⣿⣿⣿⡿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
)" << '\n';
}

// --- Game State Variables ---
static int s_currentRoomID{ 0 };
static bool s_isGoblinAlive{ true };
static bool s_isJennaAlive{ true };
static bool s_gameIsWon{ false };
static bool s_playerHasRustyKey{ false }; 

// --- Room Descriptions ---
void describeEntranceHall()
{
    std::cout << "\nYou are in the Entrance Hall. It is a cold, stone room.\n";
    std::cout << "The air is thick with dust and the silence is deafening.\n";
    std::cout << "A single, heavy wooden door leads NORTH.\n";
}

void describeCorridor()
{
    std::cout << "\nYou are in a long corridor stretching east and west.\n";
    std::cout << "Torches flicker on the walls, casting long, dancing shadows.\n";
    std::cout << "Paths lead EAST, WEST, and back SOUTH to the entrance.\n";
}

void describeGoblinLair()
{
    std::cout << "\nYou've entered a foul-smelling room, littered with bones.\n";
    if (s_isGoblinAlive)
    {
        std::cout << "A snarling Goblin King, surprisingly large, stands before you!\n";
    }
    else
    {
        std::cout << "The slain Goblin King lies on the floor.\n";
        if (!s_playerHasRustyKey)
        {
            std::cout << "Something shiny glints from beneath its hand. (Hint: try 'inspect')\n";
        }
        std::cout << "A path leads back WEST to the corridor.\n";
    }
}

void describeArmory()
{
    std::cout << "\nYou are in an old armory. Racks of rusted swords and broken shields line the walls.\n";
    std::cout << "There is a sturdy-looking door to the NORTH, but it appears to be locked.\n";
    std::cout << "A path leads back EAST to the corridor.\n";
}

void describeQueensAntechamber()
{
    std::cout << "\nYou've entered a grand antechamber. Tattered banners hang from the high ceiling.\n";
    std::cout << "An imposing, ornate door stands to the NORTH. You feel a palpable dread emanating from it.\n";
    std::cout << "You can retreat SOUTH back to the armory.\n";
}

void describeQueensChamber()
{
    std::cout << "\nYou stand before a grand, ominous throne.\n";
    if (s_isJennaAlive)
    {
        std::cout << "Jenna, the Dark Queen, rises to face you!\n";
    }
    else
    {
        std::cout << "The Dark Queen has been vanquished. Her throne sits empty.\n";
    }
    std::cout << "A path leads back SOUTH.\n";
}



void displayCurrentRoom()
{
    switch (s_currentRoomID)
    {
    case 0: describeEntranceHall();      break;
    case 1: describeCorridor();          break;
    case 2: describeGoblinLair();        break;
    case 3: describeArmory();            break;
    case 4: describeQueensAntechamber(); break;
    case 5: describeQueensChamber();     break;
    default: std::cout << "Error: You are lost in the void...\n"; break;
    }
}

void handlePlayerInput(const std::string& command)
{
    if (command == "status")
    {
        displayPlayerStatus();
        return;
    }
    if (command == "help")
    {
        std::cout << "Commands: north, south, east, west, status, inspect, take, unlock, help.\n";
        return;
    }

    switch (s_currentRoomID)
    {
    case 0: // Entrance Hall
        if (command == "north") s_currentRoomID = 1;
        else if (command == "inspect") std::cout << "The walls are damp stone. The door looks ancient.\n";
        else std::cout << "You can't do that here.\n";
        break;

    case 1: // Corridor
        if (command == "east") s_currentRoomID = 2;
        else if (command == "west") s_currentRoomID = 3;
        else if (command == "south") s_currentRoomID = 0;
        else if (command == "inspect") std::cout << "The torches provide the only light. The air is stale.\n";
        else std::cout << "You can't go that way.\n";
        break;

    case 2: // Goblin Lair
        if (s_isGoblinAlive)
        {
            displayGoblinArt();
            int goblinHealth = 130;
            if (handleCombat("The Goblin King", goblinHealth, 8, 15))
            {
                s_isGoblinAlive = false;
            }
        }
        else // Goblin is dead
        {
            if (command == "west") s_currentRoomID = 1;
            else if (command == "inspect")
            {
                if (!s_playerHasRustyKey)
                {
                    std::cout << "You search the Goblin King's body and find a large, RUSTY KEY clutched in its hand.\n";
                }
                else
                {
                    std::cout << "You've already looted the body. There is nothing else here.\n";
                }
            }
            else if (command == "take key" || command == "take rusty key")
            {
                if (!s_playerHasRustyKey)
                {
                    s_playerHasRustyKey = true;
                    std::cout << "You pry the RUSTY KEY from the goblin's grasp. It feels heavy.\n";
                }
                else
                {
                    std::cout << "You already have the key.\n";
                }
            }
            else std::cout << "You can't do that here.\n";
        }
        break;

    case 3: // Armory
        if (command == "east") s_currentRoomID = 1;
        else if (command == "north" || command == "unlock door" || command == "use key")
        {
            if (s_playerHasRustyKey)
            {
                std::cout << "You insert the rusty key into the lock. With a loud *CLICK*, the door swings open.\n";
                s_currentRoomID = 4; // Move to the antechamber!
            }
            else
            {
                std::cout << "The door is locked. You need a key.\n";
            }
        }
        else if (command == "inspect") std::cout << "The weapons are ancient and useless. The northern door looks very strong.\n";
        else std::cout << "You can't do that here.\n";
        break;
    
    case 4: // Queen's Antechamber
        if (command == "north") s_currentRoomID = 5;
        else if (command == "south") s_currentRoomID = 3;
        else if (command == "inspect") std::cout << "The banners depict a crowned skeleton. A sense of doom hangs in the air.\n";
        else std::cout << "You can't do that here.\n";
        break;

    case 5: // Queen's Chamber
        if (s_isJennaAlive)
        {
            displayQueenArt();
            int jennaHealth = 200;
            if (handleCombat("Jenna, the Dark Queen", jennaHealth, 15, 25))
            {
                s_isJennaAlive = false;
                s_gameIsWon = true;
            }
        }
        else // Queen is dead
        {
             if (command == "south") s_currentRoomID = 4;
             else std::cout << "Her reign is over. There is nothing else to do here.\n";
        }
        break;
    }
}

bool isGameWon()
{
    return s_gameIsWon;
}

