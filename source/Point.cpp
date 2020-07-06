#include "../header/Point.h"

void Point::randomPoint(int *x, int *y, int sign)
{
    srand((unsigned)time(0) + sign);
    int a = RANDOM(3, LENGTH-4);
    srand((unsigned)time(0) - sign);
    int b = RANDOM(3, LENGTH/2-2);

    if (a % 2 != 0)
    {
        a = a % 2 * 2;
    }

    *x = a;
    *y = b;

}