#pragma once
#include<iostream>
#include<string>
#include"Student.h"
class School
{
public:
int n;
static int num;//这个int用来记录add num；因为add num需要让每次加完了底标++；关键是，你的这int不能是const，既可以是static，也可以不加修饰；因为你此处只有一个对象而已
//注意到static的赋值不能就地赋值，需要在cpp里赋值
void add_member(Student s);//注意到你的add member是个void，因为你实际上没有把Shool对象传进去
School(int index){
    n=index;
    st=new Student[n+1];//我在这里爆了很久错，最后发现，main里面Student是大写的！！！
    //为什么我会多开一个，因为第n+1个我把他设为空学生，如果比较的函数返回了空学生，那就cout<<找不到
}
Student *st;//如何在school里创建n个student？
//构造函数school(n) 再new，这里写student* st，然后在构造函数里面st = new student[n]；关键是，我废了很大功夫写构造函数，最后发现自己是个傻子。
//因为你完全不用通过Student(string na,string ho,int index,string day)这种形式来构造，只需要先创立n个student，然后一个一个去改变就可以了
Student& operator[](const int x);//注意到这里需要确定你重载后的的函数的返回值，我选择返回了student，之后再重载Stundent的输出运算符
Student& operator[](const char x);
Student& operator[](const string x);
~ School(){
    delete[]st;
}
};


 