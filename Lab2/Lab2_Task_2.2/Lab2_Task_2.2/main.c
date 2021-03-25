#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#ifndef TEST

int main()
{
    int n, ans = 0;
    int x, eps = 0;
    printf("Введите x: ");
    check(&x);
    x = fmod(x, 6.283);

    printf("Введите количество членов разложения[1..17]: ");
    check(&n);

    printf("Введите эпсилон: ");

    printf("Значение sin(x): %f\n", sinf(x));
    printf("Полученное значение sin(x): %f\n", sum(x,n));

    while (ans < 18 && eps < fabsf(sum(x, ans) - sinf(x)))
    {
        ans++;
    }
    if (eps < fabsf(sum(x, ans) - sinf(x)))
        printf("Заданная точность недостижима с таким условием.\n");
    else
        printf("Заданная точность достижима с n: %d\n", ans);

    return 0;
}

void check(int *a)
{
    int valid = 0;
    char inpStr[1024];
    char buffer = 0;
    while(!valid)
        {
            buffer = 0;
            if((scanf("%1023[^\n]%c",inpStr,&buffer) != 2) || buffer != '\n')
            {
                if(printf("Ввод не верен!\nПовторите ввод: "))
                    getchar();
            }
            else
            if((sscanf(inpStr,"%d%c",&*a,&buffer) != 1) || buffer != '\n')
                printf("Ввод не верен!\nПовторите ввод: ");
            else
            if (*a <= 0 || *a > 17)
            {
                printf("Ввод не верен!\nПовторите ввод: ");
                valid = 0;
            }
            else
                valid = 1;
        }
}

#endif

float fact (int a)
{
    if (a <= 1)
        return 1.;
    else
        return (a * fact(a - 1));
}

float factIt(int a)
{
    float res = 1;
    while (a > 1)
    {
        res *= a;
        a--;
    }
    return res;
}

float sum(float x, int n)
{
    float sinSum = 0;
    while (n > 0)
    {
        sinSum += member(x, n);
        n--;
    }
    return sinSum;
}

float member(float x, int n)
{
    float member;
    member = powf(-1.0, n - 1) * powf(x, 2 * n - 1) / fact(2 * n - 1);
    return member;

}
