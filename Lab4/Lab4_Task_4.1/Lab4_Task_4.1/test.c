#ifdef TEST
#include "functions.h"
#include <assert.h>
#include <string.h>

int main()
{
    int* length, * path;
    char** text;
    int n = 5, i;
    
    length = (int*) malloc( n * sizeof(int));
    assert(length != NULL);
    
    path = (int*) malloc( n * sizeof(int));
    assert(path != NULL);
    
    text = (char**) malloc( n * sizeof(char*));
    assert(text != NULL);
    memset(text,0,1);
    for (i = 0; i < n; i++)
    {
        text[i] = (char*) malloc( 9 * sizeof(char));
        assert(text[i] != NULL);
    }
    
    strcpy(text[0], "test");
    strcpy(text[1], "check");
    strcpy(text[2], "assert");
    strcpy(text[3], "kia");
    strcpy(text[4], "tic");
    length[0] = 3;
    length[1] = 4;
    length[2] = 5;
    length[3] = 2;
    length[4] = 2;
    assert(sort(text, 5, length, path) != 0);
    printf("Test 1 - Success\n");
    length[2] = 3;
    strcpy(text[2], "none");
    assert(sort(text, 5, length, path) == 0);
    printf("Test 2 - Success\n");
    strcpy(text[2], "ant");
    length[2] = 2;
    assert(sort(text, 5, length, path) != 0);
    printf("Test 3 - Success\n");
    length[0] = 2;
    assert(sort(text, 5, length, path) == 0);
    printf("Test 4 - Success\n");
    
    for (i = 0; i < n; i++)
        free(text[i]);
    free(path);
    free(length);
    free(text);
    return 0;
}
#endif
