#ifndef FOD_H
#define FOD_H

#include <Windows.h>
#include "Point.h"

class Food
{
private:
    Point point;
public:
    COORD coord = {0, 0};
    DWORD bytes = 0;
    void newFood();
    void drawFood(HANDLE);
};


#endif