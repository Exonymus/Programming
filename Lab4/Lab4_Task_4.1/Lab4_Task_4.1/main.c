#include "functions.h"
#ifndef TEST
int main()
{
    int n, i, j;
    char** text;
    int* length,* path;
    printf("Введите кол-во слов: ");
    check(&n);
    length = (int*) malloc( n * sizeof(int));
    memoryCheck(length);
    path = (int*) malloc( n * sizeof(int));
    memoryCheck(path);
    text = (char**) malloc( n * sizeof(char*));
    if (text == NULL)
        exit(1);
    
    for (i = 0; i < n; i++)
    {
        text[i] = (char*) malloc( 9 * sizeof(char));
        if (text[i] == NULL)
            exit(1);
    }
    
    printf("Введите слова:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%8s", text[i]);
        length[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 8; j++)
            if (text[i][j] != '\0')
                length[i]++;
            else
                break;
    }

    if (sort(text, n, length, path) == 1)
    {
        if (text[path[0]][length[path[0]]] == text[path[1]][0])
            for (i = 0; i < n; i++)
                printf("%s ", text[path[i]]);
        else
            for (i = n - 1; i >= 0; i--)
                printf("%s ", text[path[i]]);
    }
    else
        printf("Преобразовать строку невозможно");
    
    for (i = 0; i < n; i++)
        free(text[i]);
    free(path);
    free(length);
    free(text);
    printf("\n");
    return 0;
}

void check(int *a)
{
    int valid = 0;
    char inpStr[1024];
    char buffer = 0;
    while(!valid)
        {
            buffer = 0;
            if((scanf("%1023[^\n]%c",inpStr,&buffer) != 2) || buffer != '\n')
            {
                if(printf("Ввод не верен!\nПовторите ввод: "))
                    getchar();
            }
            else
            if((sscanf(inpStr,"%d%c",&*a,&buffer) != 1) || buffer != '\n')
                printf("Ввод не верен!\nПовторите ввод: ");
            else if (*a <= 1)
                printf("Ввод не верен!\nПовторите ввод: ");
            else
            valid = 1;
        }
}
#endif

int sort(char** base, int n, int* length, int* path)
{
    int result = 0, i, j, startPoint = 0;
    int** graph;
    int* stepNum;
    
    graph = (int**) malloc( n * sizeof(int*));
    if (graph == NULL)
        exit(1);
    stepNum = (int*) malloc( n * sizeof(int));
    memoryCheck(stepNum);
    
    for (i = 0; i < n; i++)
    {
        graph[i] = (int*) malloc( n * sizeof(int));
        if (graph[i] == NULL)
            exit(1);
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
            if (base[i][length[i]] == base[j][0])
                graph[i][j] = 1;
        }
        graph[i][i] = 0;
    }
    
    for (j = 0; j < n; j++)
        stepNum[j] = -1;
    path[0] = 0;
    stepNum[startPoint] = startPoint;
    
    if (gamilton(1, graph, path, n, startPoint, stepNum) != 0)
        result = 1;
    else
        result = 0;
    
    for (i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    free(stepNum);
    return result;
}

void memoryCheck(int *a)
{
    if (a == NULL)
        exit(1);
}

int gamilton(int k, int** graph, int* path, int n, int startPoint, int* stepNum)
{
    int i, check = 0;

    for(i = 0; i < n && !check; i++)
    {
        if(graph[i][path[k - 1]] || graph[path[k - 1]][i])
        {
            if (k == n &&  i == startPoint )
                check = 1;
            else if (stepNum[i] == -1)
            {
                stepNum[i] = k;
                path[k] = i;
                check = gamilton (k + 1, graph, path, n, startPoint, stepNum);
                if (!check) stepNum[i] = -1;
            }
            else continue;
        }
    }
    return check;
}
