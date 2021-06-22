#include "StudentCollection.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

StudentCollection::StudentCollection() {
    //len = 0;
}

istream& operator>> (istream& in, StudentCollection& dst) {
    string info;
    in >> info;
    int first = info.find_first_of('-');
    string name = info.substr(0, first);
    int last = info.find_last_of('-');
    string subj = info.substr(first + 1, last - first - 1);
    string score_str = info.substr(last + 1, info.length() - last - 1);

    bool found = false;
    int i;
    for (i = 0; i < dst.students.size(); i++) {
        if (dst.students[i].get_name() == name) {
            found = true;
            break;
        }
    }
    if (found) {
        if (subj == "Chinese") dst.students[i].scores[1] = atoi(score_str.c_str());
        if (subj == "Math") dst.students[i].scores[2] = atoi(score_str.c_str());
        if (subj == "English") dst.students[i].scores[3] = atoi(score_str.c_str());
        dst.students[i].scores[0] = dst.students[i].get_chi() + dst.students[i].get_mat() + dst.students[i].get_eng();
    }
    else {
        Student stu = Student(name);
        if (subj == "Chinese") stu.scores[1] = atoi(score_str.c_str());
        if (subj == "Math") stu.scores[2] = atoi(score_str.c_str());
        if (subj == "English") stu.scores[3] = atoi(score_str.c_str());
        stu.scores[0] = stu.get_chi() + stu.get_mat() + stu.get_eng();
        dst.students.push_back(stu);
    }
    return in;
}

ostream& operator<< (ostream& out, const StudentCollection& src) {
    for (int i = src.students.size() - 1; i >= 0; i--) {
        out << src.students[i] << "\n";
    }
    return out;
};

void StudentCollection::sortByScore() {
    sort(this->students.begin(), this->students.end());
}

Student StudentCollection::operator[] (string name) {
        for (int i = 0; i < this->students.size(); i++) {
            if (this->students[i].get_name() == name)
                return this->students[i];
        }
    }