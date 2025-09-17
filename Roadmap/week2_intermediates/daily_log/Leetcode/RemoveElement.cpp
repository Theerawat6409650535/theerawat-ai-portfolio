#include <iostream>
#include <vector>
using namespace std;

/*
Algorithm:  1. Initialize an index `notValIndex` to track the position of the element which isn't equal to val.
            2. Loop through the array from start to end:
                2.1 If nums[i] != val, it means nums[i] is a new element.
                    - Place nums[i] at nums[notValIndex]
                    - Increment notValIndex
            3. After the loop:
                - If the array is empty, return 0
                - Otherwise, return notValIndex (the total number of elements which aren't equal to val)
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int notValIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (val != nums[i])
            {
                nums[notValIndex++] = nums[i];
            }
        }
        return nums.empty() ? 0 : notValIndex;
    }
};