# STL 和字符串处理

##  string字符串类

STL为我们提供了方便的string类型

**允许简洁的拼接操作**

```cpp
string fullname = firstname + " " + lastname;
```

**也能够使用惯用的输入输出方法**

```cpp
std::cout << fullname << std::endl;
```

**构造方式**

```cpp
string s0("Initial string"); //从c风格字符串构造
string s1;			 		 //默认空字符串
string s2(s0, 8, 3);		 //截取：“str”，index从8开始，长度为3
string s3(“Another character sequence”, 12);  //截取：“Another char”
string s4(10, 'x');		 					  //复制字符：xxxxxxxxxx
string s5(s0.begin(), s0.begin()+7);		  //复制截取: Initial
//转换为c风格字符串
str.c_str() 					//注意返回值为常量字符指针(const char*)，不能修改
```

**迭代器**

```cpp
//方式一
#include<string>
#include<iostream>//cin是在<iostream>里面，还是在std里面？string是在<string>里面还是在std里面？
int main(){
    std::string zcy="Darling I'll love you till we are senventy";
    for(auto it=zcy.begin();it!=zcy.end();it++)
    {
        std::cout<<*it<<std::endl;
    }
    return 0;
}

//方式二
   for(char c:zcy)
    {
        std::cout<<c<<std::endl;
    }
```

**常见函数**

```cpp
cout << str[1];//访问元素
str[1]='a';//修改元素
str.size()//查询长度
str.clear()//清空 
str.empty()//查询是否为空
str.push_back('a');
str.append(s2);//向尾部增加
查询长度也可以使用str.length()，与size()返回值相同
向尾部增加也可以使用 str += 'a' 或者 str += s2

拼接
string fullname = firstname + " " + lastname;
注意：拼接的时间复杂度为生成的字符串长度
for(int i = 0; i < n; i++)
allname = allname + name[i] + "\n"
//时间复杂度O(n^2*L)的时间，L表示每个子串的平均长度
拼接多个字符串最好使用 operator+= 或者 stringstream

比较
//直接按照字典序来比较
string a = "alice", b = "bob";
a == b //False
a < b  //True
```

**读取方式在期末复习那个md文件里**



**类型转换**

```cpp
//数值类型字符串化
to_string(1)			//"1"
to_string(3.14)		//"3.14"
to_string(3.1415926)		//"3.141593" 注意精度损失
to_string(1+2+3)		//"6"

关于从float到string的精度丢失，简单理解就是：float的精度是保证至少7位有效数字是准确的 
小数点后第七位发生了丢失
更进一步的讨论请在CDSN搜索：float的精度和取值范围，看第一篇文章就好，作者为AlbertS
//时间不足，现在就不用看了
    
//字符串转数值类型
int a = stoi("2001")		  //a=2001
std::string::size_type sz;   // size_t alias
int b = stoi("50 cats", &sz)  //b=50 sz=2 读入长度
int c = stoi("40c3", nullptr, 16) //c=0x40c3 十六进制
int d = stoi("0x7f", nullptr, 0)  //d=0x7f 自动检查进制
double e = stod("34.5")	  //e=34.5
```

$\Large\color{red}{我马上去研究第14行和第15行的意思。}$

**std::string 和 std::vector<char>的区别**

string可以length()或者size()来获取长度，但是vector只有size()函数。

string可以通过cin>>str;从标准输入输入字符串。

string可以通过str+="abc";向字符串尾部添加字符。

都可以使用 for(char c: str)遍历字符串中的所有字符。


```cpp
int b = stoi("50 cats", &sz)  //b=50 sz=2 读入长度
//并不是这么转换会报错，而是只能前两位转换，而且转换长度会被传入sz里面
```



## iostream输入输出流

```cpp
cout << str << endl;
cin >> str;
ostream& operator<<(ostream& out, const Test& src)
{
	out << src.id << endl;
	return out;
} 
//return的和传入的参数都是out
//ostream到底是什么？
//默认只对内置类型有输入输出的支持，用户定义的需要重载
```

基类：istream和ostream，而iostream是派生类。cin、cout是具体的对象。ifstream，ofstream，fstream都是面向文件的输入输出流。也可以通过字符串来定义交互方式，比如sstream。

**ostream即output stream是STL库中所有输出流的基类**

它重载了针对基础类型的输出流运算符（<<)，接受不同类型的数据，再调用系统函数进行输出。统一了输出接口，改善了C中输出方式混乱的状况，比如C中需要用户关心非常多的内容，手动设置输出类型，常常出错。

```c
printf("%d %f %s", 1, 2.3, "hello");
```

cout是STL中内建的一个ostream对象，它会将数据送到标准输出流（一般是屏幕）。

```cpp
class ostream
{
public:
	ostream& operator<<(char c)
	{
		printf("%c", c);
		return *this;
	}
	ostream& operator<<(const char* str)
	{
		printf("%s", str);
		return *this;
	}
}cout;
//尾巴上构建了内建对象cout
先执行cout << "hello" 调用第二个函数 返回c1（cout的引用）
再执行c1 << ' ' 调用第一个函数 返回c2 (cout的引用）
最后执行c2 << "world" 调用第二个函数
```

## 格式化输出

