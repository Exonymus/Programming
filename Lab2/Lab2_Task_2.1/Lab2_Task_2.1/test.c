#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <math.h>

int main()
{
    int i = 4, choice;
    
    printf("Для ребра = 4\n");
    for (choice = 1; choice < 6; choice++)
    {
        switch (choice)
        {
            case 1:
                if (trunc((menu(i,choice) * 1000)) == 24000)
                    printf("4(1) - Valid\n");
                else
                    printf("4(1) - Invalid\n");
                break;
            case 2:
                if (trunc((menu(i,choice) * 1000)) == 27712)
                    printf("4(2) - Valid\n");
                else
                    printf("4(2) - Invalid\n");
                break;
            case 3:
                if (trunc((menu(i,choice) * 1000)) == 7542)
                    printf("4(3) - Valid\n");
                else
                    printf("4(3) - Invalid\n");
                break;
            case 4:
                if (trunc((menu(i,choice) * 1000)) == 3266)
                    printf("4(4) - Valid\n");
                else
                    printf("4(4) - Invalid\n");
                break;
            case 5:
                if (trunc((menu(i,choice) * 1000)) == 816)
                    printf("4(5) - Valid\n");
                else
                    printf("4(5) - Invalid\n");
                break;
        }
    }
    i = 5;
    printf("Для ребра = 5\n");
    for (choice = 1; choice < 6; choice++)
    {
        switch (choice)
        {
            case 1:
                if (trunc((menu(i,choice) * 1000)) == 30000)
                    printf("5(1) - Valid\n");
                else
                    printf("5(1) - Invalid\n");
                break;
            case 2:
                if (trunc((menu(i,choice) * 1000)) == 43301)
                    printf("5(2) - Valid\n");
                else
                    printf("5(2) - Invalid\n");
                break;
            case 3:
                if (trunc((menu(i,choice) * 1000)) == 14731)
                    printf("5(3) - Valid\n");
                else
                    printf("5(3) - Invalid\n");
                break;
            case 4:
                if (trunc((menu(i,choice) * 1000)) == 4082)
                    printf("5(4) - Valid\n");
                else
                    printf("5(4) - Invalid\n");
                break;
            case 5:
                if (trunc((menu(i,choice) * 1000)) == 1020)
                    printf("5(5) - Valid\n");
                else
                    printf("5(5) - Invalid\n");
                break;
        }
    }
    return 0;
}
#endif
