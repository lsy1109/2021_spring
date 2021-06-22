#pragma once
#include<iostream>
#include<string>
using namespace std;//用了string之后不打using namespace std会报错！

class Student
{
//为啥要用友元我待会再研究，貌似流运算符重载要用。
private:
public://为啥要把三个参数用不同的类型存储，为了方便比较
    /*Student(string na,string ho,int index,string day)//命名只需要一种创建方式，有三种查询方式;
    {
        name=na;
        home=ho;
        id=index;
        date=day;
    }
    Student(){};*/
    friend istream& operator>> (istream& in, Student& dst);//in可以理解为你输入的内容，这个内容是istream类型的
    friend ostream& operator<< (ostream& out, const Student& src);//输出一般加friend，是因为输出一般会访问private对象，所以说+friend是个好习惯，但是全改成public是个好方法
    bool operator > (const Student& y) const; //用stl函数时，尾端不写const，调用容器容易出错
    //注意到，我们调用a>b时，实际上调用的是a.operator > (b);所以实际上只传入了一个参数
    string name;
    string home;
    string id;
    int age;
    string date;//这里用string是出于：如果你用int的话，用atoi（注意是atoi函数，用来把string转化为int，不是auto类型界定）会把“0031”转化为31，这样在输出的时候需要补充0
    //但其实补充0并不麻烦，要不贝贝写的时候用int叭，这样避免咱俩查重；（好奇怪，dbq）
    //另外，就算在string里面 321也是大于123的，所以可以用string直接比大小
};

