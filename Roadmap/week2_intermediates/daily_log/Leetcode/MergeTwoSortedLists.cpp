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

// my first code
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         if (!list1 && list2)
//             return list2;
//         else if (!list2 && list1)
//             return list1;
//         else if (!list1 && !list2)
//             return nullptr;
//         ListNode *head;
//         if (list1->val <= list2->val)
//         {
//             head = list1;
//             list1 = list1->next;
//             if (!list1)
//             {
//                 head->next = list2;
//                 return head;
//             }
//         }
//         else
//         {
//             head = list2;
//             list2 = list2->next;
//             if (!list2)
//             {
//                 head->next = list1;
//                 return head;
//             }
//         }
//         ListNode *temp = head;
//         while (list1 && list2)
//         {
//             if (list1->val > list2->val)
//             {
//                 temp->next = list2;
//                 list2 = list2->next;
//                 temp = temp->next;
//                 if (!list2)
//                 {
//                     temp->next = list1;
//                     return head;
//                 }
//             }
//             else
//             {
//                 temp->next = list1;
//                 list1 = list1->next;
//                 temp = temp->next;
//                 if (!list1)
//                 {
//                     temp->next = list2;
//                     return head;
//                 }
//             }
//         }
//         return head;
//     }
// };

/*
Algoirthm : 1. Create dummy node
                - a default node to avoid handling head separately
            2. Create linker pointer
                - points to dummy node
                - used to link nodes together and advance
            3. Loop until l1 or l2 is nullptr
                3.1 if l1->val < l2->val
                    3.1.1 linker->next = l1
                    3.1.2 move l1 forward
                3.2 if l2->val < l1->val
                    3.2.1 linker->next = l2
                    3.2.2 move l2 forward
                3.3 move linker forward
            4. Attach remaining list (if any)
                4.1 if l1 is nullptr : linker->next = l2
                4.2 if l2 is nullptr : linker->next = l1
            5. return merged list (dummy.next)

Time complexity : O(max(m,n)), Space complexity : O(1)
*/

// after
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // create head of merged list
        ListNode dummy(0); // mock head
        ListNode *linker = &dummy;

        // loop for merging lists
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                linker->next = list1;
                list1 = list1->next;
            }
            else
            {
                linker->next = list2;
                list2 = list2->next;
            }
            linker = linker->next;
        }

        // if l1 or l2 is left
        linker->next = list1 ? list1 : list2;

        // return merged list
        return dummy.next;
    }
};

int main()
{
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2, node1);
    ListNode *list1 = new ListNode(1, node2);

    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(3, node3);
    ListNode *list2 = new ListNode(1, node4);

    Solution s;
    ListNode *newList = s.mergeTwoLists(list1, list2);
    while (newList)
    {
        ListNode *temp = newList;
        cout << newList->val << " ";
        newList = newList->next;
        delete temp;
    }
}