#ifndef HILOWHEADS_H
#define HILOWHEADS_H

int getUserInput();
namespace Random
{
    int get(int x, int y);
}
bool highLow(int guesses,int min, int max);
bool playAgain();

#endif