```cpp
#include <iomanip>
cout << fixed << 2018.0 << " " << 0.0001 << endl;
				//浮点数 -> 2018.000000 0.000100
cout << scientific << 2018.0 << " " << 0.0001 << endl;
				//科学计数法 -> 2.018000e+03 1.000000e-04
cout << defaultfloat;  //还原默认输出格式
cout << setprecision(2) << 3.1415926 << endl;
				//输出精度设置为2 -> 3.2
cout << oct << 12 << " " << hex << 12 << endl; 
				//八进制输出 -> 14  十六进制输出 -> c
cout << dec;	//还原十进制
cout << setw(3) << setfill('*') << 5 << endl;
				//设置对齐长度为3，对齐字符为* -> **5
```

自己实现

```cpp
class setprecision
{
private:
	int precision;
public:
	setprecision(int p) : precision(p) {}
	friend class ostream;
};
// setprecision(2) 是一个类的对象，初始化了一个对象，并且声明为ostream的友元
//函数类
class ostream
{
private:
	int precision; //记录流的状态
public:
	ostream& operator<<
			(const setprecision &m) {
		precision = m.precision;
		return *this;
	}//一旦识别到<<后面有setprecision &m，就把m的精度赋值给ostream的精度，实际上把
//setprecision的精度传给了ostream的precision，辅助类算子
} cout;
	cout << setprecision(2); 
//之后的操作呢？
   // setprecision(2) 是一个类的对象
```

借助辅助类，设置成员变量。这种类叫流操纵算子。

为什么重载流运算符要返回引用，而不是直接返回cout？

始终在用同一个输出流对象cout，没有构造新的ostream。

```cpp
观察ostream的复制构造函数
ostream(const ostream&) = delete;
ostream(ostream&& x);
禁止复制、只允许移动
仅使用cout一个全局对象
```

**为什么只能使用一个对象？**
减少复制开销
一个对象对应一个标准输出，符合OOP思想
多个对象之间无法同步输出状态

**是否能做得更好？**
全局对象往往引入初始化顺序问题
单件模式（Singleton Pattern），在之后的设计模式中会介绍

![image-20210517084317489](../../../../../../../AppData/Roaming/Typora/typora-user-images/image-20210517084317489.png)

A为啥错了？

## 文件输入输出流

以文件输入流作为例子：ifstream是istream的子类，功能是从文件中读入数据

打开文件

```cpp
ifstream ifs("input.txt");
ifstream ifs("binary.bin", ifstream::binary); //以二进制形式打开文件
ifstream ifs;//先创建一个sfstream类的对象
ifs.open("file")
//do something
ifs.close()
```

```cpp
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
int main() {
ifstream ifs("input.txt");
while(ifs) {			//判断文件是否到末尾 利用了重载的bool运算符
	ifs >> ws;  		//除去前导空格 ws也是流操纵算子
	int c = ifs.peek();		//检查下一个字符，但不读取
	if (c == EOF) break;
	if (isdigit(c))			//<cctype>库函数
	{
		int n;
		ifs >> n;
		cout << "Read a number: " << n << endl;
	} else {
		string str;
		ifs >> str;
		cout << "Read a word: " << str << endl;
	}
}
}
```

```cpp
getline(cin, str)
ifstream是istream的子类
故getline(ifs, str)仍然有效

其他操作
get()     读取一个字符
ignore(int n=1, int delim=EOF)	    丢弃n个字符，或者直至遇到delim分隔符
peek()    查看下一个字符
putback(char c) 返还一个字符
unget()   返还一个字符
……
```

```c
为什么C++使用流输入取代了scanf
scanf不友好，不同类型要使用不同的标识符
scanf("%d %hd %f %lf %s", &i, &s, &f, &d, name);
cin >> i >> s >> f >> d >> name;
安全性
scanf("%d %d", &a);  //可能写入非法内存
可拓展性
MyClass obj;
cin >> obj;
性能
scanf在运行期间需要对格式字符串进行解析
istream在编译期间已经解析完毕
```

## sstream

以输入输出流作为例子
stringstream是iostream的子类
iostream继承于istream和ostream
stringstream实现了输入输出流双方的接口

```cpp
#include <sstream>
using namespace std;

int main() {
stringstream ss;
ss << "10";//将10存入ss，为什么不是"10">>ss
//将"10"输出到你的ss里，等待输出
ss << "0 200";
int a, b;
ss >> a >> b;		//a=100 b=200
}
什么是输入，什么是输出？
什么是主体，主体是你的程序，客体是你的sstream，ifstream。输入输出是相对程序而言的，比如从外部输入给程序，
```

# 字符串处理与正则表达式

```cpp
场景：用户名注册
只能包含小写字母、数字、下划线，并且限制用户名长度在3~15个字符之间
	合法例子： john_123
	非法例子： John_123 / jo / @john
如何处理？
bool check(string name){
if (name.length() < 3 || name.length() > 15) return false;
for(char c: name){
	if(!((c >= 'a' && c <= 'z') || //小写字母
		(c >= '0' && c <= '9') ||  //数字
		c == '_'))  return false;
}
}
//太过复杂，不易修改
```

![image-20210517091650699](../../../../../../../AppData/Roaming/Typora/typora-user-images/image-20210517091650699.png)

