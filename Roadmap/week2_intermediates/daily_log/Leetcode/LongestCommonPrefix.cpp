#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        int i = 0;
        int j = 0;
        while (strs.size())
        {
            prefix += strs[i][j];
            int count = 0;
            for (string s : strs)
            {
                size_t pos = s.find(prefix, 0);
                if (pos != string::npos && pos <= j)
                {
                    count++;
                }
            }
            if (count == 1)
            {
                strs.erase(strs.begin() + i);
                prefix = "";
                i++;
            }
            else if (count > 1)
            {
                j++;
            }
            else
            {
                prefix.pop_back();
                break;
            }
        }
        return prefix;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs);
    return 0;
}