#include "../header/Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
    char sys[50];
    sprintf(sys, "mode con cols=%d lines=%d",LENGTH+45, LENGTH/2+5);
    system(sys);
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

    // 画边框
    map.drawFrame(h_all[0]);
    map.drawFrame(h_all[1]);
}


void Game::game()
{
    while (1) // 总游戏循环
    {
        while (1) // 单局循环
        {   
            SetConsoleActiveScreenBuffer(h_all[0]);
            Sleep(500);
            SetConsoleActiveScreenBuffer(h_all[1]);
            
        }
        
    }
    
}