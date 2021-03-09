#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#ifndef TEST

int main()
{
    int x, choice = 0;
    printf("Введите ребро тетраэдра: ");
    check(&x);
    menu(x, choice);
    return 0;
}

void check(int *a)
{
    if ((scanf("%d", &*a) != 1) || (*a == 0))
    {
        printf("Ввод не верен\n");
        exit(1);
    }
}

void ChoiceCheck(int *a)
{
    if ((scanf("%d", &*a) != 1) || (*a < 0) || (*a > 6))
    {
        printf("Ввод не верен\n");
        exit(1);
    }
}
#endif

float menu(int x, int choice)
{
    float result;
#ifndef TEST
    printf("1 - Рассчитать общую длину всех ребер тетраэдра.\n");
    printf("2 - Рассчитать площадь всех граней тетраэдра.\n");
    printf("3 - Рассчитать объем тетраэдра.\n");
    printf("4 - Рассчитать высоту тетраэдра.\n");
    printf("5 - Рассчитать радиус вписанного шара.\n");
    printf("6 - Вывести информацию о программе.\n");
    printf("0 - Выйти из программы.\n");
    printf("Выберите пункт меню: ");
    ChoiceCheck(&choice);
#endif
    switch (choice)
       {
           case 1:
               result =  x * 6;
               printf("Результат: %f\n",result);
#ifdef TEST
               return result;
#endif
               menu(x, 0);
               break;
           case 2:
               result = sqrt(3) * pow(x, 2);
               printf("Результат: %f\n",result);
#ifdef TEST
               return result;
#endif
               menu(x, 0);
               break;
           case 3:
               result = pow(x, 3) / (6 * sqrt(2));
               printf("Результат: %f\n",result);
#ifdef TEST
               return result;
#endif
               menu(x, 0);
               break;
           case 4:
               result = sqrt(0.6667) * x;
               printf("Результат: %f\n",result);
#ifdef TEST
               return result;
#endif
               menu(x, 0);
               break;
           case 5:
               result = x / (2 * sqrt(6));
               printf("Результат: %f\n",result);
#ifdef TEST
               return result;
#endif
               menu(x, 0);
               break;
           case 6:
               printf("Версия программы: 0.1 Автор программы: Аралин И.\n");
               menu(x, 0);
               break;
           default:
               break;
       }
    return 0;
}
