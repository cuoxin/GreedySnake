#ifndef SNAKE_H
#define SNAKE_H

#include "Map.h"
#include "Point.h"
#include <conio.h>
#include <stdio.h>

typedef struct SNAKE
{
    int x;
    int y;
    struct SNAKE *next;
    struct SNAKE *previous;
}*S;

class Snake
{
private:
    Point point;
    S head, tail;
    // 蛇的长度
    int length;
    // 蛇的移动速度
    int v[2];
public:
    Snake();
    ~Snake();
    // 增加节点,尾插法
    void addSnake();
    // 蛇节点的移动
    void moveSnake();
    // 画蛇
    void drawSnake(HANDLE);
    // 吃食物的判定
    void eatFood(int, int, int *);
    // 失败的判定
    int judge();
    // 初始化速度
    void initV();
    // 改变速度
    void changeV();
    // 检查与蛇重复
    int repeat(int, int);

};

#endif