#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        string stack = "";
        string palindrome = "";
        for (char c : s)
        {
            if (count(s.begin(), s.end(), c) == s.size())
                return s;
            else if (count(s.begin(), s.end(), c) > round(s.size() / 2.0))
            {
                for (int i = 0; i < count(s.begin(), s.end(), c); i++)
                    palindrome += c;
                return palindrome;
            }
            string sub = "";
            size_t pos = stack.find(c);
            if (pos != string::npos)
            {
                stack += c;
                int top = stack.size();
                while (pos != top)
                {
                    sub += stack[--top];
                    int left = 0;
                    int right = sub.size() - 1;
                    if (isPalindrome(sub))
                    {
                        palindrome = sub.size() >= palindrome.size() ? sub : palindrome;
                    }
                }
            }
            else
            {
                stack += c;
                sub = c;
                palindrome = sub.size() >= palindrome.size() ? sub : palindrome;
            }
        }
        return palindrome;
    }
};

int main()
{
    Solution s;
    cout << "palind : " << s.longestPalindrome("aabbb");
}