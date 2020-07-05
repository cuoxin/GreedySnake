#include "../header/Snake.h"

#include <iostream>

using namespace std;

Snake::Snake()
{
    head = (S)malloc(sizeof(struct Snake)); // 这是空的

    S first_point = (S)malloc(sizeof(struct Snake)); // 蛇头

    // 随机位置生成蛇头
    int x,y;
    point.randomPoint(&x, &y);

    first_point->x = x;
    first_point->y = y;
    first_point->next = NULL;

    head->next = first_point;

}


Snake::~Snake()
{
    // 清除蛇的所有结点
    S temple;
    while (head != NULL)
    {
        temple = head->next;
        free(head);
        head = temple;
    }

}

void Snake::drawSnake(HANDLE h_output)
{
    COORD coord = {0, 0};
    DWORD bytes = 0;
    S snake_point;
    snake_point = head->next;
    while (snake_point != NULL)
    {
        coord.X = snake_point->x;
        coord.Y = snake_point->y;
        WriteConsoleOutputCharacterA(h_output, "●", 4, coord, &bytes);
        snake_point = snake_point->next;
    }
}