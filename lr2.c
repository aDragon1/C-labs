#include <stdio.h>
#include <math.h>

float task1(float x, float y)
{
    if (x < 1)
        return 1;
    else if (x < 2)
        return x + 5;
    else if (x < 4)
        return 6 * y * 2 * x + 4;
    else
        return x + sin(y);
}

float max(float a, float b)
{
    if (a > b)
        return 1;
    else
        return 0;
}

int main(void)
{
    // Task1:
    float x, y;
    printf("Enter the x,y for task 1: \n");
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("F(%g , %g) = %g \n", x, y, task1(x, y));

    // Task2:
    printf("Enter 2 numbers for task 2: \n");
    scanf("%f %f", &x, &y);
    max(x, y) == 1 ? printf("%g > %g => printing %3g", x, y, x) : printf("%g <= %g => printing %g %g", x, y, x, y);

    return 0;
}
