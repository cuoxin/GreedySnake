#ifndef SNAKE_H
#define SNAKE_H

#include "Map.h"
#include "Point.h"

typedef struct SNAKE
{
    int x;
    int y;
    struct SNAKE *next;
}*S;

class Snake
{
private:
    Point point;
    S head;
    // 蛇的长度
    int length;
public:
    Snake();
    ~Snake();
    // 增加节点,头插法
    void addSnake();
    // 蛇节点的移动
    void moveSnake();
    // 画蛇
    void drawSnake(HANDLE);
    // 吃食物的判定
    void eatFood();
    // 失败的判定
    void judge();

};

#endif