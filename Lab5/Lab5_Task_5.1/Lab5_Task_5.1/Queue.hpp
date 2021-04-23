#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int field;
    Node *next;
};

class Queue
{
    public:
        Node *head, *tail;
    public:
        Queue()
        {
            head = NULL;
            tail = NULL;
        }

        void push(int a);
        int pop();
        bool isEmpty();
};
#endif
