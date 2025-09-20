#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // Linear search (O(n))

        // bool isFound = false;
        // int i=0;
        // while (i<nums.size()) {
        //     if (nums[i]==target) {
        //         isFound = true;
        //         break;
        //     } else if (nums[i]>target) return i;
        //     i++;
        // }

        // Binary search (O(log n))

        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (high > low)
        {
            mid = (low + high) / 2;
            if (target < nums[mid])
                high = mid - 1;
            else if (target > nums[mid])
                low = mid + 1;
            else
                return mid;
        }
        return target > nums[low] ? low + 1 : low;
    }
};