#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <assert.h>

int main()
{
    int m = 10, n = 10, i, k;
    int** field = (int**) malloc( m * sizeof(int*));
    assert(field);
    printf("Test valid\n");
    for (i = 0; i < m; i++)
    {
        field[i] = (int*) malloc( n * sizeof(int));
        assert(field[i]);
    }
    
    for (i = 0; i < m; i++)
        for (k = 0; k < n; k++)
                field[i][k] = 1;
    field[m - 1][0] = 0;
    
    assert(change(1, 9, 0, n, field) == 1);
    printf("Test valid\n");
    assert(change(2, 5, 5, n, field) == 0);
    printf("Test valid\n");
    assert(change(2, 9, 0, n, field) == 2);
    printf("Test valid\n");
    assert(change(1, 8, 8, n, field) == 0);
    printf("Test valid\n");
    assert(change(2, 3, 3, n, field) == 0);
    printf("Test valid\n");
   
    
    for (i = 0; i < m; i++)
        free(field[i]);
    free(field);
    return 0;
}
#endif
