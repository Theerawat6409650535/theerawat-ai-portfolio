#include <iostream>
#include "ModifiedLinkedList.h"
#include <math.h>

void ModifiedLinkedList::add(double n)
{
    Node *node = new Node(n);
    node->next = head;
    head = node;
    counter++;
    if (counter % 2 == 0 || counter == 1)
    {
        mid = node;
        for (int i = 1; i < round(counter / 2.0); i++)
        {
            mid = mid->next;
        }
    }
}

void ModifiedLinkedList::getData(double *&array, int &size)
{
    size = counter;
    array = new double[size];
    Node *node = head;
    int i = 0;
    while (node)
    {
        array[i++] = node->data;
        node = node->next;
    }
}

ModifiedLinkedList *ModifiedLinkedList::clone()
{
    ModifiedLinkedList *cloneObj = new ModifiedLinkedList();
    double *array;
    int size;
    this->getData(array, size);
    for (int i = size - 1; i >= 0; i--)
    {
        cloneObj->add(array[i]);
    }
    delete[] array;
    return cloneObj;
}

ModifiedLinkedList *ModifiedLinkedList::mergeWith(ModifiedLinkedList *obj)
{
    ModifiedLinkedList *cloneObj = obj->clone();
    ModifiedLinkedList *cloneThis = this->clone();
    Node *temp = cloneObj->head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = cloneThis->head;
    cloneThis->head = cloneObj->head;
    cloneThis->counter += cloneObj->counter;
    cloneThis->mid = cloneThis->head;
    for (int i = 1; i < round((cloneThis->counter) / 2.0); i++)
    {
        cloneThis->mid = cloneThis->mid->next;
    }
    delete cloneObj;
    return cloneThis;
}

int ModifiedLinkedList::cut(int pos, ModifiedLinkedList *&part1, ModifiedLinkedList *&part2)
{
    double *array;
    int size;
    this->getData(array, size);
    while (size)
    {
        if (size > pos)
        {
            part2->add(array[--size]);
        }
        else
        {
            part1->add(array[--size]);
        }
    }
    delete[] array;
    return 0;
}

void ModifiedLinkedList::removeAllNodes()
{
    while (head)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
        counter--;
    }
    mid = NULL;
}

void ModifiedLinkedList::print()
{
    Node *node = head;
    for (int i = 0; i < counter; i++)
    {
        if (node == mid)
        {
            std::cout << "[" << node->data << "] ";
        }
        else
        {
            std::cout << node->data << " ";
        }
        node = node->next;
    }
    std::cout << ", Mid = :" << mid->data << std::endl;
}
