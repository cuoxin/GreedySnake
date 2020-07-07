#include <iostream>
using namespace std;

#include "../header/Map.h"

void Map::drawFrame(HANDLE h_output)
{
    for (int y = 0; y < LENGTH/2 + 2; y++)
    {
        coord.Y = y;
        for (int x = 0; x < LENGTH + 4; x+=2)
        {
            coord.X = x;
            if (y == 0 || y == LENGTH/2 + 1 || x == 0 || x == LENGTH + 2) // 上下边框
            {
                WriteConsoleOutputCharacterA(h_output, "■", 4, coord, &bytes);
            }
            
        }
    }
}

void Map::clean(HANDLE h_output)
{
    for (int y = 0; y < LENGTH/2 + 2; y++)
    {
        coord.Y = y;
        for (int x = 0; x < LENGTH + 4; x+=2)
        {
            coord.X = x;
            if (y == 0 || y == LENGTH/2 + 1 || x == 0 || x == LENGTH + 2) // 上下边框
            {
                ;
            }
            else
            {
                WriteConsoleOutputCharacterA(h_output, " ", 2, coord, &bytes);
            }
            
        }
    }
}