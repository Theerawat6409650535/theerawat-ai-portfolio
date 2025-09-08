#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **agrv)
{
    // Data types

    // Fundamental types
    bool is_available = true; // Booleans : True, False
    char letter = 'A';        // Characters : a letter with single quote
    short n1 = 1;             // Integers in short form
    int n2 = 2;               // Integers in normal form
    long n3 = 3;              // Integers in large form
    float n4 = 1.1;           // Floating-point in short form
    double n5 = 2.2;          // Floating-point in normal form
    long double n6 = 3.3;     // Floating-point in large form
    enum Day
    {
        SUN,
        MON,
        TUE,
        WED,
        THU,
        FRI,
        SAT
    }; // Enumeration : collection of constant integer

    // Special types
    int *ptr1;                                   // Pointers : variable holds value of such an address
    int &ptr2 = n2;                              // Reference : variable refer to another variable
    int list[] = {1, 2, 3, 4, 5};                // Array : collection of elements as the same type
    char s1[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Strings from array of character
    string s2 = "Hello";                         // Strings from string class (#include <string>)
    struct Student
    {
        string first_name;
        string last_name;
        string student_id;
    }; // Structures : aggregation of involving elements each other
    return 0;
}