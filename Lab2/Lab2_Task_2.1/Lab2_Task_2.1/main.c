#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#ifndef TEST

int main()
{
    int x, choice = -1;
    printf("Введите ребро тетраэдра: ");
    check(&x);
    printf("1 - Рассчитать общую длину всех ребер тетраэдра.\n");
    printf("2 - Рассчитать площадь всех граней тетраэдра.\n");
    printf("3 - Рассчитать объем тетраэдра.\n");
    printf("4 - Рассчитать высоту тетраэдра.\n");
    printf("5 - Рассчитать радиус вписанного шара.\n");
    printf("6 - Вывести информацию о программе.\n");
    printf("0 - Выйти из программы.\n");
    menu(x, choice);
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
            if((!scanf("%1023[^\n]%c",inpStr,&buffer)) || buffer != '\n')
            {
                if(printf("Ввод не верен!\nПовторите ввод: "))
                    getchar();
            }
            else
            if(!sscanf(inpStr,"%d%c",&*a,&buffer) || buffer != '\n')
                printf("Ввод не верен!\nПовторите ввод: ");
            else
                valid = 1;
            if (*a <= 0)
            {
                printf("Ввод не верен!\nПовторите ввод: ");
                valid = 0;
            }
        }
}

void choiceCheck(int *a)
{
    int valid = 0;
    char inpStr[1024];
    char buffer = 0;
    while(!valid)
        {
            buffer = 0;
            if((!scanf("%1023[^\n]%c",inpStr,&buffer)) || buffer != '\n')
            {
                if(printf("Ввод не верен!\nПовторите ввод: "))
                    getchar();
            }
            else
            if(!sscanf(inpStr,"%d%c",&*a,&buffer) || buffer != '\n')
                printf("Ввод не верен!\nПовторите ввод: ");
            else
            if ((*a < 0) || (*a > 6))
            {
                printf("Выбран неверный пункт!\nПовторите ввод: ");
                valid = 0;
            }
            else
                valid = 1;
        }
}

float menu(int x, int choice)
{
    float result;
    while (choice != 0)
    {
        printf("Выберите пункт меню: ");
        choiceCheck(&choice);
        switch (choice)
            {
                case 1:
                    result = sum(x);
                    printf("Результат: %f\n",result);
                    break;
                case 2:
                    result = area(x);
                    printf("Результат: %f\n",result);
                    break;
                case 3:
                    result = value(x);
                    printf("Результат: %f\n",result);
                    break;
                case 4:
                    result = height(x);
                    printf("Результат: %f\n",result);
                    break;
                case 5:
                    result = rad(x);
                    printf("Результат: %f\n",result);
                    break;
                case 6:
                    printf("Версия программы: final. Автор программы: Аралин И.\n");
                    break;
                default:
                    break;
            }
       }
    return 0;
}
#endif

float sum(float x)
{
    x =  x * 6;
    return x;
}

float area(float x)
{
    x = sqrt(3) * pow(x, 2);
    return x;
}

float value(float x)
{
    x =  pow(x, 3) / (6 * sqrt(2));
    return x;
}

float height(float x)
{
    x =  sqrt(0.6667) * x;;
    return x;
}

float rad(float x)
{
    x = x / (2 * sqrt(6));
    return x;
}

