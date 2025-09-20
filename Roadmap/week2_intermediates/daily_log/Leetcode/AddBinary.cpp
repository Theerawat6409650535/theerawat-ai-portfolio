#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";
        int sA = ((int)a.size());
        int sB = ((int)b.size());
        bool ad = false;
        while (sA != 0 || sB != 0 || ad)
        {
            int sum = (sA > 0 ? a[--sA] - '0' : 0) + (sB > 0 ? b[--sB] - '0' : 0) + (ad ? 1 : 0);
            res = char((sum % 2) + '0') + res;
            ad = sum > 1 ? true : false;
        }
        return res;
    }
};

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;
        int sA = ((int)a.size());
        int sB = ((int)b.size());
        bool ad = false;
        int i = 0;
        while (i < sA || i < sB || ad)
        {
            int sum = (i < sA ? a[i] - '0' : 0) + (i < sB ? b[i] - '0' : 0) + (ad ? 1 : 0);
            res.push_back(char((sum % 2) + '0'));
            ad = sum > 1 ? true : false;
            i++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};