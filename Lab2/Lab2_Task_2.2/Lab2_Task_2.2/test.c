#ifdef TEST
#include <stdio.h>
#include "functions.h"
#include <math.h>
#include <assert.h>

int main()
{
    float x = 0.5;
    for (; x < 10; x += 0.1)
    {
        assert(trunc(sum(x,17) * 100) == trunc(sinf(x) * 100));
        printf("%f - valid\n", x);
    }
    return 0;
}
#endif
