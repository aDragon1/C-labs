#include <stdio.h>
#include <math.h>

float y = 1.6;
float dx = 0.3;
float eps = 1E-5;

float task1(float x)
{
    if (x < -1)
        return 1;
    else if (x <= 1)
        return x + 5;
    else if (x <= 2)
        return 6 * y * 2 * x + 4;
    else
        return x + sin(y);
}

float task2()
{
    float s, i;
    float current = 1;
    while (current > eps)
    {
        s += current;
        current = 1 / (2 * i + 1);
        i++;
    }

    printf("При заданной точности %g ряд имеет %g членов \n", eps, i);
    return s;
}

int main(void)
{
    // Task1:
    float x = -3;
    while (x <= 3)
    {
        printf("F(%G,%G) = %G \n", x, y, task1(x));
        x += dx;
    }

    // Task2:
    printf("\nСумма ряда  = %g", task2());

    return 0;
}