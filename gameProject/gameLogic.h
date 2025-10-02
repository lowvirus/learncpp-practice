#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <string_view>

// The main combat function.
// Returns 'true' if the player wins, 'false' if the player loses.
// It no longer needs player details passed in, as it can access them
// directly from the global variables declared in player.h.
bool handleCombat(std::string_view monsterName, int& monsterHealth, int minAttack, int maxAttack);

#endif
