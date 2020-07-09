#include "../header/Food.h"

Food::Food()
{
    food_bool = 1;
}

Food::~Food()
{
    food_bool = 1;
}



void Food::newFood()
{
    point.randomPoint(&x, &y, 2);
    coord.X = x;
    coord.Y = y;
}

void Food::drawFood(HANDLE h_output)
{
    WriteConsoleOutputCharacterA(h_output, "▲", 4, coord, &bytes);
}