#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string sub = "";
        int max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            size_t pos = sub.find(s[i]);
            if (pos == string::npos)
            {
                sub += s[i];
            }
            else
            {
                pos == 0 ? sub.erase(0, 1) : sub.erase(0, pos + 1);
                sub += s[i];
            }
            max = max < sub.size() ? sub.size() : max;
        }
        return max;
    }
};
