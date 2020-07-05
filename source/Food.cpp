#include "../header/Food.h"

void Food::newFood()
{
    point.randomPoint(&x, &y);
}

void Food::drawFood(HANDLE h_output)
{
    COORD coord = {0, 0};
    DWORD bytes = 0;
    coord.X = x;
    coord.Y = y;
    WriteConsoleOutputCharacterA(h_output, "▲", 4, coord, &bytes);
}