#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Snake.h"
#include "Food.h"

class Game
{
private:
    Map map;
    HANDLE h_all[2];
    // 两个缓冲区的交替
    int h_bool = 0;
    // 食物是否被吃
public:
    Game();
    void game();
    void fullScreen();
};

#endif