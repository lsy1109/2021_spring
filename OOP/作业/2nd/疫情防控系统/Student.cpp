#include"Student.h"//自己编的必须用""，不然编译不过
using namespace std;
istream& operator>> (istream& in, Student& dst)//in可以理解为你输入的内容，这个内容是istream类型的
{   //第三个点，由于你先读入了一个回车；因此第一个人的名字实际上有一个回车符；
    char a[100];
    in.getline(a, 99, '-');//OJ给的输入实际上是"12\nasdsad-asdasd\nsfafa"，因此你第一个人读入了\n;最后你把这个\n也当成了名字，但为啥第二个人没有发生这件事？因为你的getline会把终止符去掉
    string nam(a);
    string x;
     if(a[0]=='\n')
     {
         for(int i=1;i<nam.length();i++)
            {x += nam[i];}
             dst.name=x;
     }
     else
     {
         dst.name=nam;
     }
     //把x定义在if里面会报错，因为定义在里面就是局部变量，没法在外面用
    //调用一个内置的char*到string的构造函数。
    //注意到这一串的意思是：你开了一个新的string，这个string叫nam，nam等于把a转化为string后的那玩意儿；
    char c; //in >> c;//这里其实涉及到了输入的原理：c++里的输入是有一片缓冲区，然后你把一堆乌七八糟的玩意儿输到这个缓冲区里面
    //然后比如 string s; cin>>s;就是把这个缓冲区的所有东西，一个一个按照顺序读入到s里面；
    //而in.getline()这个函数部分，注意到我的写法是先有一个a[100]，然后开始一个一个地读入，读入的最大长度为99，读入的终点是"-"符号
    //注意到，getline函数是不含尾部的，你的'-'保留在缓冲区，且'-'打头的那些乌七八糟的玩意儿还可以再读入；那我们接着读入；
    //创立了一个新的char c；这个c把'-'读走了，从缓冲区里挪走了；接下来依然这么读；
    char b[100];//实际上还有别的读取方式，比如遇见一个'-'停留一次的那种，但是比较麻烦；
    //另外，由于只有名字的字符长度是不确定的，读完名字后，可以按照后面固定的长度剪字符串即可。
    in.getline(b, 99, '-');
    string hom(b);
    dst.home=hom;
    char d; //in>>d;
    char e[100];
    in.getline(e, 99, '-');
    dst.age=atoi(e);//我一开始用age=atoi(e);会报错，为啥？因为你的age是对象的；也就是非静态成员引用必须与特定对象相对；
    char f; //in>>f;
    char g[100];
    in.getline(g, 99, '-');
    string dat(g);
    dst.date=dat;
    char h; //in>>h;
    char i[100];
    in.getline(i,99);//最后这里直接读入就可以了
    string idd(i);
    dst.id=idd;
    //cout <<"\n\n" << dst.name << "-" << dst.home << "-" << dst.age << "-" << dst.date <<"-" << dst.id <<"\n\n";
    return in;//虽然这里只有一个输入，但是为了使他满足>>a>>b这种套娃输入，就return一个in
}

bool Student::operator > (const Student& y) const //先写返回类型，再写类
 {
     if(Student::date>y.date)
     {
         return 1;
     }//最晚回校的学号最大，意思是先最晚，再学号最大；
     if(Student::date==y.date&&Student::id>y.id)
     {
         return 1;
     }
     else//else不用打冒号
     return 0;
 }

 ostream& operator<< (ostream& out, const Student& src)
     {
         if(src.age==0)
         {
             out<<"Not Found"<<endl;
         }
         else
         {
             out<<src.name<<"-"<<src.date<<"-"<<src.age<<"-"<<src.id<<endl;
         }
        return out;
     }

// 为什么这里是out而不是cout，因为你在重载out，你希望你的out对于所有的输出流都适用，那么不能写cout。因为还有fout这些
//如果写了cout，没有问题，但是没法给fout这些用，因此写out习惯更好
//这里参数的意义cout << asdfsad << sadf; out就是你的cout，src就是你的asdfsad，然后调用了函数，返回了一个新的ostream&，从此开始套娃