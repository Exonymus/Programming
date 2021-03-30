#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <alloca.h>
#ifndef TEST
int main()
{
    int n, i, j;
    char** text;
    int* length;
    printf("Введите кол-во слов: ");
    check(&n);
    length = (int*) malloc( n * sizeof(int*));
    text = (char**) malloc( n * sizeof(char*));
    for (i = 0; i < n; i++)
        text[i] = (char*) malloc( 8 * sizeof(char));
    
    printf("Введите слова:\n");
    for (i = 0; i < n; i++)
    {
        gets(text[i]);
        text[i] += ' ';
        length[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 8; j++)
            if (text[i][j] != ' ')
                length[i]++;
            else
                break;
    }

    if (sort(text, n, length) == 1)
        for (i = 0; i < n; i++)
            printf("%s ", text[i]);
    else
        printf("Преобразовать строку невозможно\n");
    for (i = 0; i < n; i++)
        free(text[i]);
    free(length);
    free(text);
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
            else
                valid = 1;
        }
}
#endif

int sort(char** base, int n, int* length)
{
    int result = 0, i, j;
    int** graph;
    int* visited, * path;
    
    graph = (int**) malloc( n * sizeof(int*));
    visited = (int*) malloc( n * sizeof(int*));
    path = (int*) malloc( n * sizeof(int*));
    for (i = 0; i < n; i++)
        graph[i] = (int*) malloc( n * sizeof(int));
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (base[i][length[i]] == base[j][0])
                graph[i][j] = 1;
            else
                graph[i][j] = 0;
            if (i == j)
                graph[i][j] = 0;
        }
    if (gamilton(1, graph, path, n, 0, visited) != 0)
        result = 1;
    else
        result = 0;
    for (i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    return result;
}

int gamilton(int k, int** a, int* path, int n, int v0, int* c)
{
    int v, q1 = 0;
    for (v = 0; v < n && v != q1; v++)
    {
        if (a[v][path[k-1]] != 0 || a[path[k-1]][v] != 0)
        {
           if (k == n && v == v0)
               q1 = 1;
           else if (c[v] == -1)
           {
               c[v] = k;
               path[k] = v;
               q1 = gamilton(k + 1, a, path, n, v0, c);
               if (q1 == 0)
                   c[v] = -1;
           }
           else continue;
        }
    }
    return q1;
}
