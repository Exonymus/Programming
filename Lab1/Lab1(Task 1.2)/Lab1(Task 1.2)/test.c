#ifdef TEST
#include <stdio.h>
#include "functions.h"

int main()
{
    int i;
    for (i = 100; i < 10000; i++)
    {
        printf("Результат: %d\n", operation(i));
    }
    return 0;
}
#endif
