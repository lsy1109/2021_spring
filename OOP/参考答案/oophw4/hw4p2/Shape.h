#pragma once
#include <iostream>
using namespace std;

class Shape {
public:
    Shape() {};
    virtual double getArea() {};
};

class Rectangle: public Shape {
    double w, h;
public:
    Rectangle(double width, double height);
    double getArea() override;
};

class Circle: public Shape {
    double r;
public:
    Circle(double radius);
    double getArea() override;
};