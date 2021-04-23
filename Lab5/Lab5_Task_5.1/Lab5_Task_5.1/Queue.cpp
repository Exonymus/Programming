#include "Queue.hpp"

void Queue :: push(int a)
{
    Node *temp = new Node;
    temp->field = a;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

int Queue :: pop()
{
    if (tail == head)
    {
        int number = tail->field;
        delete tail;
        tail = head = nullptr;
        return number;
    }
    
    int number;
    Node *current = head;
    Node *previous = nullptr;

    while(current->next != NULL)
    {
      previous = current;
      current = current->next;
    }
    
    tail = previous;
    previous->next = NULL;
    number = current->field;
    return number;
}

bool Queue :: isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;

}

