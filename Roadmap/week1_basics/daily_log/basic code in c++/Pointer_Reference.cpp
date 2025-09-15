#include <iostream>
using namespace std;

// call by value
void normFunc(int x)
{
    x = 10;
}

// call by reference
void referFunc(int &x)
{
    x = 10;
}

// call by pointer
void pointFunc(int *x)
{
    *x = 10;
}

int main(int argc, char **argv)
{
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    normFunc(num1);   // pass by value : send copy value of num1 into x in normFunc()
    referFunc(num2);  // pass by reference : x is the new nick name of num2 which means x is num2
    pointFunc(&num3); // pass by value : send copy address of num3 into x in pointFunc()

    // call by value doesn't change value in num1
    cout << num1 << " become to " << num1 << endl;

    // call by reference change value in num2 because x is num2
    cout << num2 << " become to " << num2 << endl;

    // call by pointer change value in num3 because x is pointer that refer to num3
    cout << num3 << " become to " << num3 << endl;
    return 0;
}