#include <stdio.h>
#include <math.h>

float task1(float x, float y)
{
    if (x < 0)
        return 3 * x + 1;
    else if (x == 0)
        return y + cos(x);
    else if (x > 0)
        return y - sin(x);
}

float max(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}

float task2(float a, float b, float c)
{
    return max(max(a, b), c);
}
int main(void)
{
    // Task1:
    float x, y;
    printf("Введите x,y для задания 1: \n");
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("F(%g , %g) = %g \n", x, y, task1(-1, 0));

    // Task2:
    float a, b, c;
    printf("Введите 3 для задания 2: \n");
    scanf("%f %f %f", &a, &b, &c);
    printf(" Максимальное, среди чисел %G,%G,%G - %G", a, b, c, task2(a, b, c));
    return 0;
}