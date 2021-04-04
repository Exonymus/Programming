#ifdef TEST
#include "functions.h"
#include <assert.h>
#include <string.h>

int main()
{
    char** text;
    int amount = 5, i;
    
    text = (char**) malloc( amount * sizeof(char*));
    assert(text != NULL);
    memset(text,0,1);
    for (i = 0; i < amount; i++)
    {
        text[i] = (char*) malloc( 15 * sizeof(char));
        assert(text[i] != NULL);
    }
    
    strcpy(text[0], "test");
    strcpy(text[1], "check");
    strcpy(text[2], "assert");
    strcpy(text[3], "text");
    strcpy(text[4], "kill");
    
    edit(text, amount);
    assert(text[0][0] == 'a');
    printf("Test 1 - Success\n");
    
    strcpy(text[3], "ant");
    assert(text[1][0] != 'a');
    edit(text, amount);
    assert(text[1][0] == 'a');
    printf("Test 2 - Success\n");
    
    strcpy(text[3], "check");
    edit(text, amount);
    assert(text[0][0] == '\0');
    printf("Test 3 - Success\n");
    
    for (i = 0; i < amount; i++)
        free(text[i]);
    free(text);
    return 0;
}
#endif
