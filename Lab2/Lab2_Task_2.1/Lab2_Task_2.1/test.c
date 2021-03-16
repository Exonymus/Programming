#ifdef TEST
#include <stdio.h>
#include "functions.h"
#include <math.h>
#include <assert.h>

int main()
{
    int i = 4, choice;
    
    printf("Для ребра = 4\n");
    
    assert(trunc(sum(i) * 1000) - 24000 < pow(10, -12));
    printf("4(1) - Valid\n");
    assert(trunc(area(i) * 1000) - 27712 < pow(10, -12));
    printf("4(2) - Valid\n");
    assert(trunc(value(i) * 1000) - 7542 < pow(10, -12));
    printf("4(3) - Valid\n");
    assert(trunc(height(i) * 1000) - 3266 < pow(10, -12));
    printf("4(4) - Valid\n");
    assert(trunc(rad(i) * 1000) - 816 < pow(10, -12));
    printf("4(5) - Valid\n");
    
    i = 5;
    printf("Для ребра = 5\n");
    assert(trunc(sum(i) * 1000) - 30000 < pow(10, -12));
    printf("5(1) - Valid\n");
    assert(trunc(area(i) * 1000) - 43301 < pow(10, -12));
    printf("5(2) - Valid\n");
    assert(trunc(value(i) * 1000) - 14731 < pow(10, -12));
    printf("5(3) - Valid\n");
    assert(trunc(height(i) * 1000) - 4082 < pow(10, -12));
    printf("5(4) - Valid\n");
    assert(trunc(rad(i) * 1000) - 1020 < pow(10, -12));
    printf("5(5) - Valid\n");
    return 0;
}
#endif
