#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        int low = 0, high = x, ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            long sqrt = mid * mid;
            if (sqrt <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(10000);
}