#include <iostream>
using namespace std;

#include "../header/Map.h"

void Map::drawFrame(HANDLE h_output)
{
    for (int y = 0; y < LENGTH/2 + 1; y++)
    {
        for (int x = 0; x < LENGTH + 2; x++)
        {
            if (y == 0 || y == LENGTH/2) // 上下边框
            {
                data[y][x] = '-';
            }
            else if (x == 0 || x == LENGTH + 1)
            {
                data[y][x] = '|';
            }
            else // TODO: 记得扩充蛇和食物的部分
            {
                data[y][x] = ' ';

            }
            
        }
    }

    for (int i = 0;i < LENGTH/2 + 1; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(h_output, data[i], LENGTH + 2, coord, &bytes);
    }

}