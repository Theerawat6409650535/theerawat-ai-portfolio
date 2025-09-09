#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string first_name;
    string last_name;
    int student_id;

    Student()
    {
        first_name = "";
        last_name = "";
        student_id = 0;
    }

    void setName(string fname, string lname)
    {
        first_name = fname;
        last_name = lname;
    }
};

int main(int argc, char **argv)
{
    Student *student_1 = new Student;    // allocate memory in heap
    Student *students = new Student[10]; // allocate memory in heap

    // set initializer by constructor
    cout << "My name is " << student_1->first_name << " " << student_1->last_name << endl;

    // set name by method setName
    student_1->setName("Theerawat", "Seetarahrtay");
    cout << "My name is " << student_1->first_name << " " << student_1->last_name << endl;

    delete student_1;  // after used, always should deallocate memory in heap
    delete[] students; // after used, always should deallocate memory in heap
    return 0;
}