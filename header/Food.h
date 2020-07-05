#ifndef FOD_H
#define FOD_H

#include <Windows.h>
#include "Point.h"

class Food
{
private:
    Point point;
public:
    int x, y;
    void newFood();
    void drawFood(HANDLE);
};


#endif