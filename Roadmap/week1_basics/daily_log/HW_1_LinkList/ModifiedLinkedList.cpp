#include <iostream>
#include "ModifiedLinkedList.h"
#include <math.h>

void ModifiedLinkedList::add(double n)
{
    Node *node = new Node(n);
    counter++;
    node->next = head;
    head = node;
    if (counter % 2 == 0 || counter == 1)
    {
        mid = node;
        for (int i = 1; i < round(counter / 2.0); i++)
        {
            mid = mid->next;
        }
    }
}

void ModifiedLinkedList::getData(double *&data, int &size)
{
    size = counter;
    data = new double[size];
    Node *node = head;
    int i = 0;
    while (node->next)
    {
        data[i++] = node->data;
        node = node->next;
    }
}

ModifiedLinkedList *ModifiedLinkedList::clone()
{
    ModifiedLinkedList *cloneObj = new ModifiedLinkedList();
    double *data;
    int size;
    this->getData(data, size);
    for (int i = 0; i < size; i++)
    {
        cloneObj->add(data[i]);
    }
    delete[] data;
    return cloneObj;
}

ModifiedLinkedList *ModifiedLinkedList::mergeWith(ModifiedLinkedList *obj)
{
    ModifiedLinkedList *objList = obj->clone();
    ModifiedLinkedList *newList = this->clone();
    Node *temp = objList->head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newList->head;
    newList->head = obj->head;
    delete objList;
    return newList;
}

int ModifiedLinkedList::cut(int pos, ModifiedLinkedList *&part1, ModifiedLinkedList *&part2)
{
    if (pos < 1 || pos > counter)
    {
        return -1;
    }
    else
    {
        ModifiedLinkedList *part1 = new ModifiedLinkedList;
        ModifiedLinkedList *part2 = new ModifiedLinkedList;
        double *data;
        int size;
        this->getData(data, size);
        for (int i = 0; i < size; i++)
        {
            if (i < pos)
            {
                part1->add(data[i]);
            }
            else
            {
                part2->add(data[i]);
            }
        }
        return 0;
    }
}

void ModifiedLinkedList::removeAllNodes()
{
    while (head)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
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
    }
    std::cout << ", Mid = :" << mid->data;
}
