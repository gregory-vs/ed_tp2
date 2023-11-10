#include <iostream>
#include "List.h"

void List::push(List** list, int d)
{
    List* newList = new List();

    List* last = *list;

    newList->data = d;
    newList->next = nullptr;

    if(*list == nullptr)
    {
        *list = newList;
        return;
    }

    while(last->next != nullptr)
        last = last->next;

    last->next = newList;
    return;
}



