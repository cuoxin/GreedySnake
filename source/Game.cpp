#include "../header/Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
    h_all[0] = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );

    h_all[1] = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );

    //隐藏两个缓冲区的光标
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(h_all[0], &cci);
    SetConsoleCursorInfo(h_all[1], &cci);
}


void Game::game()
{
    while (1) // 总游戏循环
    {
        while (1) // 单局循环
        {
            h_bool = !h_bool;
            map.draw(h_all[h_bool]);
        }
        
    }
    
}