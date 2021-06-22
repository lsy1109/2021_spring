# oop期末考试复习

------

## getchar()与getline()

**用于处理混杂了/n的输入。**

```cpp
2
15 Today_is_Thursday.
47 Hi/I_love_OOP.
2
15 I_am_sad.
13 Glad_to_see_you.
```

**getchar()：从缓冲区读入一个字符，包括空字符，并且会返回该字符。**

```cpp
//譬如对于第二行的读取，我们首先使用
 int initial;
 std::cin>>initial;
//读取走了第一个15，接下来我们想要读取Today_is_Thursday.\n
 getchar();//读走15与Today_is_Thursday.\n之间的那个' '
char m;
	while ((m=getchar())>' ')//逐字符读取
{   
	if (m != '/')
	{zcy += m;}
    else
	{a.x.push_back(zcy);
	zcy ="";}
}
//这里先getchar()，将空格读走，然后再挨个getchar()，并把这些char加入到std::string zcy里面
//注意此处while的结尾判定是>' '而不是!='\n'。前者比后者更为安全，因为后者必须要结尾读到'\n'才会停止，如果我结尾没有endl，那这个程序就会RE
//另一方面，'\n'的ASCII码是10，' '是32，确实'\n'<' '。
```



下面以输入文本为例子，解析getline()

```cpp
Mike William
Andy William
#
```

**getline()的第一种方式，读取一行直到换行符为止，没有读入'\n'。**

```cpp
//experiment 1
#include<string>
#include<iostream>
int main(){
    std::string zcy;
    getline(std::cin,zcy);
    std::cout<<zcy<<std::endl;
    return 0;
}
output:
Mike William
```

**getline()的第二种方式，读取到指定的字符为止，可以读入'\n'。**
```cpp
//experiment 2
#include<string>
#include<iostream>
int main(){
    std::string zcy;
    getline(std::cin,zcy,'#');
    std::cout<<zcy<<std::endl;
    return 0;
}
output：
 L3  p9
 L4  p10
 L5  p9
 L6 p10 
 L8 p10 
Mike William
Andy William
//小心第二题的提交方式，分别提交两个h，不是压缩包！！！

```
注意到这里对string的输出很有意思，当cout输出到'\n'后，并没有停止输出，而是输出了endl，接着继续输出，直到结束。上文实际上string读入的内容是"Mike William\nAndy William\n"，如果'#'与最后一个William之间没有endl，那么不会读入"Andy William\n"的这个‘\n’。



