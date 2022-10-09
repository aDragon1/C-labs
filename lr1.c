#include <stdio.h>
#include <math.h>

float task1(int x, int y){
    float lg = logf(x);
    float part1 = pow(4,lg); 
    float part2 = logf(7*pow(x,2)) / logf(3); 
    float part3 = sin(x+y) / cos(x-y); 
    return part1 + part2 - part3;
}

float task2(int r1,int r2,int r3){
    return 1/(1/(float) r1 + 1/(float) r2 + 1/(float) r3);
}

int task3(float num){
    // last symbol 
    int intNum = (int) num;
    int a = intNum%10;

    // second symbol
    intNum = div(intNum,10);
    int b = intNum%10;

    // first symbol
    intNum = div(intNum,10);
    int c = intNum%10;
    printf("a = %d b = %d c = %d \n",a,b,c);
    return a*a + b*b + c*c;
}

int main (void)
{
    // Task1:
    float x,y;
    printf("Введите x,y для задания 1: \n");
    printf("x ="); scanf("%f",&x);
    printf("y ="); scanf("%f",&y);
    printf("Задание 1 - %f\n\n", task1(x,y));

    // Task2:
    float r1,r2,r3;
    printf("Введите r1 r2 r3 для задания 2: (через пробел)\n");
    printf("r1 ="); scanf("%f",&r1);
    printf("r2 ="); scanf("%f",&r2);
    printf("r3 ="); scanf("%f",&r3);
    printf("Задание 2 - %f\n\n", task2(r1,r2,r3));

    // Task3:
    float num;
    printf("Введите число, для задания 3:\n");
    printf("Числов - "); scanf("%f",&num);
    printf("Сумма квадратов цифр этого числа = %d",task3(num));

  return 0;
}