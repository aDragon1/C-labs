#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printArray(char msg[], int arr[], int size)
{
    printf("\n");
    printf(msg);
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%3d ", arr[i]);
}

void print2DArray(char msg[], int size1, int size2, int arr[][size2])
{
    printf("\n");
    printf(msg);
    printf("\n");
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }
}

int random(int maxValue, int negativeChance)
{
    int value = rand() % maxValue;
    int sign = (rand() % 10) > negativeChance ? 1 : -1;
    return value * sign;
}

int countPositive(int arr[], int size)
{
    int s;
    for (int i = 0; i < size; i++)
        if (arr[i] > 0)
            s++;
    return s;
}

int getArr1DSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int n, m;
    printf("Enter the length of 1D array for task 1: \n");
    scanf("%d", &n);

    int arr[n], reverseArray[n]; // Init
    for (int i = 0; i < n; i++)
        arr[i] = random(100, 5); // Fill

    for (int i = 0; i < n; i++)
        reverseArray[i] = arr[n - 1 - i];

    printArray("Array - ", arr, n);
    printArray("Reverse array - ", reverseArray, n);

    printf("Enter the length's of 2D array for task 2: \n");
    scanf("%d %d", &m, &n);

    int arr2d[m][n]; // init
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr2d[i][j] = random(100, 5); // Fill

    print2DArray("Sorce 2D array - ", m, n, arr2d);
    int minRow, minSum = 0;
    for (int i = 0; i < m; i++)
    {
        int sum = getArr1DSum(arr2d[i], n);
        if (sum < minSum)
        {
            minSum = sum;
            minRow = i;
        }
    }
    printf("The row with the minimum amount is %d, \n The sum of this row is %d \n", minRow, minSum);

    return 0;
}
