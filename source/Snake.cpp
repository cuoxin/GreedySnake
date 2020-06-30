#include "../header/Snake.h"
#include "../header/Map.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

#define RANDOM(a, b) rand()%b+a;

using namespace std;

Snake::Snake()
{
    head = (S)malloc(sizeof(struct Snake)); // 这是空的

    S first_point = (S)malloc(sizeof(struct Snake)); // 蛇头

    // 随机位置生成蛇头
    srand((unsigned)time(0));
    int x = RANDOM(1, LENGTH);
    srand((unsigned)time(0));
    int y = RANDOM(1, LENGTH/2);

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