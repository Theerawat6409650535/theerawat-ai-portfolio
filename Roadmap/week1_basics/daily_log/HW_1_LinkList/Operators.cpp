#include <iostream>
#include "ModifiedLinkedList.h"
#include "Operators.h"

void Operators::makeList(double data[], int size)
{
    if (this->isEmpty())
    {
        lists[++topList] = new ModifiedLinkedList();
        for (int i = 0; i < size; i++)
        {
            lists[topList]->add(data[i]);
        }
    }
    else
    {
        std::cerr << "Error: List stack isn't empty.";
    }
}

void Operators::cutList(int pos)
{
    // Clone top list
    ModifiedLinkedList *tempList = lists[topList]->clone();

    // Clear top list
    this->clearTopList();

    // Create new lists
    ModifiedLinkedList *part1 = new ModifiedLinkedList();
    ModifiedLinkedList *part2 = new ModifiedLinkedList();

    // Cut tempList into new lists
    tempList->cut(pos, part1, part2);

    // Push new lists into list stack
    lists[topList++] = part1;
    lists[topList] = part2;

    // Delete tempList
    delete tempList;

    // Operators
    ops[++topOp] = new Op(pos);
}

void Operators::cloneList()
{
    // Clone top list
    ModifiedLinkedList *tempList = lists[topList]->clone();

    // Push clone into top of list stack
    lists[++topList] = tempList;

    // Push operator into operator stack
    ops[++topOp] = new Op(-1);
}

void Operators::printCurrentList()
{
    lists[topList]->print();
}

void Operators::printHistory()
{
    // Print all member of list stack
    std::cout << "===The lists in the history stack: ===" << std::endl;
    for (int i = topList; i > -1; i--)
    {
        std::cout << "Index in the stack: " << i << std::endl;
        lists[i]->print();
    }
    std::cout << "============================================" << std::endl;

    // Print all operator of operator stack
    std::cout << "===The operators in the history stack: ===" << std::endl;
    for (int i = topOp; i > -1; i--)
    {
        std::cout << "Index in the stack: " << i << std::endl;
        std::cout << "Operator: " << ops[i]->op << " at position : " << ops[i]->pos << std::endl;
    }
    std::cout << "============================================" << std::endl;
}

void Operators::undo()
{
    // Undo cut
    if (ops[topOp]->op == "CUT")
    {
        // Clone & Clear top lists
        ModifiedLinkedList *tempList1 = lists[topList]->clone();
        this->clearTopList();
        ModifiedLinkedList *tempList2 = lists[topList]->clone();
        this->clearTopList();

        // Merge lists
        ModifiedLinkedList *newList = tempList2->mergeWith(tempList1);

        // Push new list into list stack
        lists[topList] = newList;
    }

    // Undo clone
    else if (ops[topOp]->op == "CLONE")
    {
        this->clearTopList();
    }

    // Clear top operator
    this->clearTopOp();
}

void Operators::clearTopList()
{
    lists[topList]->removeAllNodes();
    delete lists[topList];
    lists[topList--] = nullptr;
}

void Operators::clearTopOp()
{
    delete ops[topOp];
    ops[topOp--] = nullptr;
}

bool Operators::isEmpty()
{
    // Check List stack is empty?
    return topList != (maxTopLists - 1);
}