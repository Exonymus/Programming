#ifndef TEST
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int x;
    printf("Введите число X (100..9999): ");
    check(&x);
    printf("Результат: %d\n", operation(x));
    return 0;
}
void check(int *a)
{
    if ((scanf("%d", &*a) != 1) || (*a < 100 || *a > 9999))
    {
        printf("Ввод не верен\n");
        exit(1);
    }
}
#endif

int operation(int x)
{
    int result = 0;
    if (x < 1000)
        result = (x / 100) * (x % 10) * (x / 10 % 10);
    else
        result = (x / 1000) + (x % 100 / 10) + (x / 100 % 10) + (x % 10);
    return result;
}
