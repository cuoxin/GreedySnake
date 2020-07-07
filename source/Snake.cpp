#include "../header/Snake.h"

#include <iostream>

using namespace std;

Snake::Snake()
{
    head = (S)malloc(sizeof(struct Snake)); // 这是空的

    S first_point = (S)malloc(sizeof(struct Snake)); // 蛇头

    // 随机位置生成蛇头
    int x,y;
    point.randomPoint(&x, &y, 1);

    first_point->x = x;
    first_point->y = y;
    first_point->next = NULL;
    first_point->previous = NULL;

    head->next = first_point;

    tail = head->next;

    initV();

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
        WriteConsoleOutputCharacterA(h_output, "●", 2, coord, &bytes);
        snake_point = snake_point->next;
    }
}


void Snake::moveSnake()
{
    S snake_point;
    snake_point = tail;

    while (snake_point->previous != NULL)
    {
        snake_point->x = snake_point->previous->x;
        snake_point->y = snake_point->previous->y;
        snake_point = snake_point->previous;

    }

    snake_point = head->next;

    snake_point->x += v[0];
    snake_point->y += v[1];

}


void Snake::initV()
{
    S temple;
    temple = head->next;
    if (temple->x <= LENGTH / 4 && temple->y <= LENGTH / 4)
    {
        v[0] = 2;
        v[1] = 0;
    }
    else if (temple->x >= LENGTH / 4 && temple->y <= LENGTH / 4)
    {
        v[0] = -2;
        v[1] = 0;
    }
    else if (temple->x >= LENGTH / 4 && temple->y >= LENGTH / 4)
    {
        v[0] = 0;
        v[1] = -1;
    }
    else
    {
        v[0] = 0;
        v[1] = 1;
    }
}


void Snake::changeV()
{
    int k;
    if (_kbhit())
    {
        k = _getch();
        if (k == 224)
        {
            k = _getch();
            switch (k)
            {
            case 75: // 左
                if (v[1] != 0)
                {
                    v[0] = 2 * abs(v[1]) * -1;
                    v[1] = 0;
                }
                break;

            case 72: // 上
                if (v[0] != 0)
                {
                    v[1] = abs(v[0]) / 2 * -1;
                    v[0] = 0;
                }
                break;

            case 77: // 右
                if (v[1] != 0)
                {
                    v[0] = 2 * abs(v[1]);
                    v[1] = 0;
                }
                break;

            case 80: // 下
                if (v[0] != 0)
                {
                    v[1] = abs(v[0]) / 2;
                    v[0] = 0;
                }
                break;
            
            default:
                break;
            }
        }
    }
}


void Snake::eatFood(int x, int y, int *eat_bool)
{
    S snake_head = head->next; // 真正的蛇头
    
    if (x == snake_head->x && y == snake_head->y)
    {
        *eat_bool = 1;
        addSnake();
    }
}


void Snake::addSnake()
{
    S new_point = (S)malloc(sizeof(struct SNAKE));
    new_point->x = tail->x+2;
    new_point->y = tail->y;
    new_point->next = NULL;
    new_point->previous = tail;

    tail->next = new_point;
    tail = new_point;
}