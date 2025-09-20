#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = (int)s.size();
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
                count++;
            else if (s[i] == ' ' && count > 0)
                break;
        }
        return count;
    }
};
