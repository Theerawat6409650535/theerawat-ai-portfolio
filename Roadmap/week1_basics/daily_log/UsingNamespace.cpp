#include <iostream>
#include <string>
using namespace std;

namespace Student
{
    int id = 0;
    string name = "Bob";
};

namespace Teacher
{
    int id = 1;
    string name = "Bee";
}

// Problem when using namespace
using namespace Student;
using namespace Teacher;

int main(int argc, char **argv)
{
    // cout << id; // name collision because both namespace has the same variable name which is "id"

    // Solution
    cout << Student::id << endl;
    cout << Teacher::id << endl;
    return 0;
}
