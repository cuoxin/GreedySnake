#ifndef FOD_H
#define FOD_H

#include <Windows.h>
#include "Point.h"

class Food
{
private:
    Point point;
    COORD coord = {0, 0};
    DWORD bytes = 0;
public:
    int x,y;
    int food_bool;
    Food();
    ~Food();
    void newFood();
    void drawFood(HANDLE);
};


#endif