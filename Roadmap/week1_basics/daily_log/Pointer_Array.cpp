#include <iostream>
using namespace std;

// access in array form
void setZero(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

// access in pointer form
//  void setZero(int *arr, int size)
//  {
//      for (int i = 0; i < size; i++)
//      {
//          *arr = 0;
//          arr++;
//      }
//  }

void print(int *arr, int size)
{
    cout << "Elements in array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
}

int main(int argc, char **argv)
{
    int nums[10];
    int size = 10;
    // pass array into pointer (access first element in default)
    setZero(nums, size);
    print(nums, size);
}