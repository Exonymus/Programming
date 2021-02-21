//
//  main.c
//  Lab1(Task 2)
//
//  Created by Игорь Аралин on 21.02.21.
//

#include <stdio.h>
#include "functions.h"

int operation(int x);
int check(int *a);

int main()
{
    int x;
    printf("Введите число X (100..9999): ");
    if (check(&x)) return 1;
    printf("Результат: %d\n", operation(x));
    return 0;
}


