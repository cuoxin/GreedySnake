#ifndef MAP_H
#define MAP_H

#include <Windows.h>
#define LENGTH (40 * 2) // 前一个数字内宽, 字符占两个字符

class Map
{
private:
    COORD coord = {0, 0};
    DWORD bytes = 0;
    char data[LENGTH/2+1][LENGTH+2];
public:
    void drawFrame(HANDLE);
    void drawSnake(HANDLE);
};

#endif