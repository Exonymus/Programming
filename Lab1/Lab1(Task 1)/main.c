//
//  main.c
//  Lab1
//
//  Created by Игорь Аралин on 21.02.21.
//

#include <stdio.h>
#include <stdlib.h>

int check(int *a);

int main(int argc, const char * argv[]) {
    int k,l,m,n,
        indanger = 0;
    
    printf("Введите k: ");
    if (check(&k)) return 1;
    printf("Введите l: ");
    if (check(&l)) return 1;
    printf("Введите m: ");
    if (check(&m)) return 1;
    printf("Введите n: ");
    if (check(&n)) return 1;
    
    if (abs(m-k) == 2 && abs(l - n) == 1) indanger = 1;
    if (abs(m-k) == 1 && abs(l - n) == 2) indanger = 1;
    
    if (indanger)
    {
        printf("Конь угрожает фигуре.\n");
    }
    else
    {
        printf("Конь не угрожает фигуре.\n");
    }
    
    return 0;
}

int check(int *a)
{
    if (scanf("%d", &*a) != 1)
    {
        printf("Ввод не верен\n");
        return 1;
    }
    return 0;
}
