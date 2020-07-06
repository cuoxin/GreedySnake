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

}


void Game::game()
{
    while (1) // 总游戏循环
    {
        // 画边框
        map.drawFrame(h_all[0]);
        map.drawFrame(h_all[1]);
        
        while (1) // 单局循环
        {   
            h_bool = !h_bool;

            // 食物
            if (food_bool)
            {
                food.newFood();
                food_bool = 0;
            }

            snake.changeV();
            snake.moveSnake();
            food.drawFood(h_all[h_bool]);
            snake.drawSnake(h_all[h_bool]);
            SetConsoleActiveScreenBuffer(h_all[h_bool]);

            // 清屏（除边框）
            map.clean(h_all[!h_bool]);
            Sleep(800);
            
        }
        
    }
    
}