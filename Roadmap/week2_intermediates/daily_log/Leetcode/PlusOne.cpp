#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // vector<int> res;
        // int n = (int)digits.size();
        // int rNum = 0;
        // int exp = 1;
        // for (int i=n-1;i>=0;i--) {
        //     rNum += digits[i] * exp;
        //     exp *= 10;
        // }
        // rNum++;
        // while (rNum!=0 || exp!=1)
        // {
        //     exp /= exp>rNum ? 10:1;
        //     res.push_back(rNum/exp);
        //     rNum %= exp;
        // }
        // return res;
        int n = (int)digits.size();
        digits[n - 1] += 1;
        if (digits[n - 1] > 9)
        {
            int i = n - 1;
            while (digits[i] > 9)
            {
                cout << "d[i] : " << digits[i] << endl;
                digits[i--] %= 10;
                // cout << "d[i] : " << digits[i] << endl;
                if (i < 0)
                {
                    digits.insert(digits.begin(), 1);
                    i++;
                }
                else
                    digits[i] += 1;
            }
        }
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> v = {9};
    s.plusOne(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}