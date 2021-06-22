#pragma once
#include<string>
#include<iostream>
using namespace std;

class LoadStrategy {
public:
    virtual float input() = 0;							
};


class NumberLoadStrategy : public LoadStrategy {	
public:
    float input() {
        float m;
        cin >> m;
        return m;
    }
};

class WordLoadStrategy : public LoadStrategy {
public:
    float input() {
        float s = 0;
        string d;
        cin >> d;
        int digit;
        while (d != "#") {
            if (d == "one") digit = 1;
            else if (d == "two") digit = 2;
            else if (d == "three") digit = 3;
            else if (d == "four") digit = 4;
            else if (d == "five") digit = 5;
            else if (d == "six") digit = 6;
            else if (d == "seven") digit = 7;
            else if (d == "eight") digit = 8;
            else if (d == "nine") digit = 9;
            else if (d == "zero") digit = 0;
            s = s * 10 + digit;
            cin >> d;
        }
        return s;
    }
};
