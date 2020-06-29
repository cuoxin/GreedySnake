#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include <windows.h>

class Game
{
private:
    Map map;
    HANDLE h_all[2];
    int h_bool = 0;
public:
    Game();
    void game();
    void fullScreen();
};

#endif