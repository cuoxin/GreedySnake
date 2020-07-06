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

    head->next = first_point;

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
        WriteConsoleOutputCharacterA(h_output, "●", 4, coord, &bytes);
        snake_point = snake_point->next;
    }
}


void Snake::moveSnake()
{
    S snake_point, temple;
    snake_point = head->next;

    while (snake_point != NULL)
    {
        temple = snake_point;
        snake_point = snake_point->next;
        if (snake_point == NULL)
        {
            break;
        }

        snake_point->x = temple->x;
        snake_point->y = temple->y;

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