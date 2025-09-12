#include <iostream>
#include "ModifiedLinkedList.h"
#include "Operators.h"

void Operators::makeList(double array[], int size)
{
    if (this->isEmpty()) // Check list stack is full ?
    {
        lists[++topList] = new ModifiedLinkedList(); // Add obj in list stack
        for (int i = 0; i < size; i++)
        {
            lists[topList]->add(array[i]); // Add members in the obj
        }
    }
    else
    {
        std::cerr << "Error: List stack is full!!!"; // Error message
    }
}

void Operators::cutList(int pos)
{
    // Clone top list
    ModifiedLinkedList *cloneTopList = lists[topList]->clone();

    // Clear top list
    this->clearTopList();

    // Create new lists
    ModifiedLinkedList *part1 = new ModifiedLinkedList();
    ModifiedLinkedList *part2 = new ModifiedLinkedList();

    // Cut cloneTopList into new lists
    cloneTopList->cut(pos, part1, part2);

    // Push new lists into list stack
    lists[++topList] = part1;
    lists[++topList] = part2;

    // Delete cloneTopList
    delete cloneTopList;

    // Push new operation into operator stack
    ops[++topOp] = new Op(pos);

    // Print
    std::cout << "CUT Operation has been done." << std::endl;
}

void Operators::cloneList()
{
    // Clone top list
    ModifiedLinkedList *cloneTopList = lists[topList]->clone();

    // Push cloneTopList into list stack
    lists[++topList] = cloneTopList;

    // Push new operation into operator stack
    ops[++topOp] = new Op(-1);

    // Print
    std::cout << "CLONE Operation has been done." << std::endl;
}

void Operators::printCurrentList()
{
    lists[topList]->print(); // Print top list
}

void Operators::printHistory()
{
    // Print all member in list stack
    std::cout << "===The lists in the history stack: ===" << std::endl;
    if (topList == -1)
    {
        std::cout << "[x] Nothing in this stack ..." << std::endl;
    }
    for (int i = topList; i > -1; i--)
    {
        std::cout << "Index in the stack: " << i << std::endl;
        lists[i]->print();
    }
    std::cout << "============================================" << std::endl;

    // Print all operation in operator stack
    std::cout << "===The operators in the history stack: ===" << std::endl;
    if (topOp == -1)
    {
        std::cout << "[x] Nothing in this stack ..." << std::endl;
    }
    for (int i = topOp; i > -1; i--)
    {
        std::cout << "Index in the stack: " << i << std::endl;
        if (ops[i]->op == "CUT")
        {
            std::cout << "Operator: " << ops[i]->op << " at position : " << ops[i]->pos << std::endl;
        }
        else if (ops[i]->op == "CLONE")
        {
            std::cout << "Operator: " << ops[i]->op << std::endl;
        }
    }
    std::cout << "============================================" << std::endl;
}

void Operators::undo()
{
    // Undo cut
    if (ops[topOp]->op == "CUT")
    {
        // Clone & Clear top lists
        ModifiedLinkedList *cloneFirstTopList = lists[topList]->clone();
        this->clearTopList();
        ModifiedLinkedList *cloneSecondTopList = lists[topList]->clone();
        this->clearTopList();

        // Merge lists
        ModifiedLinkedList *newTopList = cloneFirstTopList->mergeWith(cloneSecondTopList);

        cloneFirstTopList->removeAllNodes();
        cloneSecondTopList->removeAllNodes();
        delete cloneFirstTopList;
        delete cloneSecondTopList;

        // Push new list into list stack
        lists[++topList] = newTopList;

        // Print
        std::cout << "Undone [CUT] Operator ...." << std::endl;
    }

    // Undo clone
    else if (ops[topOp]->op == "CLONE")
    {
        this->clearTopList();

        // Print
        std::cout << "Undone [CLONE] Operator ...." << std::endl;
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