#ifndef TEST
#include <stdio.h>
#include "functions.h"

int main()
{
    int x;
    printf("Введите число X (100..9999): ");
    if (check(&x)) return 1;
    printf("Результат: %d\n", operation(x));
    return 0;
}
#endif
