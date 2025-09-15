#include <iostream>

class Solution
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = l1->val + l2->val;
        ListNode *head = new ListNode(sum % 10);
        ListNode *link = head;
        while (l1 || l2)
        {
            sum /= 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            if (l1 || l2 || sum > 0)
            {
                sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
                ListNode *newNode = new ListNode(sum % 10);
                link->next = newNode;
                link = newNode;
            }
        }
        return head;
    }
};