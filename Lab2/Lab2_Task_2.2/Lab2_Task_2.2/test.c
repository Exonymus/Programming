#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <math.h>
#include <assert.h>

int main()
{
    float x = 0.5;
    for (; x < 10; x += 0.1)
    {
        assert(abs(sum(x,17) * 10000 - sinf(x) * 10000 < 1e-5));
        printf("%f - valid\n", x);
    }
    return 0;
}
#endif
