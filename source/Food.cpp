#include "../header/Food.h"

void Food::newFood()
{
    int x,y;
    point.randomPoint(&x, &y, 2);
    coord.X = x;
    coord.Y = y;
}

void Food::drawFood(HANDLE h_output)
{
    WriteConsoleOutputCharacterA(h_output, "▲", 4, coord, &bytes);
}