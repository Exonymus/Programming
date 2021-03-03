//
//  functions.h
//  Lab1(Task 2)
//
//  Created by Игорь Аралин on 21.02.21.
//

#include <stdio.h>

#ifndef functions_h
#define functions_h
#endif /* functions_h */

extern int operation(int x)
{
    int result = 0;
    if (x < 1000)
        result = (x / 100) * (x % 10) * (x / 10 % 10);
    else
        result = (x / 1000) + (x % 100 / 10) + (x / 100 % 10) + (x % 10);
    return result;
}

extern int check(int *a)
{
    if ((scanf("%d", &*a) != 1) || (*a < 100 || *a > 9999))
    {
        printf("Ввод не верен\n");
        return 1;
    }
    return 0;
}
