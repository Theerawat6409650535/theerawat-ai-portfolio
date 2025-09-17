#include <iostream>
#include <vector>
using namespace std;

/*
Algorithm:  1. Initialize an index `uniqueIndex` to track the position of the last unique element.
            2. Loop through the array from start to end:
                2.1 If nums[i] != nums[uniqueIndex], it means nums[i] is a new unique element.
                    - Increment uniqueIndex
                    - Place nums[i] at nums[uniqueIndex]
            3. After the loop:
                - If the array is empty, return 0
                - Otherwise, return uniqueIndex + 1 (the total number of unique elements)
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int uniqueIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[uniqueIndex] != nums[i])
            {
                nums[++uniqueIndex] = nums[i];
            }
        }
        return nums.empty() ? 0 : uniqueIndex + 1;
    }
};
