#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

class ClassSystem {
public:
    Student class_of_s[300];
    int size;
    void addStudent(Student s);
    void addClassNumber();
    void signIn(string name);
    ClassSystem() { size = 0; };
    Student getStudentById(int i);
    Student getStudentByName(string name);
};