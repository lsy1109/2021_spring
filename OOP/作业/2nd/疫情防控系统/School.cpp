#include"School.h"//最好用"school. h"。构造函数为啥报错了？
//因为没用school::
/*using namespace std;
school(int index)
{

}*/
int School::num=0;
//一开始写为static int num=0，报错；因为没有说明这是School的num，后来写为：static int School::num=0;也错，因为不能加static

void School::add_member(Student s)
{
    st[School::num]=s;
    School::num++;
}

Student& School::operator[](const int x)//这里采用记录下标的方式，避免了多重循环
//注意到id的查询和name查询都是惟一的，所以不用重载>符号
{   int j=n;
    string t = to_string(x);//这里完成了int转为string
    for(int i=0;i<School::n;i++)
    {
        if (st[i].id==t&&j==n)
        {
            j=i;
            break;
        }
    }
    return st[j];
}
Student& School::operator[](const char x)
{
    int j=n;
    string t;
    t += x;//这里完成了char转为string
    for(int i=0;i<School::n;i++)
    {
        if (st[i].home==t&&j==n)
        {
            j=i;
        }
        if(st[i].home==t&&j!=n)
        {
            if(st[i]>st[j])
            {
                j=i;
            }
        }
    }
    return st[j];
}

Student& School::operator[](const string x)//返回值类型打在类的前面
{
    
    int j=n;
    for(int i=0;i<School::n;i++)
    {
        if (st[i].name==x&&j==n)
        {
            j=i;
            break;
        }
    }
    return st[j];
}