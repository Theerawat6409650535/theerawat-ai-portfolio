#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *temp = head;
        ListNode *prev = head;

        // find size of list
        while (temp)
        {
            temp = temp->next;
            size++;
        }

        int index = size - n;
        temp = head;
        if (index == 0)
        {
            head = head->next;
            delete temp;
            return head;
        }
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
        return head;
    }
};