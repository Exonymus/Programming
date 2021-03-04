#ifdef TEST
#include <stdio.h>
#include "functions.h"

int main()
{
    int i, a;
    for (i = 100; i < 999; i++)
    {
        a = (i / 100) * (i / 10 % 10) * (i % 10);
        printf("Результат: %d; Правильный ответ: %d\n", operation(i), a);
    }
    return 0;
}
#endif
