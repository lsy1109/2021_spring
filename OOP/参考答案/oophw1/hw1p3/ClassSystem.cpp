#include "ClassSystem.h"
#include <iostream>
#include <string>
using namespace std;

void ClassSystem::addStudent(Student s){
    s.id = this->size;
    this->class_of_s[this->size++] = s;
}

Student ClassSystem::getStudentById(int i){
    return this->class_of_s[i];
}

Student ClassSystem::getStudentByName(string name){
    for (int i = 0; i < this->size; ++i){
        if (this->class_of_s[i].getName() == name){
            return this->class_of_s[i];
        }
    }
}

void ClassSystem::addClassNumber(){
    for (int i = 0; i < this->size; ++i){
        this->class_of_s[i].absent++;
    }
}

void ClassSystem::signIn(string name){
    Student stu = getStudentByName(name);
    //cout << stu.getPresentTimes() << endl;
    int i = stu.id;
    this->class_of_s[i].present++;
    //cout << stu.getName() << " present " << stu.getPresentTimes() << endl;
    this->class_of_s[i].absent--;
}