#include <iostream>
#include "ModifiedLinkedList.h"
#include "Operators.h"

void Operators::makeList(double data[], int size)
{
    if (!this->isEmpty())
    {
        ModifiedLinkedList *newlist = new ModifiedLinkedList;

        *lists = newlist;
    }
    else
    {
    }
}

void Operators::isEmpty()
{
}