#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Algorithm:  1. Declare vector of int vector for collecting result vector
            2. Sort input vector (nums) for this algorithms (passing the duplicate)
            3. Declare and define n for store value of nums.size()
            4. Loop through the vector (nums) from start to end
                - check this nums[i] is duplicate of last nums[i] ?
                    - pass the loop to next
                - define index of 2nd,3rd elements
                    - left = i+1, right = n-1 {[1],[2],3,4,5,[6]} -> [1] : 1st, [2] : 2nd, [6] : 3rd
                - Loop find vecter for pushing
                    - define sum = nums[i] + nums[left] + num[right]
                    - if sum = 0
                        - push {nums[i],nums[left],nums[right]} into vector
                        - loop for pass duplicate of 2nd : left+1 {[1],[2],2,3,4,5,6,7,[7]} -> {[1],2,2,[3],4,5,6,7,[7]}
                        - loop for pass duplicate of 3rd : right-1 {[1],2,2,[3],4,5,6,7,[7]} -> {[1],2,2,[3],4,5,[6],7,7}
                    - if sum < 0 : left+1
                    - if sum > 0 : right-1
            5. Return vector of int vector
Time complexity: O(n^2)
Space complexity: O(1)
*/

/*
    nums.size() will return unsigned data type (size_t)

    unsigned : positive integer (>= 0), so can't be negative
        - unsigned char : 0 to 255
        - unsigned int : 0 to 4b (32-bit)
        - unsigned long long : 0 to 1.8e19 (64-bit)
    if unsigned = 0 and minus 1 which be a negative value but it can't,
    so it will reverse to maximum value called underflow

    then whenever use size() should store it and cast (convert) it to integer
    : int n = (int) nums.size();
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        const int n = (int)nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // if find duplicate of first element, pass it

            // first element : nums[i]
            int left = i + 1, right = n - 1; // second and third : nums[left], nums[right]
            while (left < right)             // left have to less than right
            {
                int sum = nums[i] + nums[left] + nums[right]; // find sum of elements
                if (sum == 0)
                { // if sum = 0, push it into vector
                    result.push_back({nums[i], nums[left], nums[right]});
                    int leftV = nums[left], rightV = nums[right]; // nums[left], nums[right] which are already used
                    while (left < right && leftV == nums[left])
                    {
                        left++;
                    } // if find duplicate of second element, pass it
                    while (left < right && rightV == nums[right])
                    {
                        right--;
                    } // if find duplicate of third element, pass it
                }
                else if (sum < 0)
                    left++; // if sum less than 0, should increase value of element (left+1)
                else
                    right--; // if sum more than 0, should decrease value of element (right-1)
            }
        }
        return result;
    }
};