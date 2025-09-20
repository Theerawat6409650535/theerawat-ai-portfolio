#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        string num = to_string(x);
        string newNum = "";
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if (num[i] >= '0' || num[i] <= '9')
                newNum += num[i];
        }
        try
        {
            return x < 0 ? stoi(newNum) * -1 : stoi(newNum);
        }
        catch (const std::exception &e)
        {
            return 0;
        }
    }
};

int main()
{
    cout << -12 % 10;
}