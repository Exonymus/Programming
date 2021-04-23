#include "functions.h"
#ifndef TEST
int main()
{
    int i = 0, j = 0, amount = 0;
    char** text;
    char n;
    FILE* fin = fopen("Text.txt", "r");
    
    if (fin == NULL)
    {
        printf("Не удалось открыть файл\n");
        return 1;
    }
    
    text = (char**) malloc(1 * sizeof(char*));
    if (text == NULL)
        exit(1);
    text[0] = (char*) malloc(15 * sizeof(char));
    if (text[i] == NULL)
            exit(1);
    
    i = 0;
    while(1)
    {
        n = fgetc(fin);
        if(feof(fin))
            break;
        if (n != ' ' && n != '.' && n != ',' && n != '!' && n != '?' && n != '"')
        {
            if (n >= 65 && n <= 90)
                text[i][j] = n + 32;
            else
                text[i][j] = n;
            j++;
        }
        else
        {
            if (n == ' ')
                text[i][j] = '\0';
            else
                continue;
            i++;
            text = (char**) realloc(text, (i + 1) * sizeof(char*));
            if (text == NULL)
                exit(1);
            text[i] = (char*) malloc( 15 * sizeof(char));
            if (text[i] == NULL)
                exit(1);
            j = 0;
        }
    }
    amount = i;
    
    edit(text, amount);
    for (i = 0; i < amount; i++)
        if (text[i][0] != '\0')
            printf("%s\n", text[i]);
    
    for (i = 0; i < amount + 1; i++)
        free(text[i]);
    free(text);
    fclose(fin);
    return 0;
}
#endif

void edit(char** text, int amount)
{
    int sum1 = 0, sum2 = 0, i, j, k;
    char* temp;
    
    temp = (char*) malloc( 15 * sizeof(char));
    if (temp == NULL)
        exit(1);
    
    for (i = 0; i < amount; i++)
    {
        for (k = 0; text[i][k] != '\0'; k++)
            sum1 += text[i][k];
        for (j = 0; j < amount; j++)
        {
            if (i != j)
            {
                for (k = 0; text[j][k] != '\0'; k++)
                    sum2 += text[j][k];
               if (sum1 == sum2)
                   text[j][0] = '\0';
            }
            else
                continue;
            sum2 = 0;
        }
        sum1 = 0;
    }
    
    for (i = 1; i < amount; ++i)
    {
        for (j = 0; j < amount - i; j++)
            if (text[j][0] > text[j + 1][0])
            {
                wordCopy(temp, text[j]);
                wordCopy(text[j], text[j + 1]);
                wordCopy(text[j + 1], temp);
            }
    }
    
    for (i = 1; i < amount; ++i)
    {
        for (j = 0; j < amount - i; j++)
            if (text[j][0] == text[j + 1][0])
            {
                if (text[j][1] == text[j + 1][1])
                {
                    if (text[j][2] > text[j + 1][2])
                    {
                        wordCopy(temp, text[j]);
                        wordCopy(text[j], text[j + 1]);
                        wordCopy(text[j + 1], temp);
                    }
                }
                else if (text[j][1] > text[j + 1][1])
                {
                    wordCopy(temp, text[j]);
                    wordCopy(text[j], text[j + 1]);
                    wordCopy(text[j + 1], temp);
                }
            }
    }
    free(temp);
}

void wordCopy(char* text, char*word)
{
    int i;
    for (i = 0; i < 15; i++)
        text[i] = word[i];
}
