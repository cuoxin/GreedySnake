#ifndef MAP_H
#define MAP_H

#include <Windows.h>
#define LENGTH 30 // 内宽

class Map
{
private:
    COORD coord = {0, 0};
    DWORD bytes = 0;
    char data[LENGTH + 2][LENGTH + 2];

public:
    void draw(HANDLE);
};

#endif