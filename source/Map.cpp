#include <iostream>
using namespace std;

#include "../header/Map.h"

void Map::draw(HANDLE h_output)
{
    //Draw draw_graphical; // 画图对象

    for (int y = 0; y < LENGTH + 2; y++)
    {
        for (int x = 0; x < LENGTH + 2; x++)
        {
            if (x == 0 || y == 0 || x == LENGTH + 1 || y == LENGTH + 1) // 边框
            {
                data[y][x] = '#';
            }
            else // TODO: 记得扩充蛇和食物的部分
            {
                data[y][x] = ' ';
            }
            
        }
    }

    // 填充缓冲区
    // TODO: 更改输出方式，选择使用局部输出
    for (int i = 0; i < LENGTH + 2; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(h_output, data[i], LENGTH + 2, coord, &bytes);
    }
    SetConsoleActiveScreenBuffer(h_output);
    Sleep(500);

}