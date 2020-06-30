#ifndef SNAKE_H
#define SNAKE_H

typedef struct Snake
{
    int x;
    int y;
    struct Snake *next;
}*S;

class Snake
{
private:
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
    void drawSnake();
    // 吃食物的判定
    void eatFood();
    // 失败的判定
    void judge();

};

#endif