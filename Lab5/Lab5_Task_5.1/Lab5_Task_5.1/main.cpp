#include "functions.h"
#ifndef TEST

int main()
{
    Queue q;
    cout << "Введите кол-во элементов в очереди: ";
    int n;
    check(&n);
    while (n <= 1)
    {
        cout << "Ввод неверен!\nПовторите ввод: ";
        check(&n);
    }
    cout << "Ввод чисел:\n";
    for (int i = 0; i < n; i++)
    {
        int a;
        check(&a);
        q.push(a);
    }

    reverse(n, q);
    
    cout << "Новая очередь: ";
    for (int i = 0; i < n; i++)
    {
        cout << q.pop() << " ";
    }
    cout << "\n";
    
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

void reverse(int n, Queue &q)
{
    int *arr = new int[n];
    if (arr == NULL)
        exit(1);
    
    for (int i = (n - 1); i >= 0; i--)
    {
        arr[i] = q.pop();
    }
    
    if (!q.isEmpty())
        exit(1);
    
    for (int i = 0; i < n; i++)
        q.push(arr[i]);
    
    delete[] arr;
}
