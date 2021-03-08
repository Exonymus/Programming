#ifdef TEST
#include <stdio.h>
#include "functions.h"

int main()
{
    int i, a;
    i = 100;
    if (operation(i) == 0)
        printf("100: Valid\n");
    else
        printf("100: Invalid\n");
    i = 101;
    if (operation(i) == 0)
        printf("101: Valid\n");
    else
        printf("101: Invalid\n");
    i = 110;
    if (operation(i) == 0)
        printf("110: Valid\n");
    else
        printf("110: Invalid\n");
    i = 111;
    if (operation(i) == 1)
        printf("111: Valid\n");
    else
        printf("111: Invalid\n");
    i = 235;
    if (operation(i) == 30)
        printf("235: Valid\n");
    else
        printf("235: Invalid\n");
    i = 676;
    if (operation(i) == 252)
        printf("676: Valid\n");
    else
        printf("676: Invalid\n");
    i = 1000;
    if (operation(i) == 1)
        printf("1000: Valid\n");
    else
        printf("1000: Invalid\n");
    i = 1111;
    if (operation(i) == 4)
        printf("1111: Valid\n");
    else
        printf("1111: Invalid\n");
    i = 9999;
    if (operation(i) == 36)
        printf("9999: Valid\n");
    else
        printf("9999: Invalid\n");
    i = 4567;
    if (operation(i) == 22)
        printf("4567: Valid\n");
    else
        printf("4567: Invalid\n");
    return 0;
}
#endif
