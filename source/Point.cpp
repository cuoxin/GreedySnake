#include "../header/Point.h"

void Point::randomPoint(int *x, int *y)
{
    srand((unsigned)time(0));
    int a = RANDOM(2, LENGTH);
    srand((unsigned)time(0));
    int b = RANDOM(2, LENGTH/2);

    if (a % 2 != 0)
    {
        a = a % 2 * 2;
    }

    *x = a;
    *y = b;

